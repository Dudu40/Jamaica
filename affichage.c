
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

#include "initialisation.h"
#include "affichage.h"


void Color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void couleurJoueur(int couleur)
{
    switch(couleur)
    {
    case 1:
        Color(11,0);
        break;
    case 2:
        Color(12,0);
        break;
    case 3:
        Color(10,0);
        break;
    case 4:
        Color(14,0);
        break;
    case 5:
        Color(13,0);
        break;
    case 6:
        Color(2,0);
        break;
    }

}

void motComplet(char mot[15])
{

    if(strcmp(mot,"or")==0)
    {
        Color(14,0);
        printf("jetons or");

    }
    else if(strcmp(mot,"tr")==0)
    {
        Color(14,0);
        printf("tresor");
    }
    else if(strcmp(mot,"av")==0)
    {
        Color(10,0);
        printf("avances");

    }
    else if(strcmp(mot,"re")==0)
    {
        Color(12,0);
        printf("recules");

    }
    else if(strcmp(mot,"po")==0)
    {
        Color(5,0);
        printf("jetons poudre a canon");

    }
    else if(strcmp(mot,"no")==0)
    {
        Color(3,0);
        printf("jetons nourriture");

    }
    else if(strcmp(mot,"pr")==0)
    {
        Color(10,0);
        printf("Port Royal");
    }
    else if(strcmp(mot,"hm")==0)
    {
        Color(9,0);
        printf("Haute mer");
    }
    else if(strcmp(mot,"port")==0)
    {
        Color(11,0);
        printf("port");
    }
    Color(15,0);
}


void transformAffich(char mot[15])
{

    if(strcmp(mot,"or")==0)
    {

        Color(14,0);
        printf("%c",254);
    }
    else if(strcmp(mot,"av")==0)
    {
        Color(10,0);
        printf(">>");
    }
    else if(strcmp(mot,"re")==0)
    {
        Color(12,0);
        printf("<<");
    }
    else if(strcmp(mot,"po")==0)
    {
        Color(5,0);
        printf("%c",254);
    }
    else if(strcmp(mot,"no")==0)
    {
        Color(3,0);
        printf("%c",254);
    }
    else if(strcmp(mot,"vide")==0)
    {
        Color(12,0);
        printf("X");
    }

    else if (strcmp(mot,"carte")==0)
    {
        Color(12,0);
        printf("?");
    }

    else if (strcmp(mot,"null")==0)
    {
        printf(" ");
    }
    else
    {
        printf("%s",mot);
    }

    Color(15,0);



}

void transformAffichTresor(char mot[15],int nbre)
{
    if(strcmp(mot,"carte")==0)
    {
        if(nbre<0)
        {
            printf("malus ");
            Color(12,0);
        }
        else if(nbre>0)
        {
            printf("bonus ") ;
            Color(10,0);
            printf("+");

        }
        printf("%d ",nbre);

    }
    else if (strcmp(mot,"null")!=0)
    {
        Color(13,0);
        printf("%s",mot);
    }
    else
    {
        printf("   ");
    }
    Color(15,0);
}


void afficherRessourceDeCase(char mot[15])
{
    if(strcmp(mot,"hm")==0)
    {
        Color(3,0);
        printf("jetons nourriture");
    }
    else if(strcmp(mot,"port")==0)
    {
        Color(14,0);
        printf("jetons or");
    }
    else
    {
        printf("jetons");
    }

    Color(15,0);
    printf("\n");
}

void afficherMain(struct CarteAction* mainn,int taille)
{

    printf("Ta main :\n ");
    for(int i=0; i<taille; i++)
    {
        printf("  ");
        transformAffich(mainn[i].actionMatin);
        printf("  ");
        transformAffich(mainn[i].actionSoir);

        if (i<taille-1)
        {
            printf("  | ");
        }



    }
    printf("\n");

}

void afficherMainTresor(struct CarteTresor* mainTresor)
{
    printf("Tes tresors :\n");
    for(int i=0; i<TAILLE_MAIN_TRESOR; i++)
    {
        transformAffichTresor(mainTresor[i].pouvoir,mainTresor[i].nb);
        printf("  ");


    }
    printf("\n");

}




void afficherCale(struct Carre* liste,int taille,int type)
{
    if (type==0){
       printf("Ta cale :\n ");
    }
    else{
       printf("Cale adverse :\n ");
    }

    for(int i=0; i<TAILLE_CALE; i++)
    {
        if(liste[i].nbre>0)
        {
            Color(10,0);
            printf("  %d ",liste[i].nbre);
        }
        else
        {
            printf(" ");
        }


        transformAffich(liste[i].objet);

        if(i<TAILLE_CALE-1)
        {
            printf("  | ");
        }
    }

    if (strcmp(liste[TAILLE_CALE-1].objet,"null")!=0)
    {
        printf("  | ");
    }
    printf("\n");

}

void affichagePosJoueurs(struct Joueur* listeJoueur,int taille,int pos)
{
    printf("Positions des adversaires :\n");
    printf("  ");
    for(int i=0;i<taille;i++)
    {
        if (i!=pos)
        {
            printf("{");
            couleurJoueur(listeJoueur[i].couleur);
          printf("%s",listeJoueur[i].pseudo);
          Color(15,0);
            printf(" -> ");
            Color(12,0);
            printf("%d",listeJoueur[i].pos);
            Color(15,0);
            printf("}  ");
        }
    }
    printf("\n");
}

void affichageCasesTresor(struct Case* plateau)
{
    printf("Cases tresors disponibles :\n");
    printf("  ");
    for(int i=0;i<TAILLE_PLATEAU;i++)
    {
        if ((strcmp(plateau[i].type,"tr")==0) && (plateau[i].tr==1))
        {
            Color(14,0);
            printf("%d  ",i+1);
        }
    }
    Color(15,0);
    printf("\n\n");
}

void affichageJoueur(struct Joueur* listeJoueur,int taille,int i,struct Case* plateau)
{
    printf("Au tour du joueur : ");
    couleurJoueur(listeJoueur[i].couleur);
    printf("{%s}\n",listeJoueur[i].pseudo);
    Color(15,0);
    printf("Tu es en case numero");
    Color(12,0);
    printf(" %d\n",listeJoueur[i].pos) ;
    Color(15,0);

    affichagePosJoueurs(listeJoueur,taille,i);
    affichageCasesTresor(plateau);
    afficherCale(listeJoueur[i].cale,TAILLE_CALE,0);
    afficherMain(listeJoueur[i].main,TAILLE_MAIN);
}



void affichageCapitaine()
{
    printf("\nTu es le ");
    Color(14,0);
    printf("capitaine\n");
    Color(15,0);
    printf("Tu tires les des !!\n");
}

void afficherDe(struct DeJeu de )
{
    printf("Le de du matin est : ");
    Color(13,0);
    printf("%d",de.deMatin) ;
    Color(15,0);
    printf("\nLe de du soir est : ") ;
    Color(13,0);
    printf("%d\n",de.deSoir);
    Color(15,0);
}

void afficherMainTresorFaceCachee(struct CarteTresor* mainTresor)
{
    printf("Tresors de l'adversaire :\n");
    printf("  ");
    for(int i=0; i<TAILLE_MAIN_TRESOR; i++)
    {
        if((strcmp(mainTresor[i].pouvoir,"carte")!=0) && (strcmp(mainTresor[i].pouvoir,"null")!=0)){
            Color(13,0);
            printf("%s",mainTresor[i].pouvoir);
        }
        else{
           transformAffich(mainTresor[i].pouvoir);
        }

        printf("  ");
    }
    printf("\n");
}

int compterPoint(struct Joueur joueurActuel, struct Case* plateau)
{
    int res=0;
    int pointsPos;
    int pointsOr=0;
    int pointTres;
    if(joueurActuel.pos>50)
    {
        pointsPos=15;
    }
    else
    {
        pointsPos=plateau[joueurActuel.pos-1].num;
    }

    for(int i=0;i<TAILLE_CALE;i++)
    {
        if(strcmp(joueurActuel.cale[i].objet,"or")==0)
        {
            pointsOr+=joueurActuel.cale[i].nbre;
        }
    }
    for(int j=0;j<TAILLE_CALE;j++)
    {
        pointTres+=joueurActuel.mainTresor[j].nb;
    }
    res=pointsOr+pointsPos+pointTres;
    return res;
}

void affichageFinDePartie(struct Joueur* listeJoueur,int taille, struct Case* plateau)
 {
    int points=0;
    int max=-100;
    int posVainqueur;
    Color(14,0);
    printf("\n\n  ON COMPTE LES POINTS\n\n");
    Color(15,0);

    for(int i=0;i<taille;i++)
    {
        couleurJoueur(listeJoueur[i].couleur);
        printf("\t{%s}\n",listeJoueur[i].pseudo);
        Color(15,0);
        afficherCale(listeJoueur[i].cale,TAILLE_CALE,0);
        afficherMainTresor(listeJoueur[i].mainTresor);
        printf("Cases de differences avec le premier arrive : %d\n",50-listeJoueur[i].pos);
        points=compterPoint(listeJoueur[i],plateau);
        printf("Tes points :");
        Color(10,0);
        printf(" %d \n\n",points);
        Color(15,0);
        if(points>max)
        {
            max=points;
            posVainqueur=i;
        }

    }
    couleurJoueur(listeJoueur[posVainqueur].couleur);
    printf("\n\n%s ",listeJoueur[posVainqueur].pseudo);
    Color(15,0);
    printf("remporte la partie avec un total de ");
    Color(10,0);
    printf("%d",max);
    Color(15,0);
    printf(" points !!\n");

 }













