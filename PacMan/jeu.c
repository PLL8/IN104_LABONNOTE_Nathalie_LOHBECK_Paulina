#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

#include "pac.h"
#include "field.h"

#define H (30) //height
#define W (60) //width
#define G (6) //nombre de fantômes

/* 
A faire : 
 * fonction qui demande au joueur sa direction --> renvoie le struct pacman actualisé
 * si c'est un mur ou un ghost --> -1 de vie et on est placé à la case (1,1) (il faut faire en sorte qu'il n'y ai jamais de ghost là)
 * si c'est une case avec de la nourriture --> +1 nourriture et on déplace
 * si c'est une case sans rien --> on déplace juste
 */

/*codes ASCII de ZQSD
 * z=122
 * q = 113
 * s = 115
 * d = 100
*/


//Fonction de demande au joueur --> ça marche !
struct pacman choix (struct pacman pac){
    //Choix par le joueur
    char c; 
    printf("Choix de votre direction :");
    scanf("%c", &c);
    
    
    while (c!=122 && c!=115 && c!=113 && c!=100){   
	   printf("Vous devez indiqué une direction valide ! Votre choix : \n");
       scanf("%c", &c);
    }
    //une fois qu'on est sortis de cette boucle on sait que le joueur a bien indiqué une direction

    if (c == 122){ //si il tape la touche z
            pac.nx = pac.nx - 1;
    }

    else if(c==115){
            pac.nx = pac.nx + 1;
    }

    else if(c==113){
            pac.ny = pac.ny - 1;
    }

    else if(c==100){
            pac.ny = pac.ny + 1;
    }


    return(pac);

}

//fonction qui prenend en argument un struct pac et qui actualise sa position en fonction de ses directions --> marche
struct pacman deplace(struct pacman pac){

    if (pac.nx == 1){
        pac.coo.x = pac.coo.x + 1; //on actualise la position
        printf("mise à jour x :%d\n", pac.coo.x);
        pac.nx = 0; //on réinitialise la direction
    }

    else if (pac.nx == -1){
        pac.coo.x = pac.coo.x - 1;
        pac.nx = 0;
    }

    else if (pac.ny == 1){
        pac.coo.y = pac.coo.y +1;
        pac.ny = 0;
    }

    else if (pac.ny == -1){
        pac.coo.y = pac.coo.y -1;
        pac.ny = 0;
    }

    return(pac);
}



//fonction qui en fonction du placement du pacman décide de la chose à faire --> normalement ça marche 
struct pacman gain(struct pacman pac, int** field){

    //premier cas : le pacman rencontre soit un mur soit un ghost
    if (field[pac.coo.x][pac.coo.y] == 1 || field[pac.coo.x][pac.coo.y] == 3){
        pac.lives = pac.lives - 1; //on peut potentiellemnt avoir une vie négative --> fin du jeu 
        pac.coo.x = 1;
        pac.coo.y = 1;
    }

    //2ème cas : il rencontre une case avec de la nourriture
    else if (field[pac.coo.x][pac.coo.y] == 0){
        pac.food = pac.food +1;
    }

    return(pac);
}
//on update pas le field ici on le fera dans le main

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


struct ghost* next_ghost(struct ghost* list_ghosts, int** field)
{
    //il faut s'assurer que deux ghosts ne se retrouvent pas sur la meme case, on cree donc une liste avec les positions futures et on s'assure que la position n'est pas déja prise
    int** list_coord=malloc(G*sizeof(int*));
    for(int i=0; i<G; i++)
    {
        list_coord[i]=malloc(2*sizeof(int));
    }
    //on vide toutes les cases de list_coord
    for (int i=0; i<G; i++)
    {
        for (int j=0; j<2; j++)
        {
            list_coord[i][j]=0;
        }
    }

    //on cree le tableau qui contient la position qu'on souhaite evaluer
    int* coord=malloc(2*sizeof(int));

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
    struct coord p0 = {1,1};
    struct pacman pac = {p0,0,0,0,0};
    pac = choix(pac);
    printf("nx, ny = %d, %d\n",pac.nx, pac.ny);

    pac = deplace(pac);
    printf("x, y = %d, %d\n",pac.coo.x, pac.coo.y);
    printf("nx, ny = %d, %d\n",pac.nx, pac.ny);



    int** area = construction_field();
    //printf("sans modif\n");
    //affichage_base(area);


    pac = gain(pac, area);
    printf("x, y = %d, %d\n",pac.coo.x, pac.coo.y);
    printf("nx, ny = %d, %d\n",pac.nx, pac.ny);
    printf("vie, food = %d, %d", pac.lives, pac.food);
    //printf("avec modif\n");
    //affichage_base(area);

}

