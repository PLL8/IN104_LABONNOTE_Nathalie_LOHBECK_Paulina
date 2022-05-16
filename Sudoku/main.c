#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#include "matrice_init.h"
#include "diagnath.h"
#include "retire.h"
#include "rempl_final.h"
#include "joueur.h"
#include "compare.h"




int main (){
	int taille = 9;
	srand(time(NULL)); //on initialise la fonction time pour utiliser la fonction rand

	//fonction qui créée et rempli la matrice
	int** area = rempli_matrice();
	
	//il faut faire une copie de cette matrice pour pouvoir comparer à la fin
	int** corr = copie(area, taille); // fonction mise dans joueur

	//matrice dont on a enlevé k chiffres par ligne
	printf("Matrice trouée\n");
	int k = 6; /// nombre de trucs à enlever ar ligne
	area = retire(area, k, taille); //fonction qui retire k chiffres par ligne
	affichage(taille, area);
	printf("\n");


	//Interactions avec le joueur
	while (matri_pleine(area, taille)==false){ // matri_pleine : renvoie "true" si la matrice est remplie
		area = choix(area, taille);
	}

	//Potentielles rectifications : le joueur peut choisir de continuer à modifier la matrice pour faire des changement avant de la soumettre à correction
	int l; //vaut 0 pour non et 1 pour oui

	printf("Le sudoku est plein voulez-vous continer ? Tapez 0 pour non et 1 pour oui\n");
	scanf("%d", &l);
	while (l!=0){
		area = choix(area, taille);
		printf("Le sudoku est plein voulez-vous continer ? \n");
		scanf("%d", &l);
	}


	//le joueur a indiqué qu'il a fini de jouer : il faut maintenant comparer ses résultats
	int* coord = compare(area, corr, taille); // renvoie [-1 -1] si la matrice est correcte/ renvoie els coordonnées de la première faute sinon
	int c; //choix du nouveau chiffre
	while(coord[0]!=-1 || coord[1] != -1){
		printf("La case située à la ligne %d et la colonne %d est fausse. \n", coord[0]+1, coord[1]+1);
		printf("Choix d'un nouveau chiffre : \n");
		scanf("%d", &c);
		while (c != corr[coord[0]][coord[1]]){ 
			printf("Ce n'est pas le bon numéro, choix du nouveau :\n");
			scanf("%d", &c);
		}
		area[coord[0]][coord[1]] = c;
		coord = compare(area, corr, taille); //on avance dans les erreurs
	}

	//Le joueur a finalement la bonne matrice


	printf("Vous avez réussi. La solution est donc :\n");
	affichage(taille, area);


}
