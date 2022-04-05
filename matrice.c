//fonction qui crée la grande matrice
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define taille (9) //on définie la taille de la matrice
#define RAND_MAX  //la valeur maximale renvoyée par int rand ()

void matrice_vierge (int t, int* area){
	for (int i =0; i<t; i++){
		for (int j = 0; j<t; j++){
			area[i][j] = 0;
		}
	}
}


//Fonction intérmédiaire qui retourne true si l'entier est déjà présent dans la liste
bool comparaison(int* liste, int k, int t){
	for (int i = 0; i<t; i++){
		if(liste[i] == k){
			return(true);
		}
	}
	return(false);
}


//Fonction qui remplie aléatoirement une matrice
void matrce_alea(int t, int* ligne){ //ici t=taille --> 9 cases dans la sous matrices
	srand(time(NULL)); //permet d'initialiser pour pouvoir utiliser la fonction rand
	int k;
	int i = 0; //on initialise l'endroit où on se place dans la matrice --> pour l'instant on crée juste une liste que l'on transformera en matrice après
	while (i != t){
		k = rand() +1; //la fonction rand renvoie un chiffre entre 0 et RAND_MAX
		if (comparaison(ligne,k)==false){ //si l'entier n'est pas présent dans la liste
			ligne[i] = k; //on remplie la matrice
			i++;
		}
	}

}


int main (){
	int* ligne = malloc(taille*sizeof(int));
	matrice_alea(taille, ligne);
	printf("%d", ligne[2]);
}	

