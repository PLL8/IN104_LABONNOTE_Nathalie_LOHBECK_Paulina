#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "diagnath.h"
#include "matrice_init.h"




int* vide_cas(int* alea, int taille)
/*
fonction qui vide la ligne qui contient les nombres aléatoires
*/
{
	for (int i=0; i<taille;  i++)
	{
		alea[i]=0;
	}

	return(alea);
}


int zero_in_line(int**mat, int line)
/*
teste si il y a un 0 dans la ligne, c'est a dire que le remplissage n'a pas fonctionné
*/
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

int zero_in_matrix(int** mat, int size)
/*
teste si il y a un 0 dans la matrice, c'est a dire que le remplissage de la matrice n'a pas fonctionné
*/
{
	for(int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			if (mat[i][j]==0)
				{
					return(1);
				}
		}
	}
	return(0); 
}



int** free_line(int** matrice, int line)
/*
libère une ligne de la matrice sans changer les diagonales, si le remplissage n'a pas aboutit pour recommencer le remplissage de la ligne
*/
{
	//on cercher quelles cases il faut laisser inchangé pour les diagonales
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
	

	int compt=0; 	//variable qui nous donne accès aux valeurs de alea

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
	//si aucun élément ne permet de remplir la case, la case reste 0
	return matrice; 

}



int rempli_line(int** matrice, int line, int taille, int compteur)
/*
fonction qui rempli une ligne de la matrice
*/
{
	//on creer notre tableau avec les valeures aléatoires
	int* ligne=malloc(9*sizeof(int));
	ligne=vide_cas(ligne, 9);
	int* alea = cas(9, ligne);
	int compt_rempli=0;

	while (zero_in_line(matrice, line)==1&&compteur<1000)
	/*
	-tant que le remplissage de la ligene n'a pas aboutit, on réinitialise la ligne
	-le compteur assure de sortir de la boucle, si il n'y a pas de solution (ie matrice remplie) pour la matrice proposée en argument
	*/
	{
		matrice=free_line(matrice, line);
		alea = vide_cas(alea, 9);
		alea = cas(9, alea);
		//on remplit case par case de la ligne, si une case n'as pas de solution, elle reste vide
		for (int c=0; c<9; c++)
			{  
				matrice=rempli_case(matrice, alea, line, c, taille);
			}
		compteur=compteur+1;
	}
	free(ligne);
	//on incremente le compteur pour assurer la terminaison de la boucle 
	compteur=compteur+1;

	return(compteur);
}




int rempli_matrice()
/*
fonction qui construit entièrement la matrice
*/
{  
	srand(time(NULL));
	//on crée la matrice diagonale
	int** matrice=matrice_vierge(9);
	matrice=diag(matrice, 9);

	//on initialise nos variables de controle: 
		//le compteur pour sortir des boucles while si il n'y a pas de solution possible
		//la variable rempli pour tester si la matrice ne contient plus de 0, c'est a dire que c'est une matrice solution
	int compteur=0;
	int rempli=1;

	//tant qu'on a pas de solution, on réinitialise notre matrice: 
	while(rempli==1)
	{

		compteur=0;
		matrice=matrice_vierge(9);
		matrice=diag(matrice, 9);
		// on essaie de remplir la matrice diagonale proposée
		//Rq: la valeur 1000 a été choisi apres plusieurs essais pour déterminer en moyenne la valeur du compteur pour aboutir a une solution (~500), qu'on a doublé pour la boucle while
		while (compteur<1000&&rempli==1)
		{
			for (int i=0; i<9; i++)
			{
				compteur=rempli_line(matrice, i,9, compteur);
			}
		}
		
		//on teste si la matrice est solution
		rempli=zero_in_matrix(matrice, 9);
	}

	return mtrice;

}