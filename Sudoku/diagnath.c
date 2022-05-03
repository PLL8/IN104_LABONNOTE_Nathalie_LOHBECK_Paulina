#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define taille (9) //on définie la taille de la matrice
#define MAX 9

#include "matrice_init.h"
#include "retire.h"

//fonction random
int aleatoire() {

    return (rand() % MAX + 1);
}


//fonction qui remplie un carreau de taille 3*3 de manière aléatoire


//compare si un entier est dans une liste --> retourne true si c'est dans la liste

bool compar(int k, int* ligne, int l){
	for (int i =0; i<l;i++){
		if(k == ligne[i]){
			return(true);
		}		
	}
	return(false);
}



int* cas(int t, int* ligne){
	int k;
	int i = 0;
	while (i != t ){
		k = aleatoire();
		//printf("k : %d\n", k);
		if(compar(k, ligne, t)==false){ //si k n'est pas dans la liste
			ligne[i] = k;
			i++;
		}
		//printf("i : %d\n", i);
	}
	return(ligne);	

}


//Fonction qui crée un carreau à partir d'une ligne de chiffres aléatoires
int** carreau (int l){ //ligne = ligne de 9 chiffres aléa; l = 9 = taille
	//on crée l'espace pour le carreau et on crée la ligne
	int* ligne = malloc(l*sizeof(int));
	ligne = cas(l, ligne);
	int** carr = malloc((l/3)*sizeof(int*));
	for (int i =0; i<l/3; i++){
		carr[i] = malloc((l/3)*sizeof(int));
	}

	//On remplie le carreau à partir de la ligne
	for (int i = 0; i<l/3; i++){
		carr[0][i] = ligne[i];
		carr[1][i] = ligne[3+i];
		carr[2][i] = ligne[6+i];
	}

		return(carr);
}


//Foncion qui remplie la diag
int ** diag (int** matrice, int t){
	int** carr0 = carreau(t);
	int** carr4 = carreau(t);
	int** carr8 = carreau(t);
	for(int i=0; i<3; i++){
		for (int j =0; j<3; j++){
			matrice[i][j] = carr0[i][j];
			matrice[i+3][j+3] = carr4[i][j];
			matrice[i+6][j+6] = carr8[i][j];
		}
	}
	return(matrice);
}




int main (){
	srand(time(NULL));
	
	int** area = matrice_vierge(taille); 
	area = diag(area, taille);
	affichage(taille, area);
	printf("\n");
	/*int k = 6;
	area = retire(area, k, taille);
	affichage(taille, area);*/

}
