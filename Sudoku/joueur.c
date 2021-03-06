//fichier avec fonctions qui font jouer le joueur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrice_init.h"



//fonction qui copie la matrice correcte
int** copie (int** matrice, int t){
	int** corr = malloc(t*sizeof(int *));
	for (int i=0; i<t; i++){
		corr[i] = malloc(t*sizeof(int));
		for(int j = 0; j<t; j++){
			corr[i][j] = matrice [i][j];
		}
	}
	return(corr);
}

//fonction qui regarde si la matrice est pleine
bool matri_pleine (int** matrice, int t){
	for (int i =0; i<t; i++){
		for (int j=0; j<t; j++){
			if (matrice[i][j] == 0){ //la matrice n'est pas pleine
				return(false);
			}
		}
	}

	return(true);
}



int** choix (int** matrice, int t){
	int x; //num de ligne
	int y; //num de colonne
	int k; //chiffre dans la case


	//choix de la case et du chiffre dans la case
	printf("Quelle ligne ?\n");
	scanf("%d", &x);
	while (x<1 || x>9){
		printf("Erreur le numéro doit être compris entre 1 et 9\n");
		printf("Quelle ligne ?\n");
		scanf("%d", &x);
	}

	printf("Quelle colonne ?\n");
	scanf("%d", &y);
	while (y<1 || y>9){
		printf("Erreur le numéro doit être compris entre 1 et 9\n");
		printf("Quelle colonne ?\n");
		scanf("%d", &y);
	}


	printf("Quel chiffre ?\n");
	scanf("%d", &k);
	while (k<1 || k>9){
		printf("Erreur le numéro doit être compris entre 1 et 9\n");
		printf("Quel chiffre ?\n");
		scanf("%d", &k);
	}
	

	matrice[x-1][y-1] = k;
	
	affichage(t, matrice);
	
	return(matrice);


}

