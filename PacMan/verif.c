#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

#define H (30) //height
#define W (60) //width
#define G (6) //nombre de fantômes

//Dans cette fonction on va vérifier si il reste de la nourriture

bool verif (int** field){
	for (int i = 0; i<H; i++){
		for (int j = 0; j<W; j++){
			if(field[i][j] == 0){
				return(true);
			}
		}
	}
	return(false);
}