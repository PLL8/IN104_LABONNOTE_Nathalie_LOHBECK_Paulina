//fonction qui crée la grande matrice
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define taille (9) //on définie la taille de la matrice



//Fonction qui affiche la matrice
void affichage(int t, int** matrice){
	for (int i =0; i<t; i++){
		for (int j =0; j<t; j++){
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}

}

//crée la matrice de 0
int** matrice_vierge (int t){
	int** area = malloc(t*sizeof(int*));
	for (int i = 0; i<t; i++){
		area[i] = malloc(t*sizeof(int));
	}

	for (int i =0; i<t; i++){
		for (int j = 0; j<t; j++){
			area[i][j] = 0;
		}
	}
	return(area);

}



//FONCTION DE PAUPAU DANS DIAG
#define MAX 9
#define OP_MAX 100

int aleatoire() {
    return (rand() % MAX + 1);
}


void rempli_diag_case(int** matrice, int carreau, int i, int j)
/*
rempli la case i,j de la sous.matrice diagonale en testant le carreau
*/
{

	bool rempli=false;	//reste faux tant que la case n'a pas encore été remplie
	bool exist=false;	//variable qui devient true si le chiffre qu'on cherche a place existe déja dans le carreau. 

	if (matrice[carreau + i][carreau + j]!=0)
	{
		rempli=true;
	}

	int elem;	//le nombre qu'on teste

	int compt=0; 	//element de comtrole pour etre sur de ne pas boucler

	while ((rempli==false)&&(compt<OP_MAX))
	{
		elem=aleatoire();

		//tester le carreau
		for (int k=0; k<3; k++)
		{
			for (int l=0; l<3; l++)
			{
				if (matrice[carreau+k][carreau+l]==elem)
				{
					exist=true;
				}
			}
		}


		//on teste si elem convient et si oui, on rempli la case
		if (exist==false)
		{
			matrice[carreau + i][carreau + j]=elem;
			rempli=true;
		}

		compt=compt+1;

	}

	if (compt==OP_MAX)
	{
		printf("Error. Boucle échouée.");
		//break;
	}

}


//	A FAIRE : FONCTION QUI REMPLIE CHAQUE CASE DE CHAQUE CARREAU DIAGONALE


int main (){
	int t = taille;
	int** area = matrice_vierge(t);
	affichage(t, area);

}



