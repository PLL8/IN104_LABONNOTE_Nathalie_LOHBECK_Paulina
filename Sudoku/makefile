

end_file: main.c compare.c matrice_init.c joueur.c diagnath.c rempl_final.c retire.c
	gcc -o end_file  main.c compare.c matrice_init.c joueur.c diagnath.c rempl_final.c retire.c

main.o: main.c compare.c matrice_init.c joueur.c diagnath.c rempl_final.c retire.c
	gcc -o main.o compare.c matrice_init.c joueur.c diagnath.c rempl_final.c retire.c

joueur.o: joueur.c matrice_init.c
	gcc -o joueur.o matrice_init.c

rempl_final.o: rempl_final.c diagnath.c matrice_init.c
	gcc -o rempl_final.o diagnath.c matrice_init.c

retire.o: retire.c diagnath.c
	gcc -o retire.o diagnath.c


	