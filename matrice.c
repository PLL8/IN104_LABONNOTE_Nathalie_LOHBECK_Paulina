//fonction qui cree la grande matrice
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int matrice (int t){
	int area [t][t];
	for (int i =0; i<t; i++){
		for (int j = 0; j<t; j++){
			area[i][j] = 0;
		}
	}
	return (area);
}


int main (){
	int t = 6;
	int area[t][t]; 
	area = matrice(t);
	printf("%d", area[2][2]);
}	