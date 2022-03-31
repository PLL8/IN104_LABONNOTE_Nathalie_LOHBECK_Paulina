#include <stdio.h>
#include <stdlib.h>


#define RAND_MAX 8
#define OP_MAX 100


//fonction qui remplie les sousmatrices non diagonales




void rempli_case(int* matrice, int i, int j)
/*
rempli la case i,j de la matrice en testant les lignes, les colones et le carreau (il faut se placer i,j modulo 3 pour trouver le carreau)
*/
{
	int i_carreau=i/3+1;	//on trouve le numero du carreau
	int j_carreau=j/3+1;

	bool rempli=false;	//reste faux tant que la case n'a pas encore été remplie
	bool exist=false;	//variable qui devient true si le chiffre qu'on cherche a place existe déja dans la ligne, colonne ou carreau. 

	if matrice[i][j]!=0
	{
		rempli=true;
	}

	int elem;	//le nombre qu'on teste

	int compt=0; 	//element de comtrole pour etre sur de ne pas boucler

	while (rempli==false)&&(compt<OP_MAX)
	{
		elem=rand()+1;

		for (int k=1; k<10; k++)
		{
			//tester les lignes
			if matrice[i][k]==elem
			{
				exist=true;
			}
			//tester les colonnes
			else if matrice[k][j]==elem
			{
				exist=true;
			}
		}

		//tester le carreau
		for (int k=0; k<3; k++)
		{
			for (int l=0; l<3; l++)
			{
				if matrice[i_carreau+k][j_carreau+l]==elem
				{
					exist=true;
				}
			}
		}


		//on teste si elem convient et si oui, on rempli la case
		if exist==false
		{
			matrice[i][j]=elem;
			rempli=true;
		}

		compt=compt+1;

	}

	if compt==OP_MAX
	{
		printf("Error. Boucle échouée.");
		//break;
	}

}



void sous_matrice(int* matrice, int carreau)
/*
fonction qui prend la grande matrice et se place dans le carreau indiqué 
matrice: 0 1 2 
		 3 4 5
		 6 7 8
puis rempli le sous carreau en examinant les lignes et colones
*/
{
	int line = carreau / 3;
	int colo = carreau % 3;

	for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				rempli_case(matrice, 3*line + i, 3*colo + j);
			}
}



void rempli_matri(int* matrice)
/*
rempli les matrices non diagonales
*/
{
	sous_matrice(matrice, 1);
	sous_matrice(matrice, 2);
	sous_matrice(matrice, 3);
	sous_matrice(matrice, 5);
	sous_matrice(matrice, 6);
	sous_matrice(matrice, 7);
}


