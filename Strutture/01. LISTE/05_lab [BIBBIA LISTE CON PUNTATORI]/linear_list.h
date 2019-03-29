#ifndef _LISTALIN_H
#define _LISTALIN_H
//inclusione della libreria iostream
#include <iostream>
//definisco gli std principali usati dalla libreria
using std::cout;
using std::endl;
using std::ostream;


//definizione del template
template< class T, class P > //in questo caso, quello che viene dopo lo deve generalizzare in base ai tipi di dati che vengono passati

class Linear_list{
 public:
	typedef T value_type;   // il valore del nodo
	typedef P position;		//la definizione di posizione
	
	// definizione degli operatori virtuali
	// queste cose non sono implementate qui (=0) e vengono implementate a seconda del tipo di lista concreta
	virtual void create() = 0; //creazione della lista
	virtual bool empty() const = 0; //controlla se la lista è vuota, costante perchè non permette la modifica della lista passata
	virtual value_type read(position) const = 0; //legge il contenuto in una data posizione, restituendolo e non permette la modifica della lista passata
	virtual void write(const value_type & x, position p) = 0; //scrivere il valore X passato come costante (perchè non può essere modificato) nella posizione P della lista
	virtual position begin() const = 0;  // restituisce la posizione che punta al primo elemento della lista
	virtual bool end(position) const = 0; // indica se quella posizione è la fine della lista (TRUE) altrimenti FALSE
	virtual position next(position) const = 0; //indica la posizione del nodo successivo al nodo che ha come posizione P passata come parametro
	virtual position previous(position) const = 0; // indica la posizione del nodo precedente al nodo che ha come posizione P passata come parametro
	virtual void insert(const value_type &, position) = 0; // permette l'inserimento di un elemento passato come parametro (in modo costante) in base alla posizione
	virtual void erase(position pos) = 0; // permette di eliminare il nodo presente in posizione POS


/* Questo template sovraccarica <<. Attenzione se il tipo restituito da read non Ã¨ primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore << 
 */
template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){ //restituisce lo stream di output sovraccaricando <<. Passo (lo stream di output e il singolo oggetto della lista da stampare)
	typename Linear_list<T,P>::position p; //Al posto di scrivere Linear_list<T,P>::position scrivo solo p
	p = l.begin(); //p punta alla prima posizione della lista
	os << "["; //mette una parentesi quadra iniziale
	while (!l.end(p)){ //fino a quando p non arriva alla fine della lista
		if (p != l.begin()) //se p non è uguale all'indirizzo iniziale della lista (cioè la lista è vuota: se vuota il successivo del begin è il begin stesso) mi metti la virgola
			os << ", " << l.read(p);
		else
			os << l.read(p); //altrimenti leggo il primo senza mettere la virgola in stampa
		p = l.next(p); //incremento il puntatore P
	}
	os << "]" << endl; //Alla fine chiudo la parentesi graffa
	return os; //ritorno lo stream di output OS
}
#endif
