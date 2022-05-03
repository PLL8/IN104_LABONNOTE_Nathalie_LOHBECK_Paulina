//fichier avec fonctions qui font jouer le joueur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



//fonction qui copie la matrice correcte --> cette fonction marche
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

//fonction qui regarde si la matrice est pleine--> cette fonction marche
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
	scanf("Quelle ligne ? %d", &x);
	while (x<1 || x>9){
		printf("Erreur le numéro doit être compris entre 1 et 9\n");
		scanf("Quelle ligne ? %d", &x);
	}

	scanf("Quelle colonne ? %d", &y);
	while (y<1 || y>9){
		printf("Erreur le numéro doit être compris entre 1 et 9\n");
		scanf("Quelle colonne ? %d", &y);
	}

	scanf("Quelle chiffre ? %d", &k);
	while (k<1 || k>9){
		printf("Erreur le numéro doit être compris entre 1 et 9\n");
		scanf("Quelle chiffre ? %d", &k);
	}


	//On remplie la case
	matrice[x-1][y-1] = k;

	return(matrice);


}

