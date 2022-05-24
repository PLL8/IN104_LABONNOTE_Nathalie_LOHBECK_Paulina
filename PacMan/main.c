#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

#include "jeu.h"
#include "field.h"
#include "pac.h"
#include "verif.h"

#define H (30) //height
#define W (60) //width
#define G (6) //nombre de fantômes
#define V (3)  //nombre de vies

/*Etapes dans le main :
 * On initalise le field
 * On initialise les positions
 * on fait une boucle while (tant que le pacman a des vies et qu'il reste de la nourriture)
 	* on demande au joueur de se placer
 	* on adapte le field
 	* on fait bouger les ghosts
 	* on adapte le field et au besoin on adapte la position du pacman (si un ghist a mangé le pacman)

 */


/*
Problèmes :
 * on affiche pas au bon moment on supprime pas au bon moment

*/

int main(){
	srand(time(NULL));

	//On initialise le field --> ça marche
	int** area = construction_field();


	//on place les éléments --> ça marche
	area = initialize(area);

	//on initialise le pacman (il est déjà placé sur le field mais on déclare ici le struct pour le modifier)
	struct coord coo = {1,1}; //les coordonnées initiales 
	struct pacman pac = {coo, 0, 0, V, 0};

	/*
	affichage(area);
	printf("init : x = %d, y=%d\n",pac.coo.x, pac.coo.y);
	pac = choix(pac); 
	pac = deplace(pac);
	pac = gain(pac, area);
	printf("après : x = %d, y=%d\n",pac.coo.x, pac.coo.y);
	*/

	printf("Pacman initial :\n");
	printf("vies : %d, coord : x = %d y=%d, food = %d\n", pac.lives, pac.coo.x, pac.coo.y, pac.food);

	while(pac.lives != 0 && verif(area) == true){
		

		//fonctions dans jeu.c
		affichage(area);
		area[pac.coo.x][pac.coo.y] = -1; //là où était placé le pacman on met -1
		printf("test");
		affichage(area);
		//ça marche mais ça m'affichage quand même un message d'erreur --> le pacman est bien mis à jour --> dans jeu.c
		pac = choix(pac); 
		pac = deplace(pac);
		pac = gain(pac, area); // update les valeurs du pacman
		area[pac.coo.x][pac.coo.y] = 2; // on update le field
		//il ne sort pas de la boucle dans jeu.c --> il n'affiche pas le field après choix.œ	
		printf("après choix");
		affichage(area);
		
		
		printf("Pacman boucle :\n");
		printf("vies : %d, coord : x = %d x=%d, food = %d\n", pac.lives, pac.coo.x, pac.coo.y, pac.food);


		//on déplace les fantômes


		area[pac.coo.x][pac.coo.y] = -1; //là où était placé le pacman on met -1

	}



}