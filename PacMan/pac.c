#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>


#define H (3) //height
#define W (4) //width
#define G (2) //nombre de fantômes

/*
Manière de remplir le field :
 - 0 = nourriture
 - 1 = mur (inaccessible)
 - 2 = le pacman
 - 3 = les ghosts
 */


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
	struct coord coo; //coordonnées du pacman
	int nx; //direction de déplacement horizontal
	int ny; //direction de déplacement vertical
	int lives;
	int food;
};

struct ghost {
	struct coord goo;
	int gx; 
	int gy; 
};


//générer un jeu de coordonnées
struct coord genere(int** field){
	int x = aleatoireH();
	int y = aleatoireW();
	while(field[x][y]!=0){ //on cherche un lieu de la map où il n'y a pas encore de personnage
		x = aleatoireH();
		y = aleatoireW();
	}

	struct coord coo ={x,y};
	return(coo);
}


///////
/*On initialise le Pacman*/

//fonction qui place un fantôme 
struct ghost place_init_G(int** field){
	struct ghost gho;

	//on génère aléatoirement les coordonnées
	struct coord coo = genere(field);
	while(coo.x == 1 && coo.y == 1){ // la place (1,1) est utilisée pour placer le pacman
		coo = genere(field);
	} 

	gho.goo = coo;
	gho.gx = 0;
	gho.gy = 0;

	return(gho);

}




//fonction qui initialise le pacman --> erreur de segmentation
int** initialize (int** field){

	//on initialise les ghosts 
	for (int i = 0; i<G; i++){
		struct ghost gi = place_init_G(field); //fonction qui place un ghost
		field[gi.goo.x][gi.goo.y] = 3 ;//on update le field
	}


	//On initialise le pacman
	struct coord p0 = {1,1};
	int vie = 3; //on initialise le nombre de vie du pacman
	struct pacman pac = {p0,0,0,vie,0};

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

	printf("fonction initilaize\n");
	area = initialize(area);
	affichage(area);
	
}

