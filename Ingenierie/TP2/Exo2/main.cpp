#include <iostream>

using namespace std;

void affiche_vecteur(int * vecteur, int dimension);
void affiche_matrice(int ** matrice, int lignes, int colonnes);
int * alloue_vecteur(int dimension, int val);
int ** alloue_matrice(int lignes, int colonnes, int val);
int ** genere_matrice_identite(int dimension);
void libere_vecteur(int * vecteur);
void libere_matrice(int ** matrice,int lignes);


int main(){

     int * vecteur = alloue_vecteur(6,1);
     int ** matrice = alloue_matrice(2,2,5);

      affiche_matrice(matrice,2,2);
      affiche_vecteur(vecteur,6);

	return 0;

}

void affiche_vecteur(int *vecteur, int dimension) {

    int i=0;

    for(i=0;i<dimension;i++)
    {
       cout << "valeur " << i << ": " << vecteur[i] << endl;
    }
}

void affiche_matrice(int **matrice, int lignes, int colonnes) {

	int i=0,j=0;

	for(i=0;i<lignes;i++)
	{
		for(j=0;j<colonnes;j++)
		{
			cout << "valeur (" << i << "," << j << "): " << matrice[i][j] << endl;
		}
	}
}

int * alloue_vecteur(int dimension, int val) {

     int i=0;
     int *vecteur = new int[dimension];

       for(i=0;i<dimension;i++)
       {
           vecteur[i] = val;
       }
    return vecteur;
}

int ** alloue_matrice(int lignes, int colonnes, int val) {

	 int i=0,j=0;
	 int ** matrice = new int*[lignes];

	  for(i=0;i<lignes;i++) {

	  	 matrice[i] = new int[colonnes];

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

     delete[] vecteur;
}

void libere_matrice(int ** matrice,int lignes) {

	 int i=0;

	 delete[] matrice;

	  for(i=0;i<lignes;i++) {

	  	 delete matrice[i];

	  }
}
