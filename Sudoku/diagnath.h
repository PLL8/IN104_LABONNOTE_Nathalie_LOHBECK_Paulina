#ifndef __DIAGNATH_H__
#define __DIAGNATH_H__


int** matrice_vierge(int t) ;

void affichage(int t, int** matrice) ;

int aleatoire() ;

bool compar(int k, int* ligne, int l) ;

int* cas(int t, int* ligne) ;

int** carreau(int l);

int** diag(int** matrice, int t) ;

#endif