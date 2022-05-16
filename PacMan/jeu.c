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



/*
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

}*/

