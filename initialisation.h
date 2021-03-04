#ifndef H_GL_INITIALISATION
#define H_GL_INITIALISATION
#define TAILLE_PLATEAU 50
#define TAILLE_CALE 6
#define TAILLE_PIOCHE 11
#define TAILLE_MAIN 4
#define TAILLE_MAIN_TRESOR 9
#define TAILLE_TRESOR
#define BORNE 6


// Structure du de contenant une valeur pour le matin et une autre pour le soir
struct DeJeu {
    int deMatin;
    int deSoir;
};

// Structure d'une case contenant son cout,son type et sa valeur de poihts et in booleen qui renvoit si c'est un tresor ou non
struct Case
{
    char type[15];
    int prix;
    int num;
    int tr;

};

struct Carre     // case dans cale
{
    int nbre;
    char objet[15];
};

struct CarteAction                                   // strucuture d'une carte
{
    char actionMatin[15];
    char actionSoir[15];
};

struct MaillonAction
{
    struct CarteAction valeur;
    struct MaillonAction *suivant;
};

struct Joueur                              // structure d'un joueur
{
    int pos;
    char pseudo[15];
    struct Carre* cale;
    struct MaillonAction *pioche;
    struct MaillonAction *defausse;
    struct CarteAction* main;
    struct CarteTresor* mainTresor;
    int couleur;

};

struct CarteTresor
{
    char pouvoir[20];
    int nb;
};

struct MaillonTresor
{
    struct CarteTresor valeur;
    struct MaillonTresor *suivant;

};


struct Jeu
{
    struct Joueur* listeJoueur;
    struct MaillonTresor *piocheTresor;
    struct DeJeu de;
    struct Case* plateau;
};
struct MaillonAction *initListeChaine(char a[15],char b[15]);
struct MaillonTresor *initListeChaineTresor(char a[15],int val);
struct MaillonAction* ajoutDebutListeChaine(struct MaillonAction *tete,struct MaillonAction *nouveau);
struct MaillonTresor* ajoutDebutListeChaineTresor(struct MaillonTresor *tete,struct MaillonTresor *nouveau);
struct Case* initPlateau();

struct MaillonTresor* initPiocheTresor();

struct MaillonAction *initPioche();

struct Carre* initCale();

struct CarteAction elementListeChaine(struct MaillonAction *tete,int pos);
struct CarteTresor elementListeChaineTresor(struct MaillonTresor *tete,int pos);

struct MaillonAction* suppElementListeChaine(struct MaillonAction* tete, struct CarteAction valeur);
struct MaillonTresor* suppElementListeChaineTresor(struct MaillonTresor* tete, struct CarteTresor valeur);

int tailleListeChaine(struct MaillonAction *tete);
int tailleListeChaineTresor(struct MaillonTresor *tete);

struct CarteAction* remplitMain(struct CarteAction* mainn,struct MaillonAction *pioche,int j);

struct Joueur initMainUpdatePioche(struct MaillonAction *pioche);

struct Banque initBanque(int taille);

int pseudoDansListeJoueur(char pseudo[15],struct Joueur* liste,int taille);

int couleurDansListeJoueur(int couleur,struct Joueur* liste,int taille) ;

int lireEnBoucleInt(char messageLecture[100],int borneInf,int borneSup);

struct Joueur* initListeJoueur(int taille);

struct Joueur* newInitListeJoueur(struct Joueur* listeJoueur,int taille);

struct MaillonTresor *tirageDebutPartieCarteTresor(struct MaillonTresor *piocheTresor);

struct Jeu initJeu(int taille);

#endif // H_GL_INITIALISATION


