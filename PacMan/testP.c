#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

#define H (30) //height
#define W (60) //width
#define G (10) //nombre de fantômes
#define V (3)  //nombre de vies

//#include "pac.h"
#include "field.h"



struct coord {
    int x;
    int y;
};


struct pacman{
    struct coord coo; //coordonnées du pacman
    int nx; //direction de déplacement vertical
    int ny; //direction de déplacement horizontal
    int lives;
    int food;
};

struct ghost {
    struct coord goo;
    int gx; 
    int gy; 
};


void affichage_ghost (struct ghost gho)
{
    printf("coordonées (%d, %d)\n", gho.goo.x, gho.goo.y);
    printf("directions nx=%d, ny=%d\n", gho.gx, gho.gy);
}


int main()
{
    srand(time(NULL));

    //struct ghost* list_ghost = malloc(G*sizeof(struct ghost));
    //printf("Test pour les ghosts\n");

    /*
    int** list_coord=malloc(G*sizeof(int*));
    printf("list_coord malloc\n");
    for(int i=0; i<G; i++)
    {
        list_coord[i]=malloc(2*sizeof(int));
        printf("list_coord %d\n", i); 
    }

    list_coord[0][0]=1;
    list_coord[0][1]=2;
    list_coord[1][0]=3;
    list_coord[1][1]=4;

    int* coord=malloc(2*sizeof(int));
    coord[0]=1;
    coord[1]=4;

    free(list_coord);
    free(coord);
    */
    //free(list_ghost);


    int** area = malloc(H*sizeof(int*));

    
    for (int i = 0; i<H; i++){
        area[i] = malloc(W*sizeof(int));
        for (int j =0; j<W;j++){
            area[i][j]=0;
        }
    }
    
    area = construction_field();
    affichage(area);
    

    printf("%d\n", area[0][1]);
    printf("%d\n", area[25][30]);
    
    for (int i = 0; i<H; i++){
        free(area[i]);
    }
    free(area);
    

/*
    struct ghost* list_ghost = malloc(G*sizeof(struct ghost));
    
    for (int i=0; i<G; i++)
    {
        list_ghost[i].goo.x=0;
        list_ghost[i].goo.y=0;
        list_ghost[i].gx=0;
        list_ghost[i].gy=0;
        affichage_ghost(list_ghost[i]);
    }

    free(list_ghost);
    */

    return 0;

}