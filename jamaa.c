
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include "initialisation.h"
#include "affichage.h"



/*
    précondition : une chaine de caracteres
    postcondition : Modifie la valeur de deux chaines de caracteres
*/

char* typeDeCase(char mot[15])
{
    char *str = malloc(3 * sizeof(char));
    if(str == NULL)
        return NULL;

    if(strcmp(mot,"hm")==0)
    {
        str[0] = 'n';
        str[1] = 'o';
        str[2] = '\0';

    }
    else if (strcmp(mot,"port")==0)
    {
        str[0] = 'o';
        str[1] = 'r';
        str[2] = '\0';

    }
    else
    {
        str=NULL;
    }

    return str;
}


/*
    précondition : un tableau dynamique de cartes tresors et une chaine de caracteres
    postcondition : Booleen qui retourne si le joueur possede une carte tresor dans sa main ou non
*/
int estTresor(struct CarteTresor* mainTresor,char mot[25])
{
    int verif=0;
    for(int i=0; i<TAILLE_MAIN_TRESOR; i++)
    {
        if(strcmp(mainTresor[i].pouvoir,mot)==0)
        {
            verif=1;
        }
    }
    return verif;
}


/*
    précondition : aucun parametre
    postcondition : retourne une valeur aleatoire de dé
*/
int lanceDejeu()
{
    int aleatoire;
    aleatoire = rand()%BORNE;//nombre aleatoire compris entre 0 et BORNE-1
    int alea=aleatoire+1;
    //printf("essai nombre aleatoire : %d\n",alea);
    return alea;
}
/*
    précondition : aucun parametre
    postcondition : retourne une structure de dé avec une valeur pour le dé du matin et une valeur pour le dé du soir
*/
struct DeJeu updateDeJeu()
{
    struct DeJeu de;
    int de1=lanceDejeu();
    int de2=lanceDejeu();
    printf("de 1 : tu as fait : ");
    Color(13,0);
    printf("%d\n",de1);
    Color(15,0);
    printf("de 2 : tu as fait : ");
    Color(13,0);
    printf("%d\n",de2);
    Color(15,0);
    int choix=lireEnBoucleInt("\nTappe 1 pour que le de1 soit le de du matin\n2 sinon\n",1,2);

    if (choix==1)
    {
        de.deMatin=de1;
        de.deSoir=de2;
    }
    else
    {
        de.deMatin=de2;
        de.deSoir=de1;
    }
    return de;
}

/*
    précondition : un tableau dynamique de cartes tresors et une valeur du type (0 ou 1)
    postcondition : retourne une valeur aleatoire de dé de combat
*/
int decombat(struct CarteTresor* mainTresor,int type)
{


    int aleatoire;
    aleatoire = rand()%BORNE;//nombre aleatoire compris entre 0 et BORNE-1
    int alea=aleatoire+1;
    //printf("essai nombre aleatoire : %d\n",alea);
    alea=alea*2;
    if(alea==12)
    {
        if (type==0)
        {
            printf("Tu as fais etoile\n");
        }
        else
        {
            printf("L'adversaire as fais etoile\n");
        }

    }
    else
    {
        if (type==0)
        {
            printf("Tu as fais %d\n",alea);
        }
        else
        {
            printf("L'adversaire a fait %d\n",alea);
        }


        if (estTresor(mainTresor,"beth"))
        {
            alea+=2;
            if (type==0)
            {
                printf("Tu as la carte ");
            }
            else
            {
                printf("L'adversaire as la carte ");
            }

            Color(13,0);
            printf("Lady Beth");
            Color(15,0);
            if(type==0)
            {
                printf(". Ton de augmente donc de 2\n");
                printf("Ton de est donc : %d\n",alea);
            }
            else
            {
                printf(". Le de de l'adversaire augmente donc de 2\n");
                printf("Le de de l'adversaire est donc : %d\n",alea);
            }

        }

    }
    return alea;
}

/*
    précondition : une valeur choix et un tableau de cartes actions
    postcondition : retourne une carte choisie par le joueur
*/
struct CarteAction choisirCarte(int choix,struct CarteAction* main)
{
    int x=choix-1;
    struct CarteAction carteChoisi = main[x];
    return carteChoisi;
};

// modifie la position du joueur
int updatePos(int pos,int valDe,char action[15])
{
    if (strcmp(action,"re")==0)
    {
        printf("Tu recules de %d\n",valDe);
        if (pos==1)
        {
            pos=1;
        }
        else
        {
            pos=pos-valDe;

        }
    }
    else if (strcmp(action,"av")==0)
    {
        pos=pos+valDe;
        printf("Tu avances de %d\n",valDe);


    }
    return pos;
}

int posCaseVide(struct Carre* tab)
{
    int resultat=-1;
    int estVide=0;

    for(int i=0; i<TAILLE_CALE; i++)
    {
        if((strcmp(tab[i].objet,"vide")==0)  && (estVide==0))
        {
            resultat=i;
            estVide=1;
        }
    }
    return resultat;
}

int posCaseVideTresor(struct CarteTresor* tab)
{
    int resultat=-1;
    int estVide=0;

    for(int i=0; i<TAILLE_MAIN_TRESOR; i++)
    {
        if((strcmp(tab[i].pouvoir,"null")==0)  && (estVide==0))
        {
            resultat=i;
            estVide=1;
        }
    }
    return resultat;
}

int calePleine(struct Carre* cale,char action[15])
{
    int res=1;

    for(int i=0; i<TAILLE_CALE; i++)
    {
        // si ce n'est pas les memes
        if(strcmp(cale[i].objet,action)!=0)
        {
            res=0;
        }

    }

    return res;
}


struct Carre* chargeCale(struct Carre* cale,char action[15],int valDe,struct CarteTresor* mainTresor)
{
    int taille=0;
    int posCaseDispo=posCaseVide(cale);

    if (calePleine(cale,action)==1)
    {
        printf("Ta cale contient uniquement des ressources identiques. ");
        printf("Il ne se passe donc rien\n");
    }
    else
    {
        printf("Tu recois %d ",valDe);
        motComplet(action);
        printf("\n");
        struct Carre carre;
        carre.nbre=valDe;
        strcpy(carre.objet,action);

        if(posCaseDispo>=0)
        {
            cale[posCaseDispo]=carre;
        }
        else
        {
            if(estTresor(mainTresor,"cale"))
            {
                taille=6;
            }
            else
            {
                taille=5;
            }

            int choix=lireEnBoucleInt("Ta cale est pleine, tu dois choisir le nuemro de la case de votre cale a jeter a la mer !\n",1,taille);
            if (strcmp(cale[choix-1].objet,action)==0)
            {
                while (strcmp(cale[choix-1].objet,action)==0)
                {
                    printf("Tu ne peux pas echanger deux resssources identiques\n");
                    choix=lireEnBoucleInt("Ta cale est pleine, tu dois choisir le numero de la case de votre cale a jeter a la mer !\n",1,taille);
                }

            }
            cale[choix-1]=carre;
            printf("Tu as jete la case numero %d a la mer\n",choix);

        }
    }

    return cale;
}



// update la cale et/ou la pos du joueur
struct Joueur utiliserCarteAction(struct Joueur joueur,struct CarteAction carteChoisi, struct DeJeu de,struct CarteTresor* mainTresor)
{
    struct Joueur newJoueur = joueur;
    struct Carre* newCale=joueur.cale;
    int newPos=joueur.pos;

    if((strcmp(carteChoisi.actionMatin,"or")==0) || (strcmp(carteChoisi.actionMatin,"po")==0) ||(strcmp(carteChoisi.actionMatin,"no")==0))
    {
        // ca prend la valeur de la crte et la place direct dans la cale
        newCale=chargeCale(newJoueur.cale,carteChoisi.actionMatin,de.deMatin,mainTresor);

    }
    else
    {
        // modifie la position en fonction de la valeur du de du matin
        newPos=updatePos(newPos,de.deMatin,carteChoisi.actionMatin);
    }

    if((strcmp(carteChoisi.actionSoir,"or")==0) || (strcmp(carteChoisi.actionSoir,"po")==0) ||(strcmp(carteChoisi.actionSoir,"no")==0))
    {
        newCale=chargeCale(newJoueur.cale,carteChoisi.actionSoir,de.deSoir,mainTresor);

    }
    else
    {
        // modifie la position en fonction de la valeur du de du soir et la carte
        newPos=updatePos(newPos,de.deSoir,carteChoisi.actionSoir);
    }
    newJoueur.pos=newPos;
    newJoueur.cale=newCale;
    return newJoueur;
}

int peutPayer(struct Carre* cale,int prix,char ressource[15])
{
    int verif=0;
    int compteur=0;
    int i=0;

    while((compteur<prix) && (i<TAILLE_CALE))
    {
        if (strcmp(cale[i].objet,ressource)==0)
        {
            compteur=cale[i].nbre;
        }
        i++;
    }
    if (compteur>=prix)
    {
        verif=1;
    }

    return verif;
}

struct Carre* payerNormal(struct Carre* cale,int prix, char ressource[15])
{
    int compteur=0;
    int i=0;
    while((compteur<prix)&&(i<TAILLE_CALE))
    {
        if(strcmp(cale[i].objet,ressource)!=0)
        {
            i++;
        }
        else
        {
            if(cale[i].nbre==0)
            {
                strcpy(cale[i].objet,"vide");
                i++;
            }
            cale[i].nbre--;
            compteur++;


        }
        if (cale[i].nbre==0)
        {
            strcpy(cale[i].objet,"vide");
        }
    }
    return cale;
}

struct Carre* payerPenurie(struct Carre* cale,char ressource[15])
{
    for(int i=0; i<TAILLE_CALE; i++)
    {
        if(strcmp(cale[i].objet,ressource)==0)
        {
            cale[i].nbre=0;
            strcpy(cale[i].objet,"vide");
        }
    }

    return cale;
}


// on passe la pos du joueur et le plateau

struct Carre* retirerRessourceDansCale(struct Carre* cale,int prix, char ressource[15],int pos,struct Case* plateau)
{



    if (peutPayer(cale,prix,ressource)==1)
    {
        cale=payerNormal(cale,prix,ressource);
    }
    else
    {

        printf("\nTu ne peux pas payer, tu n'as pas assez de ");
        motComplet(ressource);
        printf("\n");
        cale=payerPenurie(cale,ressource);

    }

    return cale;
}

struct Case* supprimerJetonTresor(struct Case casee,int pos,struct Case* plateau)
{

    if(plateau[pos-1].tr==1)
    {
        plateau[pos-1].tr=0;
    }
    return plateau;
}

struct MaillonTresor *suppElementDePiocheTresor(struct CarteTresor* mainTresor,struct MaillonTresor *piocheTresor)
{
    int verif=1;
    for(int i=0; i<TAILLE_MAIN_TRESOR; i++)
    {
        if ((strcmp(mainTresor[i].pouvoir,"null")==0) && (verif==1))
        {
            struct CarteTresor element = mainTresor[i-1];
            piocheTresor=suppElementListeChaineTresor(piocheTresor,element);
            verif=0;
        }
    }
    return piocheTresor;

}

struct Carre* viderCalePourPayer(struct Carre* cale,struct Case casee,int pos,struct Case* plateau)
{
    if(strcmp(casee.type,"hm")==0)
    {
        // on update la cale
        cale=retirerRessourceDansCale(cale,casee.prix,"no",pos,plateau);
    }
    else if(strcmp(casee.type,"port")==0)
    {
        cale=retirerRessourceDansCale(cale,casee.prix,"or",pos,plateau);
    }

    return cale;
}

struct CarteTresor* placerCarteTresor(struct CarteTresor* mainTresor,struct CarteTresor element)
{
    int verif=1;
    for(int i=0; i<TAILLE_MAIN_TRESOR; i++)
    {
        if ((mainTresor[i].nb==0) && (strcmp(mainTresor[i].pouvoir,"null")==0) && (verif==1))
        {
            mainTresor[i].nb=element.nb;
            strcpy(mainTresor[i].pouvoir,element.pouvoir);
            verif=0;
        }


    }

    return mainTresor;
}

struct Joueur morgan(struct Joueur joueurActuel)
{

    joueurActuel.main=remplitMain(joueurActuel.main,joueurActuel.pioche,TAILLE_MAIN-1);
    afficherMain(joueurActuel.main,TAILLE_MAIN);
    joueurActuel.pioche=suppElementListeChaine(joueurActuel.pioche,joueurActuel.main[TAILLE_MAIN-1]);

    return joueurActuel;
}



struct Joueur tirageCarteTresor(struct Joueur joueurActuel,struct MaillonTresor *piocheTresor)
{
    struct CarteTresor* mainTresor=joueurActuel.mainTresor;
    int taille=tailleListeChaineTresor(piocheTresor);
    int aleatoire=rand()%taille;
    struct CarteTresor element=elementListeChaineTresor(piocheTresor,aleatoire);

    mainTresor=placerCarteTresor(mainTresor,element);
    joueurActuel.mainTresor=mainTresor;

    if(strcmp(element.pouvoir,"morgan")==0)
    {
        joueurActuel=morgan(joueurActuel);
    }
    else if (strcmp(element.pouvoir,"cale")==0)
    {
        strcpy(joueurActuel.cale[TAILLE_CALE-1].objet,"vide");
        afficherCale(joueurActuel.cale,TAILLE_CALE,0);

    }
    return joueurActuel;
}

int nombrePoudre(struct Carre* cale)
{
    int compteur=0;
    for(int i=0; i<TAILLE_CALE; i++)
    {
        if(strcmp(cale[i].objet,"po")==0)
        {
            compteur+=cale[i].nbre;
        }
    }
    return compteur;
}

int aGagneCombat(int puissance1, int puissance2, int pos1, int pos2)
{
    int val=-1;
    if(puissance1>puissance2)
    {
        val=pos1;
    }
    else if(puissance2>puissance1)
    {
        val=pos2;
    }
    return val;

}


int bonChoixTresor(struct CarteTresor* mainTresor,int type)
{
    char message[100];

    if (type==0)
    {
        strcpy(message,"Choisis le numero de la case Tresor a voler\n");
    }
    else
    {
        strcpy(message,"Choisis le numero de la case Tresor a donner\n");
    }
    int choix=lireEnBoucleInt(message,1,TAILLE_MAIN_TRESOR);
    if (strcmp(mainTresor[choix-1].pouvoir,"null")==0)
    {
        while (strcmp(mainTresor[choix-1].pouvoir,"null")==0)
        {
            printf("Il n'y a pas de tresor a cette case\n");
            choix=lireEnBoucleInt(message,1,TAILLE_MAIN_TRESOR);
        }

    }

    return choix;
}
int bonChoixRessource (struct Carre* cale,struct CarteTresor* mainTresor)
{
    int taille;
    if(estTresor(mainTresor,"cale"))
    {
        taille=6;
    }
    else
    {
        taille=5;
    }

    int choix=lireEnBoucleInt("Choisis le numero de la case de la cale a voler\n",1,taille);
    if (strcmp(cale[choix-1].objet,"vide")==0)
    {
        while (strcmp(cale[choix-1].objet,"vide")==0)
        {
            printf("Il n'y a pas de ressource a cette case\n");
            choix=lireEnBoucleInt("Choisis le numero de la case de la cale a voler\n",1,taille);
        }

    }

    return choix;
}

// on
struct Joueur* volerTresor(struct Joueur* listeJoueur,int g, int p,int choix,int type)
{
    // la carte a la pos passé en parametre passe a null pour le perdant
    // le gagnant l'ajoute a sa main
    struct CarteTresor carte = listeJoueur[p].mainTresor[choix-1];
    strcpy(listeJoueur[p].mainTresor[choix-1].pouvoir,"null");

    if (strcmp(carte.pouvoir,"morgan")==0)
    {
        listeJoueur[g]=morgan(listeJoueur[g]);
        strcpy(listeJoueur[p].main[TAILLE_MAIN-1].actionMatin,"null");
        strcpy(listeJoueur[p].main[TAILLE_MAIN-1].actionSoir,"null");


    }
    else if (strcmp(carte.pouvoir,"cale")==0)
    {
        strcpy(listeJoueur[g].cale[TAILLE_CALE-1].objet,"vide");
        strcpy(listeJoueur[p].cale[TAILLE_CALE-1].objet,"null");
        afficherCale(listeJoueur[g].cale,TAILLE_CALE,0);
    }

    int posDispo=posCaseVideTresor(listeJoueur[g].mainTresor);
    listeJoueur[g].mainTresor[posDispo]=carte;

    if (type==0)
    {
        printf("Tu viens de voler le tresor : ");

    }
    else
    {
        printf("Tu viens de donner le tresor : ");
    }
    transformAffichTresor(carte.pouvoir,carte.nb);
    printf("\n");



    return listeJoueur;
}

int mainTresorVide(struct CarteTresor* mainTresor)
{
    int verif=1;
    for(int i=0; i<TAILLE_MAIN_TRESOR; i++)
    {
        if(strcmp(mainTresor[i].pouvoir,"null")!=0)
        {
            verif=0;
        }
    }
    return verif;
}

int caleVide(struct Carre* cale)
{
    int verif=1;
    for(int i=0; i<TAILLE_CALE; i++)
    {
        if((strcmp(cale[i].objet,"po")==0) || (strcmp(cale[i].objet,"or")==0)||(strcmp(cale[i].objet,"no")==0))
        {
            verif=0;
        }
    }
    return verif;
}

struct Joueur* choixGagnantCombat(struct Joueur* listeJoueurs,int g,int p)
{
    int choix;
    couleurJoueur(listeJoueurs[g].couleur);
    printf("%s ",listeJoueurs[g].pseudo);
    Color(15,0);
    printf("Tu as gagne le combat !\n\n");
    afficherMainTresor(listeJoueurs[g].mainTresor);
    afficherMainTresorFaceCachee(listeJoueurs[p].mainTresor);
    afficherCale(listeJoueurs[g].cale,TAILLE_CALE,0);
    afficherCale(listeJoueurs[p].cale,TAILLE_CALE,1);
    int choixVol=lireEnBoucleInt("\nQue veux tu faire ?\n-1 Voler un tresor\n-2 Donner un tresor\n-3 Voler le contenu d'une cale\n",1,3);
    struct Carre choixCarre;

    switch(choixVol)
    {
    case 1:
        if(mainTresorVide(listeJoueurs[p].mainTresor))
        {
            printf("L'adversaire n'a pas de tresor !\n");
            return listeJoueurs;
        }
        else
        {
            choix=bonChoixTresor(listeJoueurs[p].mainTresor,0);
            listeJoueurs=volerTresor(listeJoueurs,g,p,choix,0);
        }
        break;
    case 2:
        if(mainTresorVide(listeJoueurs[g].mainTresor))
        {
            printf("Tu n'as pas de tresor !\n");
            return listeJoueurs;
        }
        else
        {
            choix=bonChoixTresor(listeJoueurs[g].mainTresor,1);
            listeJoueurs=volerTresor(listeJoueurs,p,g,choix,1);
        }

        break;
    case 3:
        if(caleVide(listeJoueurs[p].cale))
        {
            printf("L'adversaire n'a pas de ressource !\n");
            return listeJoueurs;
        }
        else
        {
            choix=bonChoixRessource(listeJoueurs[p].cale,listeJoueurs[p].mainTresor);
            choixCarre=listeJoueurs[p].cale[choix-1];
            strcpy(listeJoueurs[p].cale[choix-1].objet,"vide");
            listeJoueurs[p].cale[choix-1].nbre=0;
            listeJoueurs[g].cale=chargeCale(listeJoueurs[g].cale,choixCarre.objet,choixCarre.nbre,listeJoueurs[g].mainTresor);
        }

        break;
        return listeJoueurs;
    }

    return listeJoueurs;
}


int deCombatSaran(int choix,int deAttaquant,struct CarteTresor* mainTresor)
{
    if(estTresor(mainTresor,"saran"))
    {
        if(choix==1)
        {
            deAttaquant=decombat(mainTresor,0);
        }
        else
        {
            printf("Tu as choisi de ne rien faire\n");
        }
    }
    return deAttaquant;
}


struct Joueur* combat(int a,int d, struct Joueur* listeJoueurs) // a: posAttaquant b: posDefenseur
{
    int choixSaran=0;
    int choix,choix2,choixSaran2;
    int nbPoudre,nbPoudre2,deAttaquant,deDefenseur,puissance,puissance2;
    int g; // pos du gagnant
    int p; // pos du perdant
    couleurJoueur(listeJoueurs[a].couleur);
    printf("\n\n\n%s",listeJoueurs[a].pseudo);
    Color(15,0);
    printf(" tu tombes sur la case de");
    couleurJoueur(listeJoueurs[d].couleur);
    printf(" %s\n",listeJoueurs[d].pseudo);
    Color(15,0);
    system("pause");
    system("cls");
    printf("\n");
    Color(12,0);
    printf("\n\tX COMBAT X\n");
    printf("\n");
    Color(15,0);
    printf("L'attaquant");
    couleurJoueur(listeJoueurs[a].couleur);
    printf(" %s",listeJoueurs[a].pseudo);
    Color(15,0);
    printf(" commence !\n");
    nbPoudre=nombrePoudre(listeJoueurs[a].cale);
    afficherCale(listeJoueurs[a].cale,TAILLE_CALE,0);
    choix=lireEnBoucleInt("Combien de poudre veux tu utiliser ?\n",0,nbPoudre);
    listeJoueurs[a].cale=payerNormal(listeJoueurs[a].cale,choix,"po");
    printf("Tu tires le de !\n");
    system("pause");
    printf("\n");
    deAttaquant=decombat(listeJoueurs[a].mainTresor,0);

    if(estTresor(listeJoueurs[a].mainTresor,"saran"))
    {
        printf("Tu possedes la carte ");
        Color(13,0);
        printf("sabre de Saran");
        Color(15,0);
        choixSaran=lireEnBoucleInt(". Veux-tu relancer ton de d'attaque ?\n-1 oui\n-2 non\n",1,2);
        deAttaquant=deCombatSaran(choixSaran,deAttaquant,listeJoueurs[a].mainTresor);
        printf("Ton nouveau de d'attaque est : %d\n",deAttaquant);
    }
    puissance=deAttaquant+choix;
    printf("Ta puissance de feu est de : %d\n\n\n",puissance);

    if (deAttaquant==12)
    {
        couleurJoueur(listeJoueurs[a].couleur);
        printf("%s",listeJoueurs[a].pseudo);
        Color(15,0);
        printf(" gagne le combat !\n\n");
        g=a;
        p=d;
    }
    else
    {

        printf("Le defenseur");
        couleurJoueur(listeJoueurs[d].couleur);
        printf(" %s",listeJoueurs[d].pseudo);
        Color(15,0) ;
        printf(" contre attaque!\n");
        nbPoudre2=nombrePoudre(listeJoueurs[d].cale);
        afficherCale(listeJoueurs[d].cale,TAILLE_CALE,0);
        choix2=lireEnBoucleInt("Combien de poudre veux tu utiliser ?\n",0,nbPoudre2);
        listeJoueurs[d].cale=payerNormal(listeJoueurs[d].cale,choix2,"po");
        printf("Tu tires le de !\n");
        system("pause");

        printf("\n\n");
        deDefenseur=decombat(listeJoueurs[d].mainTresor,0);

        if (estTresor(listeJoueurs[d].mainTresor,"saran"))
        {
            printf("Tu possedes la carte ");
            Color(13,0);
            printf("sabre de Saran");
            Color(15,0);
            choixSaran2=lireEnBoucleInt(". Que veux tu faire ?\n-1 Relancer le de adverse\n-2 Relancer ton de\n-3 Ne rien faire\n",1,3);
            if (choixSaran2==1)
            {
                deAttaquant=decombat(listeJoueurs[a].mainTresor,1);
                puissance=deAttaquant+choix;
                printf("La nouvelle puissance de feu de l'adversaire est de : %d\n",puissance);
            }
            else if (choixSaran2==2)
            {
                deDefenseur=decombat(listeJoueurs[d].mainTresor,0);
            }
        }

        if(choixSaran==2)
        {
            couleurJoueur(listeJoueurs[a].couleur);
            printf("%s",listeJoueurs[a].pseudo);
            Color(15,0);
            printf(", tu possedes la carte ");
            Color(13,0);
            printf("sabre de Saran");
            Color(15,0);
            choixSaran=lireEnBoucleInt(". Veux-tu relancer le de du defenseur ?\n-1 oui\n-2 non\n",1,2);
            deDefenseur=deCombatSaran(choixSaran,deDefenseur,listeJoueurs[a].mainTresor);
            if (choixSaran==1)
            {
                puissance2=deDefenseur+choix2;
                printf("La nouvelle puissance de feu de l'adversaire est : de %d\n",puissance2);
            }

        }


        puissance2=deDefenseur+choix2;
        printf("Ta puissance de feu est de : %d\n\n",puissance2);



        if(deDefenseur==12)
        {
            couleurJoueur(listeJoueurs[d].couleur);
            printf("%s",listeJoueurs[d].pseudo);
            Color(15,0);
            printf(" gagne le combat !\n\n\n");
            g=d;
            p=a;
        }
        else
        {
            if(aGagneCombat(puissance,puissance2,a,d)==-1)
            {
                printf("Vous avez une puissance egale\n");
                Color(12,0);
                printf("\t EGALITE \n\n");
                printf("    X COMBAT TERMINE X\n");
                Color(15,0);
                system("pause");
                system("cls");
                printf("\n\n");
                return listeJoueurs;

            }
            else
            {
                g=aGagneCombat(puissance,puissance2,a,d);
                if(g==a)
                {
                    p=d;

                }
                else
                {
                    p=a;
                }
                couleurJoueur(listeJoueurs[g].couleur);
                printf("%s",listeJoueurs[g].pseudo);
                Color(15,0);
                printf(" gagne le combat !\n\n");
            }
        }
    }
    Color(12,0);
    printf("    X COMBAT TERMINE X\n");
    Color(15,0);
    system("pause");
    system("cls");
    printf("\n\n");

    listeJoueurs=choixGagnantCombat(listeJoueurs,g,p);
    system("pause");
    system("cls");
    printf("\n\n");


    return listeJoueurs;
}

int casePrise(int pos,struct Joueur* listeJoueurs, int taille,int i)
{
    int verif=-1;
    for(int j=0; j<taille; j++)
    {
        if((listeJoueurs[j].pos==pos) && (i!=j))
            verif=j;
    }
    return verif;
}


// commun a tous le monde
struct Jeu updateJeu(struct Jeu jeu,int i,int taille)
{
    int choix;
    int posPrecedente;
    // on va chercher la liste de joueur du jeu
    struct Joueur* listeJoueur=jeu.listeJoueur;
    // on va chercher le joeur actuel
    struct Joueur joueurActuel=listeJoueur[i];
    posPrecedente=joueurActuel.pos;

    struct MaillonTresor *piocheTresor=jeu.piocheTresor;

    // on va chercher la banque du je
    // on va chercher les des du jeu
    struct DeJeu de=jeu.de;

    struct Case* plateau=jeu.plateau;
    afficherDe(de);

    if (estTresor(joueurActuel.mainTresor,"morgan"))
    {
        choix = lireEnBoucleInt("Choisis ta carte\n (1-2-3-4)\n",1,4);
    }
    else
    {
        choix = lireEnBoucleInt("Choisis ta carte\n (1-2-3)\n",1,3);
    }


    struct CarteAction carteChoisi = choisirCarte(choix,joueurActuel.main);

    printf("Tu as choisi la carte |  ");
    transformAffich(carteChoisi.actionMatin);
    printf("  ");
    transformAffich(carteChoisi.actionSoir);
    printf("  |\n");




    // update la cale, la pioche et la cale du joueur
    joueurActuel=utiliserCarteAction(joueurActuel,carteChoisi,de,joueurActuel.mainTresor);
    afficherCale(joueurActuel.cale,TAILLE_CALE,0);

    // on affiche les actions réalisés
    printf("\nTu es maintenant en case numero");
    Color(12,0);
    printf(" %d",joueurActuel.pos);
    Color(15,0);
    printf(" : ");
    // sauvegarde la case sur laquelle le joueur tombe
    struct Case casee =plateau[joueurActuel.pos-1];
    motComplet(plateau[joueurActuel.pos-1].type);

    int posDefDansListe=casePrise(joueurActuel.pos,listeJoueur,taille,i);
    if((posDefDansListe!=-1) && (strcmp(casee.type,"pr")!=0))
    {
        // si le joueur s'est deplace
        if (posPrecedente!=joueurActuel.pos)
        {
            listeJoueur=combat(i,posDefDansListe,listeJoueur);
            couleurJoueur(joueurActuel.couleur);
            printf("\n%s ",joueurActuel.pseudo);
            Color(15,0);
            printf("continue ton tour !\n ");
            afficherCale(joueurActuel.cale,TAILLE_CALE,0);
        }




    }
    printf("\nTu payes %d ",casee.prix);
    afficherRessourceDeCase(casee.type);




    joueurActuel.cale=viderCalePourPayer(joueurActuel.cale,casee,joueurActuel.pos,plateau);

    if ((strcmp(casee.type,"tr")==0) && (casee.tr==1))
    {
        plateau[joueurActuel.pos-1].tr=0;
        // on update la main
        joueurActuel=tirageCarteTresor(joueurActuel,piocheTresor);
        piocheTresor=suppElementDePiocheTresor(joueurActuel.mainTresor,piocheTresor);

    }
    afficherMainTresor(joueurActuel.mainTresor);

    printf("\n");
    afficherCale(joueurActuel.cale,TAILLE_CALE,0);

    if (joueurActuel.pioche==NULL)
    {
        joueurActuel.pioche=initPioche();
    }
    joueurActuel.main=remplitMain(joueurActuel.main,joueurActuel.pioche,choix-1);
    joueurActuel.pioche=suppElementListeChaine(joueurActuel.pioche,carteChoisi);
    Color(10,0);
    printf("\n\t  FIN DU TOUR\n\n");
    Color(15,0);
    system("pause");
    system("cls");
    printf("\n\n");
    listeJoueur[i]=joueurActuel;
    jeu.listeJoueur=listeJoueur;
    jeu.plateau=plateau;
    jeu.piocheTresor=piocheTresor;
    jeu.de=de;
    return jeu;
}

void tourDeJeu(struct Jeu jeu,int taille)
{
    int numCap=0;
    int verifFin =0;
    int numJoueur=0;
    int numAncienCap =0;
    int posGagnant;

    while(verifFin==0)
    {

        for(int i=0; i<taille; i++)
        {
            if ((i!=numAncienCap) && (numJoueur<=taille))
            {
                // tour des joueur NON capitaine
                affichageJoueur(jeu.listeJoueur,taille,i,jeu.plateau);
                // on modifie le joueur
                jeu=updateJeu(jeu,i,taille);
                if(jeu.listeJoueur[i].pos>50)
                {
                    verifFin=1;
                    posGagnant=i;
                }

                numJoueur++;

            }
            else if (i==numCap)
            {
                numAncienCap=numCap;
                numJoueur=1;
                affichageJoueur(jeu.listeJoueur,taille,i,jeu.plateau);
                affichageCapitaine();
                // on lance les dés
                jeu.de=updateDeJeu();

                jeu=updateJeu(jeu,i,taille);
                if(jeu.listeJoueur[i].pos>50)
                {
                    verifFin=1;
                    posGagnant=i;
                }
                numJoueur++;
            }
        }
        // tour des joueur NON capitaine
        if (numCap==taille-1)
        {
            for(int i=0; i<taille-1; i++)
            {
                affichageJoueur(jeu.listeJoueur,taille,i,jeu.plateau);
                jeu=updateJeu(jeu,i,taille);
                if(jeu.listeJoueur[i].pos>50)
                {
                    verifFin=1;
                    posGagnant=i;
                }
                numJoueur++;
            }
            numCap=0;
        }
        else
        {
            numCap++;
        }

    }
    // tour des joueur NON capitaine
    for(int i=0; i<numCap-1; i++)
    {
        affichageJoueur(jeu.listeJoueur,taille,i,jeu.plateau);
        jeu=updateJeu(jeu,i,taille);
        if(jeu.listeJoueur[i].pos>50)
        {
            verifFin=1;
            posGagnant=i;
        }
        numJoueur++;
    }
    couleurJoueur(jeu.listeJoueur[posGagnant].couleur);
    printf("%s ",jeu.listeJoueur[posGagnant].pseudo);
    Color(15,0);
    printf("vient de franchir ") ;
    motComplet("pr");
    printf("!!\n");
    system("pause");
    system("cls");
    printf("\n\n");
    affichageFinDePartie(jeu.listeJoueur,taille,jeu.plateau);




    printf("\n\n\t   ");

    Color(10,0);
    printf("F");
    Color(14,0);
    printf("I");
    Color(13,0);
    printf("N");
    Color(11,0);
    printf(" ");
    Color(10,0);
    printf("D");
    Color(14,0);
    printf("U");
    printf(" ");
    Color(13,0);
    printf("J");
    Color(11,0);
    printf("E");
    Color(10,0);
    printf("U");
    Color(14,0);
    printf(" !");
    Color(13,0);
    printf("!");
    Color(15,0);
    printf("\n\n\n");
}



int main()
{

    Color(15,0);

    int taille= lireEnBoucleInt("\nEntrez un nombre de joueur entre 2 et 6\n",2,6);
    struct Jeu jeu=initJeu(taille);

    printf("Les cales de chaque joueur son remplies avec 3 jetons or et 3 jetons nourriture\n ");
    tourDeJeu(jeu,taille);

}



