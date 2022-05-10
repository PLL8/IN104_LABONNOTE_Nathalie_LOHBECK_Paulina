#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define taille (9)

#include "matrice_init.h"
#include "diagnath.h"
#include "retire.h"
#include "rempl_final.h"
#include "joueur.h"
#include "compare.h"




int main (){
	int taille = 9;
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

	/*int** area = malloc(taille*sizeof(int*));
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
	affichage(taille, area);*/


	//fonction de paupau
	int** area = rempli_matrice();
	
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
	printf("%d\n", matri_pleine(area, taille));
	while (matri_pleine(area, taille)==false){
		area = choix(area, taille);
	}

	//Potentielles rectifications
	int l; //vaut 0 pour non et 1 pour oui

	printf("Le sudoku est plein voulez-vous continer ? Tapez 0 pour non et 1 pour oui\n");
	scanf("%d", &l);
	while (l!=0){
		area = choix(area, taille);
		printf("Le sudoku est plein voulez-vous continer ? \n");
		scanf("%d", &l);
	}


	//le joueur a indiqué qu'il a fini de jouer : il faut maintenant comparer ses résultats
	int* coord = compare(area, corr, taille);
	int c; //choix du nouveau chiffre
	while(coord[0]!=-1 || coord[1] != -1){
		printf("La case située à la ligne %d et la colonne %d est fausse. \n", coord[0]+1, coord[1]+1);
		printf("Choix d'un nouveau chiffre : \n");
		scanf("%d", &c);
		while (c != corr[coord[0]][coord[1]]){
			printf("Ce n'est pas le bon numéro, choix du nouveau :\n");
			scanf("%d ", &c);
		}
		area[coord[0]][coord[1]] = c;
		coord = compare(area, corr, taille); //on avance dans les erreurs
	}

	//Le joueur a finalement la bonne matrice


	printf("Vous avez réussi. La solution est donc :\n");
	affichage(taille, area);


}
