#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 9
#define OP_MAX 100


//fonction qui remplie les sousmatrices non diagonales


int aleatoire() {
	return(rand() % MAX + 1);
}

//compare si un entier est dans une liste --> retourne true si c'est dans la liste

bool compar(int k, int* ligne, int l){
	for (int i =0; i<l;i++){
		if(k == ligne[i]){
			return(true);
		}		
	}
	return(false);
}




int* cas(int t, int* ligne){
	int k;
	int i = 0;
	while (i != t ){
		k = aleatoire();
		//printf("k : %d\n", k);
		if(compar(k, ligne, t)==false){ //si k n'est pas dans la liste
			ligne[i] = k;
			i++;
		}
		//printf("i : %d\n", i);
	}
	return(ligne);	

}


void rempli_case(int** matrice, int* alea, int i, int j)
/*
rempli la case i,j de la matrice en testant les lignes, les colones et le carreau (il faut se placer i,j modulo 3 pour trouver le carreau)
*/
{
	int i_carreau=i/3+1;	//on trouve le numero du carreau
	int j_carreau=j/3+1;

	bool rempli=false;	//reste faux tant que la case n'a pas encore été remplie
	bool exist=false;	//variable qui devient true si le chiffre qu'on cherche a place existe déja dans la ligne, colonne ou carreau. 

	if (matrice[i][j]!=0)
	{
		rempli=true;
	}

	int elem;	//le nombre qu'on teste

	int compt=0; 	

	while (exist==true)
	{
		elem=alea[compt];
		print("%d\n", elem);

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
				if (matrice[i_carreau+k][j_carreau+l]==elem)
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

	if (compt==8)
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
	int* ligne=malloc(9*sizeof(int));

	for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				int* alea = cas(9, ligne);
				rempli_case(matrice, alea, 3*line + i, 3*colo + j);
			}
		}
	free(ligne);
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


