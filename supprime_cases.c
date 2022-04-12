#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define taille (9) 

//fonction qui supprmie un certain nombre d éléments de la matrice

//on supprime k éléments sur chaque case (mini matrice)

//focntion random
#define MAX 9

int random() {
    srand(time(NULL));
    printf("%d\n", rand() % MAX + 1);
    return (0);
}


//première fonction qui supprime k éléments dans une ligne donnée --> on remplace par des 0
int supprime(int k, int ligne, int i){ //i = dimension de la ligne
	int c;
	while (k!=0){
		c = random();
		if (ligne[c]!=0){
			ligne[c] = 0;
			k--;
		}
	}
	return(ligne)
}


//fonction qui parcours la matrice
int matrice_trou (int t, int k, int area){ //t = taille de la matrice et k = le nombre de cases à supprimer par ligne
	for (int i = 0; i<t; i++){
		area[i] = supprime(k, area[i], t);
	}
	return(area);
}