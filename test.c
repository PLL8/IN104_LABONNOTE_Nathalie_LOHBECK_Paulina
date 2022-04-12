#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 9


int aleatoire1() {
    srand(time(NULL));
	return(rand() % MAX + 1);
}

int main()
{
	printf("%d\n", aleatoire1());
}