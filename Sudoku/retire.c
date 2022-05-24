#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//fonction qui retire un nombre k de cases dans chaque ligne de la matrice

#include "diagnath.h"


int* retire_ligne (int* ligne, int k, int t){
	//t = longueur de la ligne
	//k = nombre de cases à retirer

	int i = 0;
	int a;

	while (i != k){
		a = aleatoire();
		if (ligne[a] != 0){
			ligne[a] = 0;
			i++;
		}
		
	}

	return(ligne);

}


int** retire(int** matrice, int k, int t){
	//k = nombre de cases à retirer dans la ligne
	//t = taille de la matrice = longueur de la ligne

	for (int i = 0; i<t; i++){
		matrice[i] = retire_ligne(matrice[i], k, t);
	}

	return(matrice);

}

/*int main(){
	srand(time(NULL));
	int taille = 9;
	int k = 6;
	int** mat = rempli_matrice();
	affichage(taille, mat);
	mat = retire(mat,k,taille);
	printf("nouvelle\n");
	affichage(taille, mat);
}*/




