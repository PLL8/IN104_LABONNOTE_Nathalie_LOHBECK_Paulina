#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

#include "pac.h"
#include "field.h"

#define H (30) //height
#define W (60) //width
#define G (6) //nombre de fantômes

//fonction pour tester si un element est dans un tableau 2*G (utiliser pour ne pas mettre deux ghosts dans la meme case)

int in_list(int** list_coord, int* coord)
{
    int x=coord[0];
    int y=coord[1];
    for(int i=0; i<G; i++)
    {
        if(list_coord[i][0]==x && list_coord[i][1]==y)
        {
            return 1;
        }
    }

    return 0;
}


struct ghost* next_ghost(struct ghost* list_ghosts, int** field, int** list_coord)
{
    printf("dans next_ghost\n"); 
    //il faut s'assurer que deux ghosts ne se retrouvent pas sur la meme case, on cree donc une liste avec les positions futures et on s'assure que la position n'est pas déja prise
    /*
    int** list_coord=malloc(G*sizeof(int*));
    printf("list_coord malloc\n");
    for(int i=0; i<G; i++)
    {
        list_coord[i]=malloc(2*sizeof(int));
        printf("list_coord %d\n", i); 
    }
    */

    //on vide toutes les cases de list_coord
    for (int i=0; i<G; i++)
    {
        for (int j=0; j<2; j++)
        {
            list_coord[i][j]=0;
        }
    }
    printf("vide reussi\n");

    //on cree le tableau qui contient la position qu'on souhaite evaluer
    int* coord=malloc(2*sizeof(int));
    printf("coord malloc\n");

    //pour chaque ghost on trouve une nouvelle position
    for (int i=0; i<G; i++)
    {
        //on accede au ghost
        struct ghost gho=list_ghosts[i];
        //on prend un chiffre de manière aléatoire, si il es pair, on deplace suivant x, sinon suivant y et si il est divisible par 4 on increment la position, sinon on la diminue
        int test = rand();
        int test2=test/2; 
        //on introduit le boolen pour tester si la case est une position possible
        bool vide=false;
        //les coefficients des positions futures
        int gx=0;
        int gy=0;

        int compteur=0; 

        //tant que on ne trouve pas de case/position possible, on boucle, si on ne trouve pas de position possible pour le ghost, il reste imobil pour ce tour
        while (vide==false && compteur<100)
        {
            int x = gho.goo.x;
            int y = gho.goo.y;
            //on trouve la nouvelle direction de maniere aleatoire
            if (test%2==0)
            {
                if (test2%2==0)
                {
                    x=x+1;
                    gx=1;
                }
                else {
                    x=x-1;
                    gx=-1;
                }
            } else
            {
                if (test2%2==0)
                {
                    y=y+1;
                    gy=1;
                }
                else {
                    y=y-1;
                    gy=-1;
                }
            }

            //on update le vecteur position
            coord[0]=x;
            coord[1]=y;

            //on teste si la position est admissible (elle est n'est pas un mur, ni une position future (on suppose que la position est occupee par un ghost, celui va bouger))
            if (field[x][y]!=1)
            {
                if (in_list(list_coord, coord)==0)
                {   
                    //on termine la boucle
                    vide=true;
                    //on rajoute la position future dans la liste des coordonnees
                    list_coord[i]=coord;
                    //on update la direction du ghost
                    list_ghosts[i].gx=gx;
                    list_ghosts[i].gy=gy;
                }
            }

            //on incremente le compteur pour s'assurer de la terminaison
            compteur=compteur+1;
        }
    }
    //on libere coord
    free(coord);

    return(list_ghosts); 
}



int main(){
    

    int** area = construction_field();
    
    //TEST GHOSTS
    printf("Test pour les ghosts\n");
    struct ghost* list_ghost = malloc(G*sizeof(struct ghost));
    printf("Jeu à l'instant initial\n");
    area = initialize(area, list_ghost);
    //affichage(area);
    //affichage_ghost(list_ghost[4]);

    //test next_ghost
    printf("before in main malloc list_coord\n");

    int* test=malloc(G*sizeof(int));
    printf("allocation ok\n");
    free(test);
    
    /*
    int** list_coord=malloc(2*sizeof(int*));
  
    printf("list_coord malloc\n");
    for(int i=0; i<G; i++)
    {
        list_coord[i]=malloc(2*sizeof(int));
        printf("list_coord %d\n", i); 
    }
    list_ghost= next_ghost(list_ghost, area, list_coord); 
    */


    free(list_ghost); 
}


