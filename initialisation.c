
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

#include "initialisation.h"

/*
    précondition : Deux chaines de caracteres qui correspondent à une carte action
    postcondition :  Retourne un maillon de liste chainé contenant une carte action
*/
struct MaillonAction *initListeChaine(char a[15],char b[15])
{
    struct MaillonAction *element = malloc(sizeof(struct MaillonAction));

    if (element == NULL)
    {
        exit(1);
    }

    strcpy(element->valeur.actionSoir,a);
    strcpy(element->valeur.actionMatin,b);
    element->suivant = NULL;

    return element;
}

/*
    précondition : Deux chaines de caracteres qui correspondent à une carte tresor
    postcondition : Retourne un maillon de liste chainé contenant une carte tresor
*/
struct MaillonTresor *initListeChaineTresor(char a[15],int val)
{
    struct MaillonTresor *element = malloc(sizeof(struct MaillonTresor));

    if (element == NULL)
    {
        exit(1);
    }

    strcpy(element->valeur.pouvoir,a);
    element->valeur.nb=val;
    element->suivant = NULL;

    return element;
}

/*
    précondition : une liste chaine de carte action et une carte action
    postcondition : Retourne la liste chaine de carte action avec la nouvelle carte action ajoutée en tete
*/
struct MaillonAction* ajoutDebutListeChaine(struct MaillonAction *tete,struct MaillonAction *nouveau)
{
  nouveau->suivant=tete;
  tete=nouveau;
  return tete;

}

/*
    précondition : une liste chaine de carte tresor et une carte tresor
    postcondition : Retourne la liste chaine de carte action avec la nouvelle carte tresor ajoutée en tete
*/
struct MaillonTresor* ajoutDebutListeChaineTresor(struct MaillonTresor *tete,struct MaillonTresor *nouveau)
{
  nouveau->suivant=tete;
  tete=nouveau;
  return tete;

}

/*
    précondition : Auncun parametre
    postcondition : Initialise la pioche de carte Tresor
    Detail : On creee une carte tresor avec les parametrees du jeu et on l'ajoute dans la liste chainee de carte tresors
*/

struct MaillonTresor* initPiocheTresor()
{

     struct MaillonTresor *tete=NULL;
    struct MaillonTresor *carte;

    carte=initListeChaineTresor("carte",3);
    tete=ajoutDebutListeChaineTresor(tete,carte);

    carte=initListeChaineTresor("carte",3);
    tete=ajoutDebutListeChaineTresor(tete,carte);

    carte=initListeChaineTresor("carte",5);
    tete=ajoutDebutListeChaineTresor(tete,carte);

    carte=initListeChaineTresor("carte",7);
    tete=ajoutDebutListeChaineTresor(tete,carte);

    carte=initListeChaineTresor("carte",7);
    tete=ajoutDebutListeChaineTresor(tete,carte);


    carte=initListeChaineTresor("carte",-2);
    tete=ajoutDebutListeChaineTresor(tete,carte);

    carte=initListeChaineTresor("carte",-3);
    tete=ajoutDebutListeChaineTresor(tete,carte);

    carte=initListeChaineTresor("carte",-4);
    tete=ajoutDebutListeChaineTresor(tete,carte);


    carte=initListeChaineTresor("morgan",0);
    tete=ajoutDebutListeChaineTresor(tete,carte);


    carte=initListeChaineTresor("saran",0);
    tete=ajoutDebutListeChaineTresor(tete,carte);


    carte=initListeChaineTresor("beth",0);
    tete=ajoutDebutListeChaineTresor(tete,carte);


    carte=initListeChaineTresor("cale",0);
    tete=ajoutDebutListeChaineTresor(tete,carte);


    return tete;
}



/*
    précondition : Auncun parametre
    postcondition : Initialise le plateau de jeu
*/

struct Case* initPlateau()
{

   struct Case* plateau = malloc(TAILLE_PLATEAU*sizeof(struct Case));
   strcpy(plateau[0].type,"pr");
   plateau[0].prix=0;
   plateau[0].num=15;
   plateau[0].tr=0;

   strcpy(plateau[1].type,"hm"); //haute mer
   plateau[1].prix= 2 ;
   plateau[1].num= -5 ;
   plateau[1].tr=0;

   strcpy(plateau[2].type,"hm");
   plateau[2].prix= 3 ;
   plateau[2].num= -5 ;
   plateau[2].tr=0;

   strcpy(plateau[3].type,"hm");
   plateau[3].prix= 2 ;
   plateau[3].num=  -5 ;
   plateau[3].tr=0;

   strcpy(plateau[4].type,"tr"); //trésor
   plateau[4].prix=0  ;
   plateau[4].num= -5 ;
   plateau[4].tr=1;

  strcpy(plateau[5].type,"port");
   plateau[5].prix= 3 ;
   plateau[5].num= -5 ;
   plateau[5].tr=0;

   strcpy(plateau[6].type,"port");
   plateau[6].prix=5  ;
   plateau[6].num= -5  ;
    plateau[6].tr=0;

   strcpy(plateau[7].type,"hm"); //chemin le plus cours d'abords lors d'un carrefour
   plateau[7].prix= 3 ;
   plateau[7].num=  -5 ;
   plateau[7].tr=0;


   strcpy(plateau[8].type,"hm");
   plateau[8].prix= 4 ;
   plateau[8].num= -5 ;
   plateau[8].tr=0;

   strcpy(plateau[9].type,"hm");
   plateau[9].prix=2;
   plateau[9].num=-5;
   plateau[9].tr=0;

   strcpy(plateau[10].type,"hm");
   plateau[10].prix= 3 ;
   plateau[10].num=  -5 ;
   plateau[10].tr=0;

   strcpy(plateau[11].type,"tr");
   plateau[11].prix= 0  ;
   plateau[11].num= -5  ;
   plateau[11].tr=1;

   strcpy(plateau[12].type,"hm");
   plateau[12].prix= 3 ;
   plateau[12].num= -5 ;
   plateau[12].tr=0;

   strcpy(plateau[13].type,"tr");
   plateau[13].prix= 0 ;
   plateau[13].num= -5 ;
   plateau[13].tr=1;

   strcpy(plateau[14].type,"hm");
   plateau[14].prix=2  ;
   plateau[14].num= -5  ;
   plateau[14].tr=0;

   strcpy(plateau[15].type,"hm");
   plateau[15].prix= 3 ;
   plateau[15].num= -5  ;
   plateau[15].tr=0;

   strcpy(plateau[16].type,"port");
   plateau[16].prix= 5 ;
   plateau[16].num= -5 ;
   plateau[16].tr=0;

   strcpy(plateau[17].type,"hm");
   plateau[17].prix= 2 ;
   plateau[17].num= -5  ;
   plateau[17].tr=0;

   strcpy(plateau[18].type,"port");
   plateau[18].prix=3;
   plateau[18].num=-5;
   plateau[18].tr=0;

   strcpy(plateau[19].type,"tr");
   plateau[19].prix=0  ;
   plateau[19].num= -5 ;
   plateau[19].tr=1;

   strcpy(plateau[20].type,"hm");
   plateau[20].prix= 4 ;
   plateau[20].num= -5  ;
   plateau[20].tr=0;

   strcpy(plateau[21].type,"hm");
   plateau[21].prix= 4 ;
   plateau[21].num= -5;
   plateau[21].tr=0;

   strcpy(plateau[22].type,"hm");
   plateau[22].prix= 3 ;
   plateau[22].num= -5 ;
   plateau[22].tr=0;

   strcpy(plateau[23].type,"port");
   plateau[23].prix= 3 ;
   plateau[23].num= -5 ;
   plateau[23].tr=0;

   strcpy(plateau[24].type,"tr");
   plateau[24].prix= 0 ;
   plateau[24].num= -5 ;
   plateau[24].tr=1;

   strcpy(plateau[25].type,"hm");
   plateau[25].prix= 2 ;
   plateau[25].num= -5 ;
   plateau[25].tr=0;

   strcpy(plateau[26].type,"hm");
   plateau[26].prix= 3 ;
   plateau[26].num= -5  ;
   plateau[26].tr=0;

   strcpy(plateau[27].type,"tr");
   plateau[27].prix=0  ;
   plateau[27].num= -5 ;
   plateau[27].tr=1;

   strcpy(plateau[28].type,"port");
   plateau[28].prix=5  ;
   plateau[28].num= -5  ;
   plateau[28].tr=0;

   strcpy(plateau[29].type,"hm");
   plateau[29].prix=1  ;
   plateau[29].num= -5 ;
   plateau[29].tr=0;

   strcpy(plateau[30].type,"port");
   plateau[30].prix= 3 ;
   plateau[30].num= -5 ;
   plateau[30].tr=0;

   strcpy(plateau[31].type,"port");
   plateau[31].prix= 3 ;
   plateau[31].num= -5  ;
   plateau[31].tr=0;

   strcpy(plateau[32].type,"hm");
   plateau[32].prix= 3 ;
   plateau[32].num= -5  ;
   plateau[32].tr=0;

   strcpy(plateau[33].type,"hm");
   plateau[33].prix=4  ;
   plateau[33].num= -5;
   plateau[33].tr=0;

   strcpy(plateau[34].type,"hm");
   plateau[34].prix=4;
   plateau[34].num=-5;
   plateau[34].tr=0;

   strcpy(plateau[35].type,"tr");
   plateau[35].prix= 0 ;
   plateau[35].num= -5  ;
   plateau[35].tr=1;

   strcpy(plateau[36].type,"port");
   plateau[36].prix=3  ;
   plateau[36].num= -5  ;
   plateau[36].tr=0;

   strcpy(plateau[37].type,"hm");
   plateau[37].prix=2  ;
   plateau[37].num= -5 ;
   plateau[37].tr=0;

   strcpy(plateau[38].type,"hm");
   plateau[38].prix=1  ;
   plateau[38].num= -5 ;
   plateau[38].tr=0;

   strcpy(plateau[39].type,"tr");
   plateau[39].prix= 0 ;
   plateau[39].num= -5  ;
   plateau[39].tr=1;

   strcpy(plateau[40].type,"hm");
   plateau[40].prix= 1;
   plateau[40].num=  -5 ;
   plateau[40].tr=0;

   strcpy(plateau[41].type,"port");
   plateau[41].prix=5  ;
   plateau[41].num=2  ;
   plateau[41].tr=0;

   strcpy(plateau[42].type,"hm");
   plateau[42].prix=2  ;
   plateau[42].num=3  ;
   plateau[42].tr=0;

   strcpy(plateau[43].type,"hm");
   plateau[43].prix=3;
   plateau[43].num=4;
   plateau[43].tr=0;

   strcpy(plateau[44].type,"tr");
   plateau[44].prix=0  ;
   plateau[44].num=5 ;
   plateau[44].tr=1;

   strcpy(plateau[45].type,"port");
   plateau[45].prix= 7 ;
   plateau[45].num=6   ;
   plateau[45].tr=0;

   strcpy(plateau[46].type,"hm");
   plateau[46].prix= 2 ;
   plateau[46].num=  7;
   plateau[46].tr=0;

   strcpy(plateau[47].type,"hm");
   plateau[47].prix= 3 ;
   plateau[47].num= 8 ;
   plateau[47].tr=0;

   strcpy(plateau[48].type,"hm");
   plateau[48].prix= 3 ;
   plateau[48].num= 9  ;
   plateau[48].tr=0;

   strcpy(plateau[49].type,"hm");
   plateau[49].prix= 3 ;
   plateau[49].num=  10 ;
   plateau[49].tr=0;

   return plateau;


}

/*
    précondition : Auncun parametre
    postcondition : Initialise la pioche de carte Actions
    Detail : On creee une carte Action avec les parametrees du jeu et on l'ajoute dans la liste chainee de carte actions
*/
struct MaillonAction *initPioche()
{
    struct MaillonAction *tete=NULL;
    struct MaillonAction *carte;
    carte=initListeChaine("av","av");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("no","po");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("no","av");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("po","no");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("av","po");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("av","re");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("or","or");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("re","av");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("or","av");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("av","no");
    tete=ajoutDebutListeChaine(tete,carte);

    carte=initListeChaine("po","or");
    tete=ajoutDebutListeChaine(tete,carte);

    return tete;

}

/*
    précondition : Auncun parametre
    postcondition : Initialise la cale du joueur
*/
struct Carre* initCale()
{
  struct Carre* cale = malloc(TAILLE_CALE*sizeof(struct Carre));

    cale[0].nbre=3;
    strcpy(cale[0].objet,"or");
    cale[1].nbre=3;
    strcpy(cale[1].objet,"no");
    for(int i=2;i<TAILLE_CALE-1;i++){
      cale[i].nbre=0;
      strcpy(cale[i].objet,"vide");
    }
    strcpy(cale[TAILLE_CALE-1].objet,"null");
    cale[TAILLE_CALE-1].nbre=0;

  return cale;
}

/*
    précondition : Une pioche et la position de l'element a rechercher
    postcondition : Retourne la valeur de la carte action a cette position
*/

struct CarteAction elementListeChaine(struct MaillonAction *tete,int pos){
  int compteur=0;

   while(compteur!=pos){
     compteur++;
     tete=tete->suivant;

   }
 return tete->valeur;
}

/*
    précondition : Une pioche et la position de l'element a rechercher
    postcondition : Retourne la valeur de la carte tresor a cette position
*/
struct CarteTresor elementListeChaineTresor(struct MaillonTresor *tete,int pos){
  int compteur=0;

   while(compteur!=pos){
     compteur++;
     tete=tete->suivant;

   }
 return tete->valeur;
}

/*
    précondition : Une pioche du joueur et la position de l'element a supprimer
    postcondition : Retourne la nouvelle pioche du joueur avec l'element supprimé
*/
struct MaillonAction* suppElementListeChaine(struct MaillonAction* tete, struct CarteAction valeur)
{
struct MaillonAction  *tmp;
struct MaillonAction  *previous;

if (tete == NULL) // si la liste est NULL on s'arrete tout de suite
  return (tete);
previous = tete;
if ((strcmp(previous->valeur.actionSoir,valeur.actionSoir)==0) && (strcmp(previous->valeur.actionMatin,valeur.actionMatin)==0)) // Verifie la tete de liste, cas particulier
{
  tete = previous->suivant;
  free(previous);
  return (tete);
}

tmp = previous->suivant; // le cas n est gere on se place donc sur le cas n+1
while(tmp != NULL) // On Mouline est on supprime si on trouve l'element
{
  if ((strcmp(tmp->valeur.actionSoir,valeur.actionSoir)==0) && (strcmp(tmp->valeur.actionMatin,valeur.actionMatin)==0))
  {
    previous->suivant = tmp->suivant;
    free(tmp);
    return (tete);
  }
  previous = tmp; // pour ce souvenir dans la prochaine iteration du precedent
  tmp = tmp->suivant;
}
return tete;
}

/*
    précondition : Une pioche de cartes tresors et la position de l'element a supprimer
    postcondition : Retourne la nouvelle pioche de carte tresors  avec l'element supprimé
*/
struct MaillonTresor* suppElementListeChaineTresor(struct MaillonTresor* tete, struct CarteTresor valeur)
{
struct MaillonTresor  *tmp;
struct MaillonTresor  *previous;

if (tete == NULL) // si la liste est NULL on s'arrete tout de suite
  return (tete);
previous = tete;
if ((strcmp(previous->valeur.pouvoir,valeur.pouvoir)==0) && (valeur.nb==previous->valeur.nb)) // Verifie la tete de liste, cas particulier
{
  tete = previous->suivant;
  free(previous);
  return (tete);
}

tmp = previous->suivant; // le cas n est gere on se place donc sur le cas n+1
while(tmp != NULL) // On Mouline est on supprime si on trouve l'element
{
  if ((strcmp(tmp->valeur.pouvoir,valeur.pouvoir)==0) && (valeur.nb==tmp->valeur.nb))
  {
    previous->suivant = tmp->suivant;
    free(tmp);
    return (tete);
  }
  previous = tmp; // pour ce souvenir dans la prochaine iteration du precedent
  tmp = tmp->suivant;
}
return tete;
}

/*
    précondition : Une pioche
    postcondition : Retourne la taille de la pioche du joueur
*/
int tailleListeChaine(struct MaillonAction *tete)
{
  int taille=0;
  if (tete==NULL){
   return taille;
  }

else{
     while(tete!=NULL){
     taille++;
     tete=tete->suivant;

      }
 }
 return taille;
}

/*
    précondition : Auncun parametre
    postcondition : Initialise la main de carte tresor du joueur
*/
struct CarteTresor* initMainTresor()
{
    struct CarteTresor* mainTresor=malloc(sizeof(struct CarteTresor)*TAILLE_MAIN_TRESOR);
    for(int i=0;i<TAILLE_MAIN_TRESOR;i++)
    {
       mainTresor[i].nb=0;
       strcpy(mainTresor[i].pouvoir,"null");
    }
    return mainTresor;
}

/*
    précondition : Une pioche
    postcondition : Retourne la taille de la pioche de cartes tresors
*/
int tailleListeChaineTresor(struct MaillonTresor *tete)
{
  int taille=0;
  if (tete==NULL){
   return taille;
  }

else{
     while(tete!=NULL){
     taille++;
     tete=tete->suivant;

      }
 }
 return taille;
}

/*
    précondition : La pioche du joueur, la main du joueur et la position la main du joueur a remplir
    postcondition : Retourne la main du joueur avec une nouvelle carte a cette position
*/
struct CarteAction* remplitMain(struct CarteAction* mainn,struct MaillonAction *pioche,int j)
{

    int taille;
    struct CarteAction element;

    // on retourne la taille de la pioche (nombre de carte)

    taille=tailleListeChaine(pioche);
      // on choisit une position random
      int pos = rand() %taille;
      // on prend la carte de cette position dans la pioche
      element=elementListeChaine(pioche,pos);
      mainn[j]=element;
      // on diminue la taille de la pioche
    return mainn;
}


/*
    précondition : La pioche du joueur
    postcondition : Retourne le joueur ayant une nouvelle main de 3 cartes et une pioche actualisé
    detail : On pioche 3 cartes pour le joueur et on les supprime dans la pioche du joueur
*/
struct Joueur initMainUpdatePioche(struct MaillonAction *pioche)
{
    // a chaque tour de boucle
    struct CarteAction* mainn=malloc(sizeof(struct CarteAction)*TAILLE_MAIN);
    struct CarteAction element;
    struct Joueur joueurActuel;

    for (int j=0;j<TAILLE_MAIN-1;j++)
    {
        element=mainn[j];
       mainn=remplitMain(mainn,pioche,j);
       pioche=suppElementListeChaine(pioche,element);
    }
    strcpy(mainn[TAILLE_MAIN-1].actionMatin,"null");
    strcpy(mainn[TAILLE_MAIN-1].actionSoir,"null");
    joueurActuel.main=mainn;
    joueurActuel.pioche=pioche;
    return joueurActuel;
}
/*
    précondition : Un pseudo, une liste de joueur et le nombre de joueur de la partie
    postcondition : Verifie si le pseudo d'un joueur existe deja dans la liste de joueurs
*/

int pseudoDansListeJoueur(char pseudo[15],struct Joueur* liste,int taille)
{
  int res=0;

  for(int i=0;i<taille;i++){
    if (strcmp(pseudo,liste[i].pseudo)==0)
        {

        res=1;
        }

  }

  return res;

}
/*
    précondition : Une couleur, une liste de joueur et le nombre de joueur de la partie
    postcondition : Verifie si la couleur d'un joueur existe deja dans la liste de joueurs
*/

int couleurDansListeJoueur(int couleur,struct Joueur* liste,int taille)
{
  int res=0;

  for(int i=0;i<taille;i++){
    if (couleur==liste[i].couleur){

        res=1;
    }

  }
  return res;

}
/*
    précondition : Un message de lecture et les bornes inferieurs et superieures de l'entier a lire
    postcondition : Retourne un entier correct compris entre les bornes passés en parametre
    Detail : Demande le même message passé en parametre tant que les conditions ne sont pas remplies
*/
int lireEnBoucleInt(char messageLecture[100],int borneInf,int borneSup)
{
    int retour;
    char char_nul;
    int taille;

  // tant que le numero de la colonne n'est pas valide on demande de saisir un entier
  do
    {
    printf("%s",messageLecture);
    retour=scanf("%d",&taille);

    // tant que la valeur n'est pas un entier on demande de saisir un entier et on vide le buffer
    if (retour==0)
        {

        while(retour==0)
            {
          retour=scanf("%c",&char_nul);
          while(char_nul!='\n'){
              retour=scanf("%c",&char_nul);

           }
      printf("Tu dois saisir un entier !\n");
      retour=scanf("%d",&taille);

      }

    }
 }while((taille<borneInf) || (taille>borneSup));

 return taille;

}


/*
    précondition : le nombre de joueurs de la partie
    postcondition : initialise une liste de joueurs contenant : une main, une main de Tresors, une cale, une pioche, une position sur le plateau et une couleur
*/

struct Joueur* initListeJoueur(int taille)
 {
    struct Joueur * listeJoueur=malloc(taille*sizeof(struct Joueur));

    // si liste vide (IMPOSSIBLE) on sort du programme
    if (listeJoueur==NULL){
      exit(0);
    }

    // parcourt liste joueur
    for(int i=0;i<taille;i++)
    {

      char pseudo[15];
      int couleur;
      struct Carre* cale =malloc(TAILLE_CALE*sizeof(struct Carre));
      struct CarteAction* mainn =malloc(TAILLE_MAIN*sizeof(struct CarteAction));
      struct CarteTresor* mainTresor =malloc(TAILLE_MAIN_TRESOR*sizeof(struct CarteTresor));
      struct MaillonAction *pioche=NULL;
      listeJoueur[i].pos=1;
        // on demande un pseudo au joueur
        printf("\t{ Joueur numero %d }\n\n",i+1);
        printf("Choisis ton pseudo : \n");
        scanf("%s",pseudo);
        // si le pseudo existe dans la liste on le redemande a l'infini
        if (pseudoDansListeJoueur(pseudo,listeJoueur,taille)==1){
          do
            {
            printf("Le pseudo est déja pris !\n");
            printf("Choisis ton pseudo :\n");
            scanf("%s",pseudo);
            }
            while(pseudoDansListeJoueur(pseudo,listeJoueur,taille)==1);

        }
        // on place le pseudo valide dans la liste de joueur
        strcpy(listeJoueur[i].pseudo,pseudo);

        // lis la couleur jusqu'a ce qu'elle soit correcte
        couleur=lireEnBoucleInt("Choisis une couleur :\n-1 Bleu clair\n-2 Rouge\n-3 Vert clair\n-4 Jaune\n-5 Rose\n-6 Vert fonce\n\n",1,6);
        // si la couleur est deja prise
        if(couleurDansListeJoueur(couleur,listeJoueur,taille)==1){
          //redemande a l'infini la couleur
          do{
          printf("Cette couleur est déja prise !\n");
          couleur=lireEnBoucleInt("Choisis une couleur  :\n-1 Bleu clair\n-2 Rouge\n-3 Vert clair\n-4 Jaune\n-5 Rose\n-6 Vert fonce\n\n",1,6);
          }while(couleurDansListeJoueur(couleur,listeJoueur,taille)==1);


        }
        // rentre la couleur valide dans la liste de joueur
        listeJoueur[i].couleur=couleur;

        cale = initCale();
        listeJoueur[i].cale=cale;

        pioche=initPioche();
        mainTresor=initMainTresor();
        listeJoueur[i].pioche=pioche;

        // on veut retourner la nouvelle pioche et la main initialié du joueur dans un joueur temporaire
       struct Joueur joueurActuel=initMainUpdatePioche(pioche);

       // on isole la main initialisé de 3 cartes contenu dans le joueur actuel
        mainn=joueurActuel.main;
        // on isole la pioche vidé de 3 cartes contenu dans le joueur actuel
        pioche=joueurActuel.pioche;
        // on rentre la nouvelle main et la nouvelle pioche  dans la liste de joueur
        listeJoueur[i].pioche=pioche;
        listeJoueur[i].main=mainn;

        listeJoueur[i].mainTresor=mainTresor;




   }
   return listeJoueur;
}

/*
    précondition : La liste de joueurs intialisée
    postcondition : La nouvelle liste de joueurs avec un capitaine choisi aleatoirement place en premiere position
*/


struct Joueur* newInitListeJoueur(struct Joueur* listeJoueur,int taille)
{
    struct Joueur* tab=malloc(sizeof(struct Joueur)*taille);
    tab=listeJoueur;
    srand(time(NULL));
    // on choisi un random de la lisre qu'on met en premiere case tu tableau
    int numCapitaine =(int) rand()%taille;
    // on sauvegarde la premier case du tableau
    struct Joueur temp=tab[0];
    tab[0]=tab[numCapitaine];
    tab[numCapitaine]=temp;


    return tab;

}

/*
    précondition : La pioche de cartes tresors du jeu
    postcondition : Supprime 3 elements de la pioche de cartes Tresors pour qu'il n'y en ai que 9 comme l'indique les regles du jeu
*/

struct MaillonTresor *tirageDebutPartieCarteTresor(struct MaillonTresor *piocheTresor)
{
    for(int i=0;i<3;i++){
             int taille=tailleListeChaineTresor(piocheTresor);
        int aleatoire=rand()%taille;

        struct CarteTresor element=elementListeChaineTresor(piocheTresor,aleatoire);
        piocheTresor=suppElementListeChaineTresor(piocheTresor,element);

    }



    return piocheTresor;
}
/*
    précondition : Un jeu vide
    postcondition : Initialise Le jeu contenant le plateau, la liste de joueur et la pioche de cartes Tresors et le de
*/

struct Jeu initJeu(int taille)
{
    struct Jeu jeu;
    struct Joueur* listeJoueur=initListeJoueur(taille);
    listeJoueur=newInitListeJoueur(listeJoueur,taille);

    struct MaillonTresor *piocheTresor=initPiocheTresor();
    piocheTresor=tirageDebutPartieCarteTresor(piocheTresor);


    // on place le capitaine en premiere position de la liste et on return la nouvelle liste

    struct Case* plateau=initPlateau();

    jeu.plateau=plateau;
    jeu.listeJoueur=listeJoueur;
    jeu.piocheTresor=piocheTresor;

    return jeu;
}







