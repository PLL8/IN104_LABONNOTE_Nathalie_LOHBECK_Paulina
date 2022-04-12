//TD05 Paulina LOHBECK

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//question 1


int* creer_grille()
{
	int* grille = malloc(sizeof(int)*9);
	/*
	for (int i=0; i<9; ++i)
	{
		grille[i]=0;
	}
	*/
	return grille;
	
}

//question2

void afficher(int* grille)
{
	for (int i=0; i<3; ++i)
	{
		for (int k=0; k<3; ++k)
		{
			if(grille[3*i+k]==2)
			{
				printf("o");
			} else if (grille[3*i+k]==1)
			{
				printf("x");
			} else
			{
				printf(".");
			}
				 
		}
		printf("\n");	
	
	}
	printf("\n");

}


/*

int main ()
{
	int* grille;
	grille = creer_grille();
	afficher(grille);
	free(grille);
	
	return(0);
	
}

*/


//question 3

void test_affichage()
{
		
		int* grille;
		grille = creer_grille();
		afficher(grille);
		// il faut déplacer les indices: 8-1 et 4-1
		grille[3]=1;
		grille[7]=2;
		printf("%d\n", grille[8]);
		afficher(grille);
	
}

/*
int main()
{
	test_affichage();

}

//nous affiche le bon tableau
*/

//question 4

void placer(int* grille, int chiffre, int joueur)
{
	grille[chiffre-1]=joueur;

}

/*

int main()
{
	int joueur=1;
	int* grille;
	grille = creer_grille();
	afficher(grille);
	placer(grille, 5,joueur);
	afficher(grille);
	free(grille);
	
	return(0);
	

}
*/


//question 5

//on écrit une fonction pour tester si il reste des cases libres dans la grille

int tableau_rempli(int* grille)
{
	int reponse = 0;
	for(int i=0; i<9; i++)
	{
		if (grille[i]==0)
		{
			reponse = 1;
		}	
	}
	return reponse;

}

/*

int main ()
{
	int* grille;
	grille = creer_grille();
	for (int i=0; i<9; ++i)
	{
		grille[i]=1;	
	}
	//grille[2]=0;
	afficher(grille);
	printf("%d", tableau_rempli(grille));
	free(grille);
	
	return(0);
	
}

*/



void placer_alea(int* grille, int joueur)
{
	srand(time(0));
	int endroit = rand()%9;
	if (tableau_rempli(grille)==0)
	{
		printf("Le tableau est rempli");
		//il faut rejouter une ligne pour sortir du void	
	}
	
	while(grille[endroit]!=0)
	{
		endroit = rand()%9;
	
	}
	grille[endroit]=joueur;
	
}

/*

int main()
{
	int joueur=2;
	int* grille;
	grille = creer_grille();
	afficher(grille);
	placer_alea(grille, joueur);
	afficher(grille);
	free(grille);
	
	return(0);
}


*/



int a_gagne(int* grille, int joueur)
{
	int gagne=0;
	
	// on teste les lignes:
	
	if (grille[0]==grille[1] && grille[1]==grille[2] && grille[0]==joueur)
	{
		gagne=1;
		return gagne;
	} else if (grille[3]==grille[4] && grille[4]==grille[5] && grille[3]==joueur)
	{
		gagne=1;
		return gagne;
	} 
	else if (grille[6]==grille[7] && grille[7]==grille[8] && grille[6]==joueur)
	{
		gagne=1;
		return gagne;
	} else if (grille[0]==grille[3] && grille[3]==grille[6] && grille[0]==joueur)
	{
		gagne=1;
		return gagne;
	} else if (grille[1]==grille[4] && grille[4]==grille[7] && grille[1]==joueur)
	{
		gagne=1;
		return gagne;
	} else if (grille[2]==grille[5] && grille[5]==grille[8] && grille[2]==joueur)
	{
		gagne=1;
		return gagne;
	} else if (grille[0]==grille[4] && grille[4]==grille[8] && grille[0]==joueur)
	{
		gagne=1;
		return gagne;
	} else if (grille[2]==grille[4] && grille[4]==grille[6] && grille[2]==joueur)
	{
		gagne=1;
		return gagne;
	}
	
	return gagne;
	
}


/*

int main()
{

	int* grille;
	grille = creer_grille();
	afficher(grille);

	grille[2]=1;
	grille[4]=1;
	grille[6]=1;
	afficher(grille);
	printf("%d", a_gagne(grille, 1));
	free(grille);
	
	
	return(0);	

}

*/





int main()
{
	int* grille;
	grille = creer_grille();
	int compteur = 0;
	//on continue de jouer jusqu'a ce que le tableau soit rempli, ce qui assure aussi qu la fonction placer_alea ne "sature" pas
	while (tableau_rempli(grille)!=0 && a_gagne(grille,1)!=1 && a_gagne(grille,2)!=1)
	{
		//le joueuer commence
		printf("Tablau rempli %d\n", tableau_rempli(grille));
		afficher(grille);
		printf("Entrer une valeur\n");
		int entree;
		scanf("%d", &entree);
		//on teste si l'emplacement choisit n'est pas déja pris
		while (grille[entree-1]!=0)
		{
			printf("Emplacement déja pris, entrez nouvelle valeur\n");
			scanf("%d", &entree);
		}
		placer(grille,entree, 1);
		//on teste si le joueur a gagne
		if (a_gagne(grille, 1)==1)
		{
			printf("Le joueur a gagne en %d tours\n", compteur);
			return(0);
		}
		// il faut un nombre impair de tours pour remplir le tableau, donc on le teste ici
		if (tableau_rempli(grille)==0)
		{
			printf("Le match nul en %d tours\n", compteur);
			return(0);
		}
		// puis l'ordinateur joue
		printf("L'ordinateur joue\n");
		placer_alea(grille, 2);
		// on teste si l'ordinateur a gagne
		if (a_gagne(grille, 2)==1)
		{
			printf("L'ordinateur a gagne en %d tours\n", compteur);
			return(0);
		}
		afficher(grille);
		
		
		compteur = compteur +1;
	
		
	}
	free(grille);
	
	return(0);

}


//Remarque: on aurait pu reutiliser la methode du TD3 (Aragorn et Boromir) et definir un pointeur qui pointe vers el joueur pour n'avoir que 1 action dans la boucle while


