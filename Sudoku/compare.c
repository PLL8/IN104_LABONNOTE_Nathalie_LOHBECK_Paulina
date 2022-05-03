#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//cette fonction a été testée elle marche 

int* compare(int** arr, int** corr, int t)
{
	int* coord = malloc(2*sizeof(int)); // liste des coordonnées fausses
	coord[0] = -1;
	coord[1] = -1;
	for (int i=0; i<t; i++)
 	{
 		for (int j=0; j<t; j++)
 		{
 			if (arr[i][j]!=corr[i][j])
 			{
 				coord[0] = i;
 				coord[1] = j;
 				return(coord);
 			}
 		}
 	}
 	return (coord);
}
//return [-1,-1] si les matrices sont identiques. Retourne les coordonnées de la première faute sinon



