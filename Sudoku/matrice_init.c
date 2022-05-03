//fonction qui crée la grande matrice
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define taille (9) //on définie la taille de la matrice



//Fonction qui affiche la matrice
void affichage(int t, int** matrice){
	for (int i =0; i<t; i++){
		for (int j =0; j<t; j++){
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}

}

//crée la matrice de 0
int** matrice_vierge (int t){
	int** area = malloc(t*sizeof(int*));
	for (int i = 0; i<t; i++){
		area[i] = malloc(t*sizeof(int));
	}

	for (int i =0; i<t; i++){
		for (int j = 0; j<t; j++){
			area[i][j] = 0;
		}
	}
	return(area);

}




