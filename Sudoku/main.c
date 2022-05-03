#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define taille (3)

#include "matrice_init.h"
#include "diagnath.h"
#include "retire.h"
//#include "rempl_matr2.h"
#include "joueur.h"
#include "compare.h"




int main (){
	int taille =3;
	srand(time(NULL));
	
	/*
	//Matrice initiale
	printf("matrice init\n");
	int** area = matrice_vierge(taille); 
	affichage(taille, area);
	printf("\n");


	//Matrice avec les diag
	printf("matrice diag \n");
	area = diag(area, taille);
	affichage(taille, area);
	printf("\n");

	//Matrice remplie
	printf("matrice remplie\n");
	area = remli_matri(area, taille);
	affichage(taille, area);
	printf("\n");
	*/

	int** area = malloc(taille*sizeof(int*));
	area[0] = malloc(taille*sizeof(int));
	area[1] = malloc(taille*sizeof(int));
	area[2] = malloc(taille*sizeof(int));
	area[0][0] = 1;
	area[0][1] = 2;
	area[0][2] = 3;
	area[1][0] = 4;
	area[1][1] = 5;
	area[1][2] = 6;
	area[2][0] = 7;
	area[2][1] = 8;
	area[2][2] = 9;
	affichage(taille, area);

	//il faut faire une copie de cette matrice pour pouvoir comparer à la fin
	int** corr = copie(area, taille); // fonction mise dans joueur
	affichage(taille, corr);

	//matrice avec des trous
	printf("matrice trouée\n");
	int k = 1; /// nombre de trucs à enlever ar ligne
	area = retire(area, k, taille);
	affichage(taille, area);
	printf("\n");


	//Interactions avec le joueur
	while (matri_pleine(area, taille)==false){
		area = choix(area, taille);
	}

	//Potentielles rectifications
	int l; //vaut 0 pour non et 1 pour oui

	scanf("Le sudoku est plein voulez-vous continer ? %d", &l);
	while (l!=0){
		area = choix(area, taille);
		scanf("Le sudoku est plein voulez-vous continer ? %d", &l);
	}

	//le joueur a indiqué qu'il a fini de jouer : il faut maintenant comparer ses résultats
	int* coord = compare(area, corr, taille);
	int c; //choix du nouveau chiffre
	while(coord[0]!=-1 || coord[1] != -1){
		printf("La case située à la ligne %d et la colonne %d", coord[0], coord[1]);
		scanf("Choix d'un nouveau chiffre : %d", &c);
		while (&c != corr[coord[0], coord[1]]){
			scanf("Ce n'est pas le bon numéro, choix du nouveau :%d ", &c);
		}
		area[coord[0], coord[1]] = &c;
		coord = compare(area, corr, taille); //on avance dans les erreurs
	}

	//Le joueur a finalement la bonne matrice


	printf("La solution est donc :\n");
	affichage(taille, area);


}