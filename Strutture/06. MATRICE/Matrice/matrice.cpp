#include "matrice.h" // inclusione della definizione del tipo matrice
#include <iostream>
#include <stdlib.h>     /* srand, rand */

// costruttore
matrice::matrice(int r, int c){
  colonne = c;
  righe = r;
  // allocazione dinamica della matrice


	/*              ---------
		elementi ---> | e[0]   | --> [ e[0][0], e[0][1], ..., e[0][c-1]]
		              | e[1]   | --> [ e[1][0], e[1][1], ..., e[1][c-1]]

									 .......

									| e[r-1] | --> [ e[r-1][0], e[r-1][1], ..., e[r-1][c-1]]
									---------
		
			dove ei Ã¨ di tipo puntatore a tipoelem, e eij Ã¨ di tipo tipoelem
			Inoltre, ei = elementi[i] e eij = elementi[i][j]
	 */

  int i,j;
	// allocazione del vettore di puntatori a tipoelem
  elementi = new tipoelem* [righe]; //Assegno ad elementi l'indirizzo di un array di dimensione righe
  for (i=0; i < righe; i++)
		// allocazione dei singoli vettori righe di elementi di tipo tipoelem
    elementi[i] = new tipoelem[colonne]; //assegno l'elemento di tipo array con il numero di colonne definite
  // inizializzazione degli elementi a valore nullo
  for (i=0;i<righe;i++)
		for (j=0;j<colonne;j++)
			elementi[i][j]=0; //inizializzazione della matrice nulla
}

// costruttore di copia
// lo stato della variabile al quale sto applicando lo stato di copia è proprio lo stato iniziale
//In quello di assegnamento, devo distruggere lo stato dell'oggetto e ricrearne uno nuovo
matrice::matrice(const matrice &m){
	righe = m.righe;
	colonne = m.colonne;
  int i,j;
  elementi = new tipoelem* [righe];  //Alloco gli array dinamicamente
  for (i=0; i < righe; i++)
    elementi[i] = new tipoelem[colonne];
  for (i=0;i<righe;i++)
		for (j=0;j<colonne;j++)
			elementi[i][j]=m.elementi[i][j]; //inserisco nella cella il valore memorizzato nella matrice m
	
}

matrice::~matrice(){ //prima distrugge lo stato precedente (POSSO NON FARLO SE LE DIMENSIONI SONO LE STESSE)
	for (int j=0; j<colonne; j++)
		delete[] elementi[j]; //dealloco prima tutti gli array delle colonne
	delete [] elementi; //dealloco l'array contenente i riferimenti alle colonne
}

matrice &matrice::operator=(const matrice &m){
	// evita gli auto assegnamenti - CONTROLLO CHE NON STO SCRIVENDO A=A (quindi l'indirizzo di m non sia this)
	if (this == &m) return *this;
	else {
		int i,j;
		if (colonne != m.colonne || righe != m.righe){
			this->~matrice(); //dealloco, ricreando un nuovo stato solo se le dimensioni della precedente sono diverse dalle nuove
			colonne = m.colonne;
			righe = m.righe;
			elementi = new tipoelem* [righe]; 
			for (i=0; i < righe; i++)
				elementi[i] = new tipoelem[colonne]; //copio i valori di m nella matrice appena allocato
		}
		for (i=0;i<righe;i++)
			for (j=0;j<colonne;j++)
				elementi[i][j] = m.elementi[i][j];
	}
	return *this;
}

tipoelem matrice::leggimatrice(int r, int c){
	return elementi[r][c];
}

void matrice::scrivimatrice(int r, int c, tipoelem e){
	elementi[r][c] = e;
}

void matrice::prodottoScalare(double c){
	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			elementi[i][j] = c * elementi[i][j];
}

matrice matrice::trasposta(){
	matrice T(colonne,righe);

	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			T.scrivimatrice(j,i, elementi[i][j]);
	return T; // Attenzione è errato se non si implementa il sovraccarico di operator=
}

void matrice::stampa(){ //può essere anche il sovracccarico di <<
	std::cout << std::endl;
	for (int i=0; i<righe; i++){
		std::cout << std::endl;		
		for (int j=0; j<colonne; j++)
			std::cout << elementi[i][j] << " ";
	}
	std::cout << std::endl;
}

void matrice::rand2(){
	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			elementi[i][j] = rand() % 100;
}

