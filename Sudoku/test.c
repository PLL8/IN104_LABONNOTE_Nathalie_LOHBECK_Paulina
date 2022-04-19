#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 9


int aleatoire1() {
    srand(time(NULL));
	return(rand() % MAX + 1);
}


//fonction random
int aleatoire() {

    return (rand() % MAX + 1);
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
//la fonction compare marche !



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

int main()
{
	printf("%d\n", aleatoire1());
}