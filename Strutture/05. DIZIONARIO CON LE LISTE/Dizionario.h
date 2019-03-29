#ifndef DIZ_H
#define DIZ_H
#include <iostream>
#include "Hash.h"
#include "listap.h"
#include "Entry.h"

template<typename K, typename E> class Dizionario //DEFINIZIONE DELLA CLASSE
{
// E=tipo elemento, K=tipo chiave
typedef Entry<K,E> entry;

	public:
		Dizionario(unsigned int); // costruttore
		~Dizionario(); // distruttore
		//METODI PUBLIC
		bool vuoto(); // restituisce true se il dizionario è vuoto
		bool appartiene(const K& ); // restituisce true se l'elemento appartiene al dizionario
		E recupera(const K&); // restituisce l'elemento corrispondente alla chiave (se esiste)
		void inserisci(const K&, const E&); // inserisce un elemento nel dizionario
		void cancella(const K&); // elimina l'elemento di chiave K dal dizionario
		unsigned int dimensione(); // restituisce il numero elementi del dizionario
		void stampa();

	private:
		unsigned int H(const K&); // calcola il valore hash dell'elemento object - FUNZIONE HASH
		unsigned int lunghezza; // lunghezza massima del dizionario
		unsigned int nelementi; // elementi presenti in un certo istante presenti nel dizionario
		circLista< Entry <K,E> >* table; // liste di trabocco per le entry
};

template <typename K, typename E> Dizionario<K,E>::Dizionario(unsigned int n) //COSTRUTTORE DEL DIZIONARIO
{
lunghezza = n; //Lunghezza stabilita del dizionario
nelementi = 0; //inizializzazione del numero di elementi presenti
table = new circLista< entry >[lunghezza]; //istanzio una nuova lista circolare di lunghezza in base al parametro definito
}

template <typename K, typename E> Dizionario<K,E>::~Dizionario() //DISTRUTTORE
{
	delete[] table; //dealloco la tabella
}

template<typename K, typename E> bool Dizionario<K,E>::vuoto()
{
	return (nelementi == 0); //se il dizionario è vuoto, ritorno true, altrimenti false
};

template<typename K, typename E> bool Dizionario<K,E>::appartiene(const K& key)
{
	Cella<entry>* iter; //creo un puntatore alla cella
	bool trovato = false; //inizializzo il boolean trovato
	unsigned int pos = H(key); //inizializzo la posizione al valore di ritorno della funzione di HASH
	iter = table[pos].primoLista(); //inizializzo il puntatore al primo elemento della lista
	while (!table[pos].finelista(iter) && !trovato) //ciclo fino a quando non arrivo alla fine della lista o non l'ho trovato
	{
		if (key == table[pos].leggilista(iter).getKey()) //se la chiave presa in input = alla chiave in posizione pos
			trovato = true; //pongo trovato = true
		iter = table[pos].succlista(iter); //incremento il puntatore al successivo elemento della lista
	}
	return(trovato); //ritorno l'esito della ricerca
};

template<typename K, typename E> E Dizionario<K,E>::recupera(const K& key) //restituisce l'elemento corrispondente alla chiave (se esiste)
{
	Cella <entry>* iter; //dichiaro il puntatore di iterazione della struttura
	bool trovato = false; //setto il flag booleano a false
	E elem; //creo un oggetto elemento di tipo E
	unsigned int pos = H(key); //prendo la posizione rispetto al valore ritornato dalla funzione HASH calcolata sulla chiave
	iter = table[pos].primoLista(); //setto il puntatore al primo elemento della lista
	while (!table[pos].finelista(iter) && !trovato) //ciclo fino a quando non arrivo alla fine della lista o non l'ho trovato
	{
		if (key == table[pos].leggilista(iter).getKey()) //se la chiave presa in input = alla chiave in posizione pos
			{ 
			   trovato = true; //pongo trovato = true
			   elem=table[pos].leggilista(iter).getValue(); //setto il valore dell'elemento in base al valore presente in tale posizione
			}
		iter = table[pos].succlista(iter); //incremento il puntatore al successivo elemento della lista
	}
	return(elem); //ritorno l'elemento avvalorato
};

template<typename K, typename E> void Dizionario<K,E>::inserisci(const K& chiave, const E& element)
{
	entry e(chiave,element); //creo una nuova coppia, in base ai valori forniti in input
	Cella <entry>* posizione=table[H(chiave)].primoLista();		//creo un puntatore alla cella, la cui posizione è data dalla funzione HASH calcolata sulla chiave e punta al primo elemento della lista contenuto in questa posizione
	table[H(chiave)].inslista(e,posizione);			//inserisco la coppia nella posizione della lista definita precedentemente
	nelementi++; //incremento il numero di elementi presenti nel dizionario
};

template<typename K, typename E> void Dizionario<K,E>::cancella(const K& chiave)
{
	Cella <entry>* iter; //creo un puntatore alla cella
	bool trovato = false; //creo un booleano trovato e lo setto a false
	unsigned int pos = H(chiave); //setto la posizione in base al vlore di ritorno della funzione hash
	iter = table[pos].primoLista(); //il valore di iter viene settato al primolista della tabella in posizione pos calcolata prima
	while (!table[pos].finelista(iter) && !trovato) 
	{
	if (chiave == table[pos].leggilista(iter).getKey()) //ciclo fino a quando non arrivo alla fine della lista o non l'ho trovato
	   trovato = true; //pongo trovato = true
	else
	    iter = table[pos].succlista(iter); //altrimenti setto il valore del puntatore al successivo elemento della lista di posizione pos
	}
	if (trovato) //se è stato trovato
	{
	   table[pos].canclista(iter); //cancello dalla lista il nodo in posizione iter
	   nelementi--; //decremento il numero di elementi presenti
	}
};

template<typename K, typename E> unsigned int Dizionario<K,E>::H(const K& chiave)
{
	return (hash(chiave) % lunghezza); //ritorna il modulo
}

template<typename K, typename E> unsigned int  Dizionario<K,E>::dimensione()
{
	return nelementi; //ritorno il numero di elementi presenti nel dizionario
}

template<typename K, typename E> void Dizionario<K,E>::stampa()
{
	for (int i=0;i<lunghezza;i++) //per tutti gli elementi presenti nella lista
	{
	    table[i].stampaLista();    //stampo il contenuto della lista relativa alla cella i
	}
};

#endif // DIZ_H
