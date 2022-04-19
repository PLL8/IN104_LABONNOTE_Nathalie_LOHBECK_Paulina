#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define taille (9) //on définie la taille de la matrice
#define MAX 9



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
//la fonction compare marche !



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


void affichage(int* ligne, int t){
	for (int i=0; i<t; i++){
		printf("%d", ligne[i]);
	}
}

int** carreau (int* ligne, int l){ //ligne = ligne de 9 chiffres aléa; l = 9 = taille
	int** carr = malloc(l/3*sizeof(int*));
	for (int i = 0; i<l/3; i++){
		carr[1][i] = ligne[i];
	}
	for (int i = 0; i<l/3; i++){
		carr[2][i] = ligne[3+i];
	}
}

int main (){
	srand(time(NULL));
	int* ligne = malloc(taille*sizeof(int));
	for (int i =0; i<taille; i++){
		ligne[i] =0;
	}

	printf("%d\n", compar(1, ligne, taille));

	printf("ligne initiale");
	affichage(ligne, taille);
	printf("\n");


	ligne = cas(taille, ligne);
	printf("ligne finale");
	affichage(ligne, taille);
	printf("\n");

}