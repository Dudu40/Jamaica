#ifndef H_GL_AFFICHAGE
#define H_GL_AFFICHAGE

void Color(int t,int f);


void couleurJoueur(int couleur);

void motComplet(char mot[15]);

void transformAffich(char mot[15]);

void transformAffichTresor(char mot[15],int nbre);

void afficherRessourceDeCase(char mot[15]);

void afficherMain(struct CarteAction* mainn,int taille);

void afficherMainTresor(struct CarteTresor* mainTresor);

void afficherCale(struct Carre* liste,int taille,int type);

void affichagePosJoueurs(struct Joueur* listeJoueur,int taille,int pos);

void affichageCasesTresor(struct Case* plateau);

void affichageJoueur(struct Joueur* listeJoueur,int taille,int i,struct Case* plateau);

void affichageCapitaine();

void afficherDe(struct DeJeu de );

void afficherMainTresorFaceCachee(struct CarteTresor* mainTresor);

int compterPoint(struct Joueur joueurActuel, struct Case* plateau);

void affichageFinDePartie(struct Joueur* listeJoueur,int taille, struct Case* plateau);



#endif
