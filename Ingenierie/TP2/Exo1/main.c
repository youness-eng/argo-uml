#include <stdio.h>
#include <stdlib.h>

void affiche_vecteur(int *vecteur, int dimension);
void affiche_matrice(int **matrice, int lignes, int colonnes);
int * alloue_vecteur(int dimension, int val);
int ** alloue_matrice(int lignes, int colonnes, int val);
int ** genere_matrice_identite(int dimension);
void libere_matrice(int ** matrice, int lignes);
void libere_vecteur(int * vecteur);

main(){

	int i=0;
    int *vect = alloue_vecteur(6,2);
    int **matrice = alloue_matrice(4,2,1);
    int **mat_identite = genere_matrice_identite(2);

	    affiche_vecteur(vect,6);
		affiche_matrice(matrice,4,2);
		printf("\n");
		affiche_matrice(mat_identite,5,5);
		libere_vecteur(vect);
		libere_matrice(matrice,4);
		libere_matrice(mat_identite,5);

	return 0;

}

void affiche_vecteur(int *vecteur, int dimension) {

    int i=0;

    for(i=0;i<dimension;i++)
    {
       printf("valeur %d: %d \n",i,*(vecteur+i));
    }
}

void affiche_matrice(int **matrice, int lignes, int colonnes) {

	int i=0,j=0;

	for(i=0;i<lignes;i++)
	{
		    printf("(");
		for(j=0;j<colonnes;j++)
		{
			printf("%d ",i,j,matrice[i][j]);
		}
		    printf(")\n");
	}
}

int * alloue_vecteur(int dimension, int val) {

     int i=0;
     int *vecteur = malloc(dimension*(sizeof(int)));

       for(i=0;i<dimension;i++)
       {
           vecteur[i] = val;
       }
    return vecteur;
}

int ** alloue_matrice(int lignes, int colonnes, int val) {

	 int i=0,j=0;
	 int ** matrice = malloc(lignes*(sizeof(int*)));

	  for(i=0;i<lignes;i++) {

	  	 matrice[i] = malloc(colonnes*(sizeof(int)));

	  }

	  for(i=0;i<lignes;i++) {

	  	 for(j=0;j<colonnes;j++) {

	  	 	matrice[i][j] = val;

		   }
	  }
	        return matrice;
}

int ** genere_matrice_identite(int dimension) {

	 int i=0;
	 int ** matrice = alloue_matrice(dimension,dimension,0);

	  for(i=0;i<dimension;i++) {

	  	 matrice[i][i] = 1;
	  }
	     return matrice;
}

void libere_vecteur(int * vecteur) {

     free(vecteur);
}

void libere_matrice(int ** matrice,int lignes) {

	 int i=0;

	 free(matrice);

	  for(i=0;i<lignes;i++) {

	  	 free(matrice[i]);

	  }
}
