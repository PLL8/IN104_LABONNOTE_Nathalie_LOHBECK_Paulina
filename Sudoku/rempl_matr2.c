#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "diagnath.h"
#include "matrice_init.h"


//#define taille (9)
#define MAX 9
//#define OP_MAX 100

int* vide_cas(int* alea, int taille)
{
	for (int i=0; i<taille;  i++)
	{
		alea[i]=0;
	}

	return(alea);
}


int zero_in_line(int**mat, int line)
{ 
	for(int i=0; i<9; i++)
	{
		if (mat[line][i]==0)
			{
				return(1);
			}

	}
	return(0); 
}


int** free_line(int** matrice, int line)
{
	int carreau = line / 3;
	if (carreau==0)
	{
		for (int i=3; i<9; i++)
		{
			matrice[line][i]=0;
		}
	} else if (carreau==1) {
		for (int i=0; i<3; i++)
		{
			matrice[line][i]=0;
		}
		for (int i=6; i<9; i++)
		{
			matrice[line][i]=0;
		}
	}
	else {
		for (int i=0; i<6; i++)
		{
			matrice[line][i]=0;
		}
	}
	return(matrice); 
}



int** rempli_case(int** matrice, int* alea, int i, int j, int taille)
/*
rempli la case i,j de la matrice en testant les lignes, les colones et le carreau (il faut se placer i,j modulo 3 pour trouver le carreau)
*/
{
	int i_carreau=i/3;	//on trouve le numero du carreau
	int j_carreau=j/3;
	bool rempli=false;	//reste faux tant que la case n'a pas encore été remplie
	bool exist=false;	//variable qui devient true si le chiffre qu'on cherche a place existe déja dans la ligne, colonne ou carreau. 

	if (matrice[i][j]!=0)
	{
		rempli=true;
	}
	

	int elem;	//le nombre qu'on teste
	

	int compt=0; 	

	while ((rempli==false)&&(compt<9))
	{
		exist=false;
		elem=alea[compt];

		for (int k=0; k<9; k++)
		{
			//tester les lignes
			if (matrice[i][k]==elem)
			{
				exist=true;
			}
			//tester les colonnes
			else if (matrice[k][j]==elem)
			{
				exist=true;
			}
		}

		//tester le carreau
		for (int k=0; k<3; k++)
		{
			for (int l=0; l<3; l++)
			{	
				if (matrice[3*i_carreau+k][3*j_carreau+l]==elem)
				{
					exist=true;
				}
			}
		}


		//on teste si elem convient et si oui, on rempli la case
		if (exist==false)
		{
			matrice[i][j]=elem;
			rempli=true;
		}

		compt=compt+1;

	}

	if (compt==9)
	{
		printf("Error. Boucle échouée.");
	}
	return matrice; 

}



int** rempli_line(int** matrice, int line, int taille)
{
/*
fonction qui prend la grande matrice et se place dans le carreau indiqué 
matrice: 0 1 2 
		 3 4 5
		 6 7 8
puis rempli le sous carreau en examinant les lignes et colones
*/

	
	int* ligne=malloc(9*sizeof(int));
	printf("avant cas dans sous-matrice\n");
	ligne=vide_cas(ligne, 9);
	int* alea = cas(9, ligne);
	printf("avant boucles sous_matrice, matrice avec zero %d\n", zero_in_line(matrice, line));

	while (zero_in_line(matrice, line)==1)
	{
		matrice=free_line(matrice, line);
		alea = vide_cas(alea, 9);
		alea = cas(9, alea);
		for (int c=0; c<9; c++)
			{  
				matrice=rempli_case(matrice, alea, line, c, taille);
				affichage(9, matrice);
				printf("\n");
			}
	}
	free(ligne);

	printf("fin\n");
	return(matrice);

}



int** rempli_matri(int** matrice, int taille)
/*
rempli les matrices non diagonales
*/
{
	matrice = rempli_line(matrice, 0, taille);
	matrice = rempli_line(matrice, 1, taille);
	matrice = rempli_line(matrice, 2, taille);
	matrice = rempli_line(matrice, 3, taille);
	matrice = rempli_line(matrice, 4, taille);
	matrice = rempli_line(matrice, 5, taille);
	matrice = rempli_line(matrice, 6, taille);
	matrice = rempli_line(matrice, 7, taille);
	matrice = rempli_line(matrice, 8, taille);
	return(matrice);
}




int main(){  
	srand(time(NULL));
	int** matrice=matrice_vierge(9);
	affichage(9, matrice);
	printf("\n");
	matrice=diag(matrice, 9);
	affichage(9, matrice);
	printf("\n");



	printf("main avant sous_matrice\n");

	
	matrice=rempli_line(matrice, 0,9);
	matrice=rempli_line(matrice, 1,9);
	matrice=rempli_line(matrice, 2,9);
	matrice=rempli_line(matrice, 3,9);
	matrice=rempli_line(matrice, 4,9);
	matrice=rempli_line(matrice, 5,9);
	matrice=rempli_line(matrice, 6,9);
	matrice=rempli_line(matrice, 7,9);
	matrice=rempli_line(matrice, 8,9);


	affichage(9, matrice);

}
