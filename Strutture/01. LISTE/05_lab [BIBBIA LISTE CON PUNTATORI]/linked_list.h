#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

//includo il file sorgente linear_list
#include "linear_list.h"

//definizione della classe template
template<class T>
class Linked_list; //forward declaration: viene successivamente utilizzata

template< class T >
class List_node{ 
	//ho detto al compilatore che Linked_List (di tipo friend) può accedere agli attributi privati della classe Nodo
	friend class Linked_list<T>;
 //definizione anche dei suoi metodi privati
 private:
	T _value; //il valore di tipo T (campo dato)
	List_node<T> * _pPrev; //il puntatore di tipo List_Node al precedente
	List_node<T> * _pNext; //il puntatore di tipo List_Node al successivo
};

//definizione della classe template del tipo di dato T (generico)
template< class T >
//è una linear list dove la posizione è un puntatore ad un nodo
class Linked_list : public Linear_list<T, List_node<T>*>{ //va ad effettuare il collegamento tra la Linked_List (implementazione specifica) con la Linear List (che è generica) rendendo disponibili a Linked_list tutti i metodi virtual che sono pubblici
 public:
	typedef typename Linear_list<T, List_node<T>*>::value_type value_type; //definisce un alias per l'attributo value_type di Linear_List, chiamandolo value_type
	typedef typename Linear_list<T, List_node<T>*>::position position; //definisce un alias per l'attributo position di Linear_List, chiamandolo position
	
	// costruttori della classe Linked_List (non sono virtuali ma definiti)
	Linked_list(); //costruttore di default senza parametri
	// costruttore per copia
	Linked_list(const Linked_list<T>& ); //passo in modo costante l'indirizzo del primo elemento della lista da copiare, non modificabile
	//distruttore
	~Linked_list(); //permette di distruggere tutta la Linked_List

	// operatori della classe Linked_List, sono gli stessi definiti e commentati nella linear_list
	void create(); //permette la creazione 
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position);
	void erase(position);
	//operatore aggiuntivo che permette di definire la lunghezza della linked_list. CONST perchè è di sola lettura
	int size() const 
	{
		return _length;
	};
	
	// sovraccarico dell'operatore =
	Linked_list<T>& operator=(const Linked_list<T>&);
	//sovrccarico dell'operatore ==
	bool operator==(const Linked_list<T> &) const;

//Qui inizia la definizione di metodi e attributi PRIVATE della classe Linked_List
 private:
	List_node<T> * _pHead; //puntatore al nodo sentinella
	int _length; //la lunghezza della Linked List
};

//definizione del template del primo costruttore
template< class T >
Linked_list< T >::Linked_list() 
{
	_pHead = new List_node<T>; //viene creata la testa della lista
	_pHead->_pNext = _pHead; //pHead.next viene fatto puntare a se stesso
	_pHead->_pPrev = _pHead; //pHead.prec viene fatto puntare a se stesso
	_length = 0; //la lunghezza (il numero di elementi) è 0
}


template< class T > //costruttore di copia, dobbiamo istruire il compilatore a comprendere le operazioni da effettuare
Linked_list< T >::Linked_list(const Linked_list<T>& L) //si usa quando devo costuire una nuova lista Linked_List partendo dalla dimensione di una già esistente Linked_List)
{
  _length = L.size(); //la nuova lista avrà dimensione uguale alla lista passata per parametro

	_pHead = new List_node<T>; //creo un nuovo nodo sentinella (nodo iniziale della nuova lista)
	_pHead->_pNext = _pHead; //pHead.next è uguale all'indirizzo della sentinella stessa
	_pHead->_pPrev = _pHead; //pHead.prev è uguale all'indirizzo della sentinella stessa

	if (!L.empty()) //se la lista da copiare L non è vuota, 
	{ 
		position p = L.last(); //vado a puntare P all'ultimo elemento della lista L da copiare
		for (int i=0; i <= L._length; i++) //fino a quando non arrivo al primo elemento della lista L
		{
			insert(L.read(p), begin()); //inserisco il campo dato della lista L, nella testa trattandolo come una PILA
			p = L.previous(p); //p va al nodo precedente
		}
	}
}

//distruttore deve deallocare partendo dal begin() fino a quando la lista non è vuota.
//Devo poi eliminare il puntatore testa e la sentinella (in next della sentinella punta a se stesso)
//primolista è il successore della sentinella- Se la lista è vuota mi restituisce il valore della sentinella.
template< class T >
Linked_list< T >::~Linked_list() //definiamo le operazioni effettuate dal distruttore
{
	while(!empty()) //fino a quando la Linked_List non è vuota
		erase(begin()); //dealloco il nodo in testa ma erase incrementa il puntatore al successivo
	delete _pHead; //dealloco la testa della lista
}

template< class T >
//implementazione del metodo virtuale di Linear_List CREATE()
void Linked_list< T >::create()
{
	if (empty()) //se la lista è vuota
			_length = 0; //imposta la lunghezza a 0
}

template< class T >
bool Linked_list< T >::empty() const //mediante un boolean controlla se la lista passata è vuota
{
	return(_pHead == _pHead->_pNext); //se la sentinella punta a se stessa (la lista è vuota) dunque ritorno TRUE, altrimenti FALSE
}

template< class T >
typename Linked_list< T >::position

Linked_list< T >::begin() const //restituisce la posizione del primo elemento, successore della sentinella
{
	return (_pHead->_pNext); //restituisce il pHead.next;
}

template< class T >
typename Linked_list< T >::position
Linked_list< T >::last() const //restituisce la posizione dell'ultimo elemento, memorizzato nella prec della sentinella
{
	return (_pHead->_pPrev); //restituisce il pHead.prec;
}

template< class T >
typename Linked_list< T >::position
Linked_list< T >::next(position p) const //restituisce la posizione successiva all'elemento P passato
{
	return(p->_pNext); //restituisce p.Next
}

template< class T >
typename Linked_list< T >::position //position non è un attributo della classe ma è un tipo definito nella classe Linked_List perciò va usato il typename
Linked_list< T >::previous(position p) const 
{
	if (p != _pHead) //se la posizione non è la sentinella, restituisce il precedente, altrimenti mi restituisce l'ultimo elemento della lista
		return(p->_pPrev); //mi restituisce il p.Prev
}

template< class T >
bool Linked_list< T >::end(position p) const 
{
	return(p == _pHead); //ritorna TRUE se il puntatore è uguale 
}

template< class T >
typename Linked_list< T >::value_type
Linked_list< T >::read(position p) const //legge il contenuto 
{
	if (!end(p)) //se la lista non è finita, mi stampa il valore del campo DATO
		return(p->_value);
}


//inserimento dei valori
template< class T >
void Linked_list< T >::write(const value_type &a, position p) 
{
	if (!end(p)) //se la lista non è finita, inserisco nel campo DATO il valore passato come parametro
    p->_value = a;
}

//inserimento di un nuovo valore in mezzo prima di P
template< class T >
void Linked_list< T >::insert(const value_type &a, position p)
{
	position t = new List_node<T>; //creo un nuovo nodo, che avrà posizione t
	t->_value = a; //in t.Dato inserisco il valore a passato per parametro come reference e costante

	t->_pNext = p; //in t.Next deve puntare a P
	t->_pPrev = p->_pPrev; //in t.Prec deve puntare a P.prec
	p->_pPrev->_pNext = t; //il successivo del precedente di P, deve puntare al nuovo puntatore T [p.prev.next]
	p->_pPrev = t; //p.Prec pinterà a t

	_length++; //incremento la lunghezza della lista
}

//riprendere da erase

//cancellazione dell'elemento della cella p
template< class T >
void Linked_list< T >::erase(position p) //cancellazione di un elemento dalla lista in posizione P
{
	if (!empty() && !end(p)) //se la lista non è vuota e la posizione di P non è quella finale
	{
		p->_pPrev->_pNext = p->_pNext; //p.prev.next=p.next - al puntatore precedente del successivo punta al p.successivo
		p->_pNext->_pPrev = p->_pPrev; //p.next.prev=p.prev - al puntatore successivo al precedente punto al p.precedente
		delete p; //cancello il nodo puntato da P
	}
}


template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L) //sovraccarico l'operatore =
{
	if (this != &L) //se l'oggetto left value!=alla reference di L (non faccio una reference su se stesso), altrimenti se è lo stesso oggetto non effettuo la copia
	{
		_length = L.size(); //imposto la lunghezza dell'oggetto di sinistra= a quello di destra

		_pHead = new List_node<T>; //creo la sentinella
		_pHead->_pNext = _pHead; //pHead.next punta a se stessa
		_pHead->_pPrev = _pHead; //pHead.prev punta a se stessa

        cout << L.empty(); //mi dice se la lista L (di destra) è vuota o meno
        cout << L.size(); //mi dice la dimensione della lista L di destra
		if (!L.empty()) //se L non è vuota
		{
            position p = L.last(); //metto P all'ultimo elemento di L (di destra) - effettuo la copia da destra verso sinistra
			for (int i=0; i < L.size(); i++) //procedo da destra verso sinistra
			{
				cout << i, L.read(p); //stampo il valore di I e il campo DATO presente alla p-esima posizione della lista L (di destra)
				insert(L.read(p), begin()); //inserisco il valore letto in testa alla lista di sinistra
				p = L.previous(p); //decremento il valore di P, facendolo puntare al precedente
			}
		}
	}
	return *this; //ritorno l'indirizzo di memoria della lista sinistra
}


template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const //sovraccarico l'operatore == (controlla se gli elementi della lista sono uguali, se si ritorna TRUE, altrimenti FALSE)
{
	if (L.size() != _length) //se la dimensione della lista L (DI DESTRA) è diversa dalla lunghezza di quella di sinistra
		return false; //possiamo già affermare che l'esito dell'uguaglianza è negativo, dunque ritorno false
	position p, pL; //altrimenti dichiaro due puntatori p e Pl di tipo posizione
	p = begin(); //p punta all'inizio di quello di sinistra
	pL = L.begin(); //pl punta all'inizio di quello di destra (Pl)
	while (!end(p)) //fino a quando non si arriva alla fine della lista P (di sinistra)
	{
		if (p->_value != pL->_value) //se p.dato (sinistra)!=pL.dato (destra)
			return false; //non sono uguali, quindi ritorno false
		p = p->_pNext; //altrimenti, se gli elementi sono uguali, p punta al successivo
		pL = pL->_pNext; //e pL punta al successivo
	}
	return true; //se si arriva qui, tutti gli elementi delle due liste sono uguali e viene ritornato il boolean TRUE
}


#endif
