#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool compare(int** arr, int** corr)
{
	bool correct=true;
	for (int i=0; i<9; i++)
 	{
 		for (int j=0; j<9; j++)
 		{
 			if (arr[i][j]!=corr[i][j])
 			{
 				correct=false;
 			}
 		}
 	}
 	return correct;
}

