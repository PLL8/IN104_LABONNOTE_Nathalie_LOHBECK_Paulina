#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Coucou paupau comment vas-tu ?
//ça marche paaaas
//Very well my friend! Et toi?


#define taille (9) //on définie la taille de la matrice
#define RAND_MAX (9) //on définie le chiffre max prie par la variable aléatoire


bool compare (int* liste, int tp, int k){ //fonction qui renvoie vrai si l'élément k est dans la liste 
	for (int i = 0; i<3*tp; i++){
		if (liste[i] == k){
			return(true);
		}
	}
	return(false);
}


int remplissage_3 (int tp){ //on a tp = taille/3
	int areap[tp][tp];
	int* list = malloc(sizeof(int)*(tp*3)); //on crée une liste qui contient les chiffres que l'on a déjà attribué pour ne pas les répéter
	int k; 
	for (int i = 0; i<tp; i++){
		for (int j= 0; j<tp; j++){
			k = rand();
			if (compare(list,tp,k) == true){
			areap[i][j] = rand();
		}
	}

}

int matrice (int t){
	//On crée d'abord la matrice vierge
	int area[t][t];
	for (int i = 0; i<t; i++){
		for (int j = 0; j<t; j++){
			area[i][j] = 0;
		}
	}

	//on remplie maintenant la matrice

	//On remplie d'abord les matrices diagonales
	for (int k1 = 0; k1<3; k1++){
		for (int k2=0; k2<3; k2++){

		}
	}
	
}

	



int main(){




}