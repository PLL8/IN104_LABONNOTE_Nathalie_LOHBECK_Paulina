#ifndef __REMPL_MATR2_H__
#define __REMPL_MATR2_H__

int* vide_cas(int* alea, int taille);
int zero_in_line (int ** mat, int line);
int** rempli_case(int** matrice, int* alea, int i, int j, int taille);
int ** rempli_line(int** matrice, int line, int taille);
int** rempli_matri (int ** matrice, int taille);


#endif