#ifndef GRAFOLIST_H
#define GRAFOLIST_H

#include "Grafo.h"
#include "list_vector.h"
/** 
	Questa realizzazione usa un vettore per tenere traccia di tutti quanti i nodi del grafo, ogni cella del vettore fa riferimento ad un'altra lista di nodi
	facenti parte alla lista degli adiacenti di ogni nodo. 
	
	Inoltre è possibile creare dei grafi pesati, andando a specificare in fase di costruzione del grafo di che tipo si vuole il peso.
	
**/

class NodoG
{
 public:
  NodoG(int i)
  {
    nodoId = i;		//indice nel vettore iniziale di tipo intero
  }

  NodoG()
  {
  	//costruttore vuoto
  }
  
  
  int getId(){ return nodoId; }			//restituisce la posizione nel vettore del nodo
  void setId(int id) {nodoId = id; }	//il grafo gli passa this		  //quando inserisco il nodo in un grafo, invoco il setID inserendo l'ID nel vettore dei nodi
  void setPuntatore(void* G) {this->G=G;}
  void* getPuntatore() {return G; }
 private:
	void* G;
  //int *G;	             //indirizzo di tipo Grafo che gli setta l'id
  int nodoId;			//l'ID rappresenta l'indice nel vettore
};



template<class P>
class InfoArco 
{
 public:
  P peso;			//peso dell'arco tra due nodi
  NodoG _to;		//l'indice a cui punta l'arco nel vettore
};


template<class E, class P> 
  class InfoNodo 
  {
 public:
  E   etichetta;		//etichetta del nodo
  bool vuoto;			//status se vuoto o meno nel vettore dei nodi
  void* info;			
  List_vector <InfoArco<P> > archi;			//lista degli archi di ogni nodo
  int archi_entranti;		//contiene il numero di archi entranti di un nodo. InsArco incrementa - CancArco decrementa
    
  InfoNodo()
  { 
    info = 0; 	//setto info=0
    vuoto = true; 		//setto il nodo a vuoto
    archi_entranti=0;		//setto il numero dei nodi entranti in un nodo a 0
  }
};


template<class E, class P>
  class GrafoList : public Grafo<E, P, NodoG > 
  {
 public:
    typedef E Etichetta;		//etichetta del nodo del grafo
    typedef P Peso;				//indica il peso dell'arco
    typedef NodoG Nodo;			//indica il nodo del grafo
    typedef Arco_<Peso, Nodo> Arco;		//indica l'arco del grafo
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;		//riferimento al grafo //------------DA CAPIRE------------
    typedef typename Grafo_::ListaNodi ListaNodi;		//lista dei nodi del grafo
    typedef typename Grafo_::ListaNodiPos ListaNodiPos;		//indica il vettore di posizioni dei nodi

    GrafoList(int);		//COSTRUTTORE
    ~GrafoList();		//DISTRUTTORE

    bool vuoto() const;		//funzione che determina se, dato un grafo, questo è vuoto
    void insNodo(NodoG&);	//funzione che, dato un nodo, lo inserisce nel grafo
    void insArco(Nodo, Nodo, Peso);		//funzione che, dati due nodi ed un peso, inserisce un arco nel grafo
    void cancNodo(Nodo);			//funzione che, dato un nodo, lo cancella dal grafo
    void cancArco(Nodo, Nodo);		//funzione che, dati due nodi, mi cancella l'arco presenti
    bool esisteArco(Nodo n1, Nodo n2) const; //controllo se esiste un arco che collega questi due nodi, controllando se il grafo è lo stesso
	bool esisteNodo(Nodo) const;       //da chiedere
    ListaNodi Adiacenti(Nodo) const ;		//funzione che, dato un nodo, mi restituisce una lista dei nodi adiacenti
    ListaNodi list_nodi() const ;			//funzione che restituisce la lista dei nodi presenti nel grafo
    Etichetta leggiEtichetta(Nodo) const ;		//funzione che, dato un nodo, mi restituisce il valore dell'etichetta
    void scriviEtichetta(Nodo, Etichetta) ;		//funzione che, dato un nodo e un valore di etichetta, mi setta il valore dell'etichetta
    Peso leggiPeso(Nodo, Nodo) const ;			//funzione che, dati due nodi, mi restituisce il peso dell'arco che collega i due nodi
    void scriviPeso(Nodo, Nodo, Peso) ;			//funzione che, dati due nodi ed un peso, mi determina il peso dell'arco
    void* getIndirizzo() {	return this;	}
    
    int numNodi()
	{
      return nodi;		//restituisce il numero di nodi del grafo
    };
    int numArchi()
	{
      return archi;		//restituisce il numero di archi del grafo
    };


 private:
    InfoNodo<E,P>* matrice;			//array di tipo Infonodi - che contiene nodi
    int dimensione;					//dimensione massima dei nodi possibili in un grafo
    int nodi;						//nodi effettivamente presenti nel grafo
    int archi;						//numero di archi presenti presenti nel grafo
};


template<class E, class P>
  GrafoList<E, P>::GrafoList(int _dimensione)		//crea il vettore dei nodi, passando per input la dimensione massima
{
  dimensione = _dimensione;		//avvaloro la dimensione massima
  nodi = 0;		//setto il numero dei nodi presenti a 0
  archi = 0;		//setto il numero dei archi presenti a 0
  matrice = new InfoNodo<E,P>[dimensione];		//alloco un array di tipo InfoNodo di dimensione (DIMENSIONE)
  for (int i=0; i<dimensione; i++)		//per ohni nodo
  {
  	matrice[i].vuoto=true;	  //impostare a true il vuoto di tutti i nodi
  	matrice[i].archi.create();		//Va a creare il riferimento alla lista degli archi
  }

}

template<class E, class P>
  GrafoList<E, P>::~GrafoList() 		//distruttore del vettore
{
  delete [] matrice;		//deallocazione del vettore dei nodi
}

template<class E, class P>
  bool GrafoList<E, P>::vuoto() const 		//metodo vuoto del grafo
{
  return (nodi == 0);		//ritorna TRUE se il numero dei nodi = 0
}


template<class E, class P>
  bool GrafoList<E, P>::esisteNodo(NodoG n) const		//metodo esisteNodo del grafo
{
bool trovato=false;
	if(n.getPuntatore()==this && !matrice[n.getId()].vuoto)
	{
	
	int i;
	for(i=0;i<dimensione &&trovato==false;i++)
	{
		if(matrice[i].etichetta == matrice[n.getId()].etichetta)
		{
			trovato=true;
		}
	}
	}
	return trovato;
}


template<class E, class P>
  bool GrafoList<E, P>::esisteArco(NodoG n1, NodoG n2) const		//metodo esisteNodo del grafo
{
	typename List_vector<InfoArco<P> >::position p; 
	bool trovato=false;
	int i;
	p=matrice[n1.getId()].archi.begin();
	while(!matrice[n1.getId()].archi.end(p) && !trovato)
	{
		if(matrice[n1.getId()].archi.read(p)._to.getId()==n2.getId())
		{
			trovato=true;
		}
		else
		{
			p = matrice[n1.getId()].archi.next(p);
		}
	}
	return trovato;
}

template<class E, class P>
  void GrafoList<E, P>::insNodo(Nodo& N) 		//inserimento del nodo
{
  int n = 0;		//inizializzo l'indice del vettore
  if (nodi < dimensione)		//se il numero dei nodi effettivamente presenti è minore della dimensione massima
  {
    while (matrice[n].vuoto == false)		//fino a quando non trovo una posizione libera nella matrice
      n++;		//incremento l' indice del vettore
    nodi++;		//incremento il numero dei nodi occupati
    matrice[n].vuoto = false;		//indico che la cella è utilizzata
  }
  matrice[n].archi_entranti=0;		//<---FATTO
  N.setId(n);		//avvaloro l'ID del nodo N con la posizione nel vettore
  N.setPuntatore(this); //<-- MI STAMPA L'INDIRIZZO DI MEMORIA DEL GRAFO NEL NODO
}

template<class E, class P>
  void GrafoList<E, P>::insArco(Nodo n1, Nodo n2, P peso) 		//inserimento di un arco
{
	if(esisteNodo(n1)&&esisteNodo(n2))
	{
		InfoArco<P> I;		//dichiarazione dell'arco
		I.peso = peso;		//avvaloro il peso dell'arco che stiamo creando
		I._to = n2;			//avvaloro la destinazione dell'arco (il nodo entrante) con il riferimento a N2
		matrice[n1.getId()].archi.insert(I, matrice[n1.getId()].archi.begin());		//vado in inserire l'arco nella lista degli archi uscenti del nodo N1
		
		//incrementare il numero dei nodi entranti di n2
		matrice[n2.getId()].archi_entranti++;				//<---FATTO
		
		archi++;		//incremento il numero degli archi presenti nel grafo	
	}
	else
	{
		cout<<"I due nodi non appartengono allo stesso grafo"<<endl;
	}
}


template<class E, class P>
  void GrafoList<E, P>::cancNodo(Nodo n) 		//cancellazione del nodo, passato per Input
  {
  bool canc = true;		//avvaloro il canc a true, per indicare 
  int i;				//dichiaro l'indice
  for (i=0; i < dimensione && canc; i++) 		//ciclo fino a quando l'indice è minore della dimensione e canc=TRUE
    if (!matrice[n.getId()].archi.empty()) 		//se la lista degli archi in riferimento al nodo uscente è vuota
      canc = false;			//setto canc a falso
  // TODO: implementare il controllo sugli archi entranti
  
  	if(matrice[n.getId()].archi_entranti!=0)					//<--FATTO
  		canc=false;
  
  
	//se il numero di archi entranti e' 0
  if (canc)		//se CANC è TRUE
  {
    // la lista  matrice[n.getId()].archi Ã¨ vuota;
    matrice[n.getId()].vuoto = true;		//setto a TRUE la cella del vettore in riferimento al nodo cancellato
    cout<<"cancellato"<<endl;
  }
}

template<class E, class P>
  void GrafoList<E, P>::cancArco(Nodo n1, Nodo n2)			//cancellazione dell'arco
{
	if(n1.getPuntatore()==n2.getPuntatore())
	{
			typename List_vector<InfoArco<P> >::position p; 		//dichiaro un indice di posizione P
		p = matrice[n1.getId()].archi.begin();					//lo faccio puntare alla prima posizione della lista degli archi uscenti del nodo N1
		bool trovato = false;									//inizializzo il boolean TROVATO a false
		while (!matrice[n1.getId()].archi.end(p) && !trovato)		//fino a quando non arrivo alla fine della lista dei nodi uscenti e non è stato trovato
		{
			if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())		//se l'ID della posizione in cui si trova P è uguale a quello di n2
				trovato = true;														//imposto trovato=true
			else 
					p = matrice[n1.getId()].archi.next(p);		//altrimenti passo al successivo
		}
		if (trovato)		//se il nodo di destinazione è stato trovato
		{
			matrice[n1.getId()].archi.erase(p);		//cancello l'arco presente in posizione P
			matrice[n2.getId()].archi_entranti--;			//<--FATTO
	  		archi--;			//decremento il numero di archi presenti nel grafo
		}
	}
	else
	{
		cout<<"ATTENZIONE! Si sta tentando di cancellare un arco tra due nodi che non appartengono allo stesso grafo"<<endl;
	}
}

template<class E, class P>
  typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::Adiacenti(Nodo n) const
  {
  ListaNodi list;
  typename List_vector<InfoArco<P> >::position p; 			//dichiaro l'indice posizionale P
  
    if(!matrice[n.getId()].archi.empty())
	{
		p = matrice[n.getId()].archi.begin();
		while (!matrice[n.getId()].archi.end(p))
		{
			//matrice[n.getId()].archi.read(p)._to.getId();
			list.insert(new NodoG(matrice[n.getId()].archi.read(p)._to),list.begin());
			p = matrice[n.getId()].archi.next(p);
		}
	}

  // FATTO TODO: costruire la lista dei nodi dalla lista degli adiacenti matrice[n.getId()].archi
  return list;
  
}

template<class E, class P>
  typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::list_nodi() const 
  {
  ListaNodi list;			//creouna lista di riferimenti a Nodi
  for (int i = 0; i < dimensione; i++)		//ciclo fino alla dimensione massima
    if (!matrice[i].vuoto) 		//se il nodo corrente ha archi uscenti
      list.insert(new NodoG(i), list.begin());		//inserisco nella lista creata il riferimento alla posizione del vettore del nodo, posizionandola all'inizio
  return list;		//ritorno l'indice della lista
}

template<class E, class P>
  E GrafoList<E, P>::leggiEtichetta(Nodo n) const 		//leggi l'etichetta di un nodo
{
  return matrice[n.getId()].etichetta;				//restituisce l'etichetta di un nodo, passato per parametro
}

template<class E, class P>
  void GrafoList<E, P>::scriviEtichetta(Nodo n, E etichetta) 		//scrive l'etichetta di un nodo
{
  matrice[n.getId()].etichetta = etichetta;			//imposta l'etichetta del nodo indicato, con la sua etichetta
}

template<class E, class P>
  P GrafoList<E, P>::leggiPeso(Nodo n1, Nodo n2) const 			//leggi il peso di un arco tra due nodi indicati
  {
	typename List_vector<InfoArco<P> >::position p; 			//dichiaro l'indice posizionale P
	p = matrice[n1.getId()].archi.begin();						//P lo metto all'inizio della lista degli archi del nodo uscente
	bool trovato = false;										//imposto trovato=false
	while (!matrice[n1.getId()].archi.end(p) && !trovato)			//fino a quando non arrivo alla fine della lista degli archi e non l'ho trovato
	{	
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())		//se il riferimento al nodo entrante è uguale all'ID di N2
			trovato = true;														//imposto trovato=true
		else 
				p = matrice[n1.getId()].archi.next(p);							//altrimenti incremento P al successivo
	}
	if (trovato)																//se l'ho trovato
		return matrice[n1.getId()].archi.read(p).peso;							//leggo il peso relativo all'arco
}

template<class E, class P>
  void GrafoList<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) 
  {
	typename List_vector<InfoArco<P> >::position p; 			//dichiaro l'indice posizionale P
	p = matrice[n1.getId()].archi.begin();						//P lo metto all'inizio della lista degli archi del nodo uscente
	bool trovato = false;										//imposto trovato=false
	while (!matrice[n1.getId()].archi.end(p) && !trovato)		//fino a quando non arrivo alla fine della lista degli archi e non l'ho trovato
	{
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())	//se il riferimento al nodo entrante è uguale all'ID di N2
			trovato = true;													//imposto trovato=true
		else 
				p = matrice[n1.getId()].archi.next(p);						//altrimenti incremento P al successivo
	}
	if (trovato)												//se l'ho trovato
	{
		InfoArco<P> I;											//creo un arco i
		I.peso = peso;											//ne imposto il peso
		I._to = n2;												//imposto il riferimento al nodo destinatario
		matrice[n1.getId()].archi.write(I,p);					//scrivo nella posizione p L'ARCO che è stato creato
	}
}

#endif
