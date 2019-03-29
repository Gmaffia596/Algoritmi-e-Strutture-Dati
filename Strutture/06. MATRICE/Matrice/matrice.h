#ifndef MATRICE_H
#define MATRICE_H

typedef double tipoelem;

class matrice {
 public:
	matrice(int, int); // costruttore
	~matrice();
	matrice(const matrice &);
	matrice & operator=(const matrice &);
	tipoelem leggimatrice(int, int);
	void scrivimatrice(int, int, tipoelem);
	void prodottoScalare(double); //modifica l'oggetto stesso
	matrice trasposta(); //restituisce una matrice, all'interno dichiarer� una variabile di tipo matrice, ne effettuer� la trasposta e la restituir�. Potremi renderlo pi� efficiente implementando il costruttore di copia (reference all'oggetto dello stesso tipo) ma anche il costrure di spostamento (avendo una variabile temporanea)
	void stampa();
	void rand2();
 private:
	int righe;
	int colonne;
	/* dato che non sappiamo a priori il numero di righe e colonne, ci sar� un vettore di puntatori di tipoelem, che verranno allocati dinamicamente */
	tipoelem **elementi;
						
};

#endif
