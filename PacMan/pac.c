#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>


#define H (3) //height
#define W (4) //width
#define G (2) //nombre de fantômes


//fonctions qui renvoient des chiffres alea entre 0 et H-1 et W-1 
int aleatoireH() {
    return (rand() % H);
}

int aleatoireW() {
    return (rand() % W);
}


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
};

struct ghost {
	struct coord goo;
	int gx; //direction du fantôme
	int gy; 
};


//générer un jeu de coordonnées
struct coord genere(int** field){
	int h = aleatoireH();
	int w = aleatoireW();
	while(field[h][w]!=0){
		h = aleatoireH();
		w = aleatoireW();
	}

	struct coord coo ={h,w};
}


///////
/*On initialise le Pacman*/

//fonction qui place un fantôme 
struct ghost place_G(int** field){
	struct ghost gho;

	//on génère aléatoirement les coordonnées
	struct coord coo = genere(field);
	while(coo.x == 1 || coo.y == 1){
		coo = genere(field);
	} 

	gho.goo = coo;
	gho.gx = 0;
	gho.gy = 0;

	return(gho);

}
//normalement cette fonction marche



//fonction qui initialise le pacman --> erreur de segmentation
int** initialize (int** field){

	//on initialise les ghosts 
	for (int i = 0; i<G; i++){
		struct ghost gi = place_G(field); //fonction qui place un ghost
		field[gi.goo.x][gi.goo.y] = 3 ;//on update le field
	}


	//On initialise le pacman
	struct coord p0 = {1,1};
	struct pacman pac = {p0,0,0,3,0};

	field[p0.x][p0.y]=2;

	return(field);

}



/////////////


//fonction affichage
void affichage(int** matrice){
	for (int i =0; i<H; i++){
		for (int j =0; j<W; j++){
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}

}





int main (){
	srand(time(NULL));

	///test
	int** area = malloc(H*sizeof(int*));
	for (int i = 0; i<H; i++){
		area[i] = malloc(W*sizeof(int));
		for (int j =0; j<W;j++){
			area[i][j]=0;
		}
	}
	area[0][0]=1;
	area[2][2] = 1;
	affichage(area);
	
	////

	
	area = initialize(area);
	affichage(area);
	
}

