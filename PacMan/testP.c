#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>


int in_list(int** list_coord, int* coord, int G)
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


int main()
{
    int** list_coord=malloc(2*sizeof(int*));
    //printf("allocation ok\n");
    for(int i=0; i<2; i++)
    {
        list_coord[i]=malloc(2*sizeof(int));
        //printf("allocation line ok\n");
    }
    
    list_coord[0][0]=1;
    list_coord[0][1]=2;
    list_coord[1][0]=3;
    list_coord[1][1]=4;

    int* coord=malloc(2*sizeof(int));
    coord[0]=1;
    coord[1]=4;

    printf("in list %d\n", in_list(list_coord, [1,2], 2));

    return 0;

}