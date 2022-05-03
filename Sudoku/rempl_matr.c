#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "diagnath.h"

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


int zero_in_sub_matr(int**mat, int carreau)
{
	int result=0; 
	int line = carreau / 3;
	int colo = carreau % 3;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if (mat[3*line+i][3*colo+j]==0)
			{
				result=1;
			}
		}
	}
	return(result); 
}


int** free_carreau(int** matrice, int carreau)
{
	int line = carreau / 3;
	int colo = carreau % 3;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			matrice[3*line+i][3*colo+j]=0;
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



int** sous_matrice(int** matrice, int carreau, int taille)
{
/*
fonction qui prend la grande matrice et se place dans le carreau indiqué 
matrice: 0 1 2 
		 3 4 5
		 6 7 8
puis rempli le sous carreau en examinant les lignes et colones
*/

	printf("on teste le carreau %d dans sous_matrice\n", carreau);
	int line = carreau / 3;
	int colo = carreau % 3;
	int* ligne=malloc(9*sizeof(int));
	int** matrice_old=matrice;
	printf("avant cas dans sous-matrice\n");
	ligne=vide_cas(ligne, 9);
	int* alea = cas(9, ligne);
	printf("après cas ligne dans sous_matrice\n");
	printf("avant boucles sous_matrice, matrice avec zero %d\n", zero_in_sub_matr(matrice, carreau));

	while (zero_in_sub_matr(matrice, carreau)==1)
	{
		matrice=free_carreau(matrice, carreau);
		alea = vide_cas(alea, 9);
				alea = cas(9, alea);
		for (int i=0; i<3; i++)
			{  
				for (int j=0; j<3; j++)
				{
					matrice=rempli_case(matrice, alea, 3*line + i, 3*colo + j, taille);
					printf("zero dans matrice apres le remplissage %d\n",zero_in_sub_matr(matrice, carreau));
					affichage(9, matrice);
					printf("\n");
			}
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
	matrice = sous_matrice(matrice, 1, taille);
	matrice = sous_matrice(matrice, 2, taille);
	matrice = sous_matrice(matrice, 3, taille);
	matrice = sous_matrice(matrice, 5, taille);
	matrice = sous_matrice(matrice, 6, taille);
	matrice = sous_matrice(matrice, 7, taille);
	matrice = sous_matrice(matrice, 8, taille);

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

	//matrice = sous_matrice(matrice, 3, 9);
	//matrice = sous_matrice(matrice, 5, 9);
	//matrice = sous_matrice(matrice, 6, 9);
	rempli_matri(matrice, 9);
	printf("0 in matrice %d\n", zero_in_sub_matr(matrice, 0));
	affichage(9, matrice);
	/*
	int* ligne=malloc(9*sizeof(int));
	int* alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 0 , 3 , 9);
	affichage(9, matrice);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 0 , 4 , 9);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 0 , 5 , 9);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 1 , 3 , 9);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 1 , 4 , 9);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 1 , 5 , 9);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 2 , 3 , 9);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 2 , 4 , 9);
	alea=vide_cas(alea, 9);
	alea = cas(9, ligne);
	matrice=rempli_case(matrice, alea, 2 , 5 , 9);
*/	

	//matrice=rempli_matri(matrice, 9); 
	
}