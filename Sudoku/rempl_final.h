#ifndef __REMPL_FINAL_H__
#define __REMPL_FINAL_H__

int* vide_cas(int*alea, int taille);
int zero_in_line(int** mat, int line);
int zero_in_matrix(int** mat, int size);
int ** free_line (int** matrice, int line);
int ** rempli_case(int**matrice, int* alea, int i, int j, int taille);
int rempli_line(int** matrice, int line, int taille, int compteur);
int** rempli_matrice();
#endif