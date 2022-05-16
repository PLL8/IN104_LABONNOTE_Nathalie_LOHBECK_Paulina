#ifndef __DIAGNATH_H__
#define __DIAGNATH_H__

int aleatoire(); //fonction qui renvoie un chiffre aléatoire entre 1 et 9
bool compar(int k, int* ligne, int l); //vérifie si un entier et dans une liste
int* cas (int t, int* ligne); //retourne une ligne composée de chiffres de 1 à 9 aléatoirement répartis
int** carreau (int l); //transforme cette ligne aléatoire en un carreau aléatoire
int** diag (int ** matrice, int t); //place ces carreaux aléatoires sur la diagonale de la matrice globale

#endif
