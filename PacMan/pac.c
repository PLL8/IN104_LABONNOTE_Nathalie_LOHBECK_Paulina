#include <stdlib.h>
#include <stdbool.h>


#define H (30) //height
#define W (60) //width
#define G (6) //nombre de fantômes


struct coord {
	int x;
	int y;
};


struct pacman{
	struct coord coo;
	int nx;
	int ny;
	int lives;
	int food;
}

struct ghost {
	struct coord goo;
	struct gx; //direction du fantôme
	struct gy; 
}

//fonction qui initialise le pacman
void

int main (){
	//Liste des ghosts;
	struct ghost list_ghosts[G];

	//On initialise le pacman
	struct coord p0 = {1,1};
	struct pacman pac = {p0,0,0,3,0};
