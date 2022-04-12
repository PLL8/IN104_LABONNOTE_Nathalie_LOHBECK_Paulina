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




/*//Fonction intérmédiaire qui retourne true si l'entier est déjà présent dans la liste
bool comparaison(int* liste, int k, int t){
	for (int i = 0; i<t; i++){
		if(liste[i] == k){
			return(true);
		}
	}
	return(false);
}


//Fonction qui remplie aléatoirement une matrice
int** matrce_alea(int t){ //ici t=taille --> 9 cases dans la sous matrices
	int* ligne = malloc(taille*sizeof(int)); 
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
*/

int main (){
	int t = taille;
	int** area = matrice_vierge(t);
	affichage(t, area);

}



