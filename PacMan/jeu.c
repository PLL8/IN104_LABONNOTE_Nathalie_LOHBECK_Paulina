#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

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


//Fonction de demande au joueur
/*struct pacman choix (struct pacman pac){
	int c ;
	printf("Choix de votre direction :");
	scanf("%d", &c);

	//if (c ==)
}*/

int main()