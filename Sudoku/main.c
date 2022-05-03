#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define taille (9)

#include "matrice_init.h"
#include "diagnath.h"
#include "retire.h"



int main (){
	srand(time(NULL));
	
	int** area = matrice_vierge(taille); 
	area = diag(area, taille);
	affichage(taille, area);
	printf("\n");
	int k = 6;
	area = retire(area, k, taille);
	affichage(taille, area);

}