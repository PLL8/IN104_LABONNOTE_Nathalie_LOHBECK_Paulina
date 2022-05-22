#ifndef __PAC_H__
#define __PAC_H__

int aleatoireH();
int aleatoireW();

struct coord {
	int x;
	int y;
};


struct pacman{
	struct coord coo; //coordonnées du pacman
	int nx; //direction de déplacement vertical
	int ny; //direction de déplacement horizontal
	int lives;
	int food;
};

struct ghost {
	struct coord goo;
	int gx; 
	int gy; 
};

struct coord genere(int** field);
struct ghost place_init_G(int** field);
int** initialize(int** field, struct ghost* list_ghost);
void affichage_ghost (struct ghost gho);
void affichage_base(int** matrice);


#endif