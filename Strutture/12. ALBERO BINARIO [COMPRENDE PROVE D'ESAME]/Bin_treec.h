/***************************************************************************
 *   Copyright (C) 2005 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _Bin_treecC_H_
#define _Bin_treecC_H_

#include "Bin_tree.h"
#include "exceptions.h"

template <class T>
class Bin_treec : public Bin_tree<T, int>
{
    static const int NIL = -1;		//dichiarazione di una costante NIL disponibile per la classe a valore intero -1

  public:

	typedef typename Bin_tree<T, int>::value_type value_type;		//definizione del tipo di dato
	typedef typename Bin_tree<T, int>::Nodo Nodo;					//definizione del campo nodo

    struct _cella		//definizione della struttura _CELLA
	{
        Nodo genitore;		//dichiarazione di un nodo genitore
        Nodo sinistro;		//dichiarazione di un figlio sinistro
        Nodo destro;		//dichiarazione di un figlio destro
        value_type valore;	//dichiarazione di un campo DATO
    };

    typedef struct _cella Cella;		//chiamo la struttura _CELLA -> Cella

    // costruttori e distruttori
    Bin_treec();	//COSTRUTTORE
    Bin_treec(int);	//COSTRUTTORE A CUI PASSO IL NUMERO MASSIMO DI NODI
    ~Bin_treec();	//DISTRUTTORE

    // operatori
    void create();	//OPERAZIONE DI CREAZIONE DELL'ALBERO BINARIO
    bool empty() const;		//FUNZIONE DI CONTROLLO PER L'ALBERO PER VEDERE SE VUOTO O MENO

    Nodo root() const;		//FUNZIONE CHE RESTITUISCE LA RADICE DI UN ALBERO
    Nodo parent(Nodo) const;	//FUNZIONE CHE RESTITUISCE IL GENITORE DI UN NODO DATO
    Nodo sx(Nodo) const;		//FUNZIONE CHE RESTITUISCE IL FIGLIO SINISTRO DI UN NODO DATO
    Nodo dx(Nodo) const;		//FUNZIONE CHE RESTITUISCE IL FIGLIO DESTRO DI UN NODO DATO
    bool sx_empty(Nodo) const;	//FUNZIONE CHE RESTITUISCE UN VALORE BOOLEANO SE NON E' PRESENTE IL FIGLIO SINISTRO DI UN NODO DATO
    bool dx_empty(Nodo) const;	//FUNZIONE CHE RESTITUISCE UN VALORE BOOLEANO SE NON E' PRESENTE IL FIGLIO DESTRO DI UN NODO DATO

    //void costr(Bin_treec<T>);
    void erase(Nodo);		//FUNZIONE DI CANCELLAZIONE DI UN NODO DA UN ALBERO

    T read(Nodo) const;		//FUNZIONE DI LETTURA DEL CAMPO DATO DI UN NODO
    void write(Nodo , value_type );		//FUNZIONE DI SCRITTURA DEL CAMPO DATO DI UN NODO

    void ins_root(Nodo);	//INSERIMENTO DI UN NODO COME RADICE DI UN ALBERO
    void ins_sx(Nodo);		//INSERIMENTO DI UN NODO COME FIGLIO SINISTRO DI UN ALTRO
    void ins_dx(Nodo);		//INSERIMENTO DI UN NODO COME FIGLIO DESTRO DI UN ALTRO
    
    //inserimento dei metodi dati per esercizio
    void trovafoglia(Nodo);
    void previsita(Nodo);
    void postvisita(Nodo);
    void invisita(Nodo);

  private:
    int MAXLUNG;	//DEFINIZIONE DELLA LUNGHEZZA MASSIMA DELL'ALBERO BINARIO
    Cella *spazio;	//DEFINIZIONE DEL PUNTATORE SPAZIO DI TIPO CELLA
    int nNodi;		//DEFINIZIONE DEL NUMERO NODI DELL'ALBERO
    Nodo inizio;	//PUNTATORE NODO AD INIZIO
    Nodo libera;	//PUNTATORE NODO ALL'ULTIMO NODO LIBERO
};

template <class T>
Bin_treec<T>::Bin_treec()		//COSTRUTTORE DI DEFAULT
{
  MAXLUNG = 100;	//DEFINISCO UNA LUNGHEZZA MASSIMA DI 100
  spazio = new Cella[MAXLUNG];		//SPAZIO E' UN VETTORE DI CELLE DI 100 ELEMENTI
  create();		//CREO L'ALBERO BINARIO
}

template <class T>
Bin_treec<T>::Bin_treec(int nNodi): MAXLUNG(nNodi)		//SECONDO COSTRUTTORE CON PARAMETRO INTERO
{
  spazio = new Cella[nNodi];	//SPAZIO E' UN VETTORE DI CELLE DI nNodi ELEMENTI
  create();		//CREO L'ALBERO BINARIO
}


template <class T>
Bin_treec<T>::~Bin_treec()	//DISTRUTTORE
{
  erase(inizio);	//CANCELLO PARTENDO DALL'INIZIO
  delete[] spazio;	//CANCELLO IL VETTORE CONTENENTE I NODI
}

template <class T>
void Bin_treec<T>::create()		//FUNZIONE DI CREAZIONE DELL'ALBERO
{
  inizio = NIL;		//pongo inizio a valore NIL
  for (int i = 0; i < MAXLUNG; i++)		//per tutta la lunghrzza massima dichiarata
    {
      spazio[i].sinistro = (i+1) % MAXLUNG;	//??
    }

  libera = 0;	//pongo libera a 0
  nNodi = 0;	//inizializzo il numero dei nodi a 0
}

template <class T>
bool Bin_treec<T>::empty() const
{
  return(nNodi == 0);	//RITORNO TRUE SE IL NUMERO DEI NODI PRESENTI NELL'ALBERO E' 0
}

template <class T>
typename Bin_treec<T>::Nodo Bin_treec<T>::root() const 
{
  return(inizio); //RESTITUISCO IL NODO INIZIALE DELL'ALBERO (LA RADICE)
}

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::parent(Nodo n) const		//RESTITUISCO IL PADRE DI UN NODO
{
  if (n != inizio)	//SE NON SIAMO ALL'INIZIO
    return (spazio[n].genitore);	//RITORNO SUO PADRE
  else
    return(n);		//ALTRIMENTI RITORNO LA RADICE STESSA
}

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::sx(Nodo n) const		//RESTITUISCO IL FIGLIO SINISTRO DI UN NODO DATO
{
  if (!sx_empty(n))		//SE FIGLIO SINISTRO DEL NODO N E' PRESENTE
    return (spazio[n].sinistro);	//LO RITORNO
  else
    return(n);		//ALTRIMENTI RITORNO LA RADICE
};

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::dx(Nodo n) const		//RESTITUISCO IL FIGLIO DESTRO DI UN NODO DATO
{
  if (!dx_empty(n))		//SE FIGLIO DESTRO DEL NODO N E' PRESENTE
    return (spazio[n].destro);		//lO RITORNO
  else
    return(n);		//ALTRIMENTI RITORNO LA RADICE
}

template <class T>
bool Bin_treec<T>::sx_empty(Bin_treec<T>::Nodo n) const		//CONTROLLO SE IL FIGLIO SINISTRO E' VUOTO
{
  return (spazio[n].sinistro == NIL);	//RITORNO TRUE SE IL FIGLIO SINISTRO==NIL
}

template <class T>
bool Bin_treec<T>::dx_empty(Bin_treec<T>::Nodo n) const		//CONTROLLO SE IL FIGLIO DESTRO E' VUOTO
{
  return (spazio[n].destro == NIL);		//RITORNOI TRUE SE IL FIGLIO DESTRO==NIL
}

template <class T>
void Bin_treec<T>::ins_root(Bin_treec<T>::Nodo n)
{
	//INSERIMENTO DELLA RADICE IN UN ALBERO DICHIARATO.
	//LA RADICE, ESSENDO UNICA, VIENE GESTITA LA POSSIBILITA' CHE POSSANO ESSERE DEFINITE DUE RADICI
  if (inizio == NIL)
    {
      inizio = libera;
      libera = spazio[libera].sinistro;
      spazio[inizio].sinistro = NIL; //Alla radice appena creata, pone un figlio sinistro che punta a NULL
      spazio[inizio].destro = NIL; //Alla radice appena creata, pone un figlio destro che punta a NULL
      nNodi++; //incremento il numero dei nodi
    }
	else
		throw RootExists(); //gestisco l'eccezione che ci siano due o più dichiarazioni di radici
}


template <class T>
void Bin_treec<T>::ins_sx(Nodo n) //INSERIMENTO DI UN FIGLIO SINISTRO AD UN NODO n INDICATO
{
	if (inizio == NIL) //se voglio inserire un figlio, senza che venga creato il nodo
		throw EmptyTree(); //gestisco l'eccezione di albero vuoto
	if (n == NIL) //se la radice è stato inserito nell'aLbero ma non avvalorata
		throw NullNode();		//gestisco l'eccezione di nodo vuoto
	if (spazio[n].sinistro != NIL)		//se il figlio sinistro già esiste
		throw NodeExists();		//gestisco l'eccezione di nodo già esistente
	if (nNodi >= MAXLUNG)		//se il numero di nodi è >= alla lunghezza massima prefissata
		throw FullSize();		//gestisco l'eccezione di fullsize
  else
    {
      Nodo q = libera;		//nodo Q è il nodo che vogliamo inserire come figlio destro, lo facciamo puntare a libera
      libera = spazio[libera].sinistro;		//libera diventa il nodo sinistro puntato da libera stesso
      spazio[n].sinistro = q;	//il nodo genitore (n) punta a q 
      spazio[q].sinistro = NIL;	//il nodo figlio sinistro di q punta a NIL
      spazio[q].genitore = n;	//il nodo figlio, il suo padre sarà n
      spazio[q].destro = NIL;	//il nodo figlio destro di q punta a NIL
      nNodi++;		//incremento il numero di nodi presenti nell'albero
    }
}

template <class T>
void Bin_treec<T>::ins_dx(Nodo n)	//INSERIMENTO DI UN FIGLIO DESTRO AD UN NODO n INDICATO
{
	if (inizio == NIL)
		throw EmptyTree();
	if (n == NIL)
		throw NullNode();
	if (spazio[n].destro != NIL)
		throw NodeExists();
	if (nNodi >= MAXLUNG)
		throw FullSize();
	else
    {
      Nodo q = libera;		//nodo Q è il nodo che vogliamo inserire come figlio destro, lo facciamo puntare a libera
      libera = spazio[libera].sinistro;		//libera diventa il nodo sinistro puntato da libera stesso
      spazio[n].destro = q;		//il nodo genitore (n) punta da destra a q 
      spazio[q].genitore = n;	//il nodo figlio, il suo padre sarà n
      spazio[q].sinistro = NIL;	//il nodo figlio sinistro di q punta a NIL
      spazio[q].destro = NIL;	//il nodo figlio destro di q punta a NIL
      nNodi++;		//incremento il numero di nodi presenti nell'albero
    }
}

template <class T>
void Bin_treec<T>::erase(Nodo n)		//CANCELLAZIONE DI UN NODO DATO
{
  if (n != NIL) //se n non è nullo
  {
      if (!sx_empty(n))		//se si ha la presenza di figli sinistri
        erase(spazio[n].sinistro);		//cancello tutti i figli sinistri
      if (!dx_empty(n))		//se si ha la presenza di figli destri
        erase(spazio[n].destro);		//cancello tutti i figli destri
      if (n != inizio) 	//se n non è la radice
	  {
          Nodo p = parent(n);	//p viene avvalorato come PADRE di n
          if (spazio[p].sinistro == n)	//se n è il figlio sinistro di p
            spazio[p].sinistro = NIL;		//il figlio sinistro viene fatto puntare a NIL
          else
            spazio[p].destro = NIL;			//altrimenti, il figlio destro viene fatto puntare a NIL
        }
      else		//altrimenti se n è la radice
        inizio = NIL;	//pongo inizio=NIL
      nNodi--;		//decremento il numero di nodi
      spazio[n].sinistro = libera;		//il figlio sinistro di n punta a libera
      libera = n;			//libera punta al nodo n
    }
	else
		throw NullNode();		//altrimenti gestisco la possibilità che il nodo sia nullo
}

template <class T>
T Bin_treec<T>::read(Nodo n) const		//LETTURA DI UN NODO
{
  if (n != NIL)		//se il nodo n non è vuoto
    return (spazio[n].valore);	//ritorno il campo dato di n
	else
		throw NullNode();		//altrimenti gestisco l'eccezione di nodo nullo
}

template <class T>
void Bin_treec<T>::write(Nodo n, value_type a)		//SCRITTURA DEL CAMPO DATO DI UN NODO
{
  if (n != NIL)		//se il nodo n non è vuoto
    spazio[n].valore = a;	//il suo valore diventa A
	else
		throw NullNode();		//altrimenti gestisco l'eccezione di nodo nullo
}

template <class T>
void Bin_treec<T>::trovafoglia(Nodo n)
{
	
	bool figliosinistro=true;
	bool figliodestro=true;
	if (n != NIL) //se n non è nullo
  {
      if (!sx_empty(n))		//se si ha la presenza di figli sinistri
      {
      	trovafoglia(spazio[n].sinistro);
	  }
	  else
	  {
	  	figliosinistro=false; //il nodo non ha figlio sinistro
	  }
	  if(!dx_empty(n))
	  {
	  	trovafoglia(spazio[n].destro);
	  }
	  else
	  {
	  	figliodestro=false;
	  }

	  if(!figliosinistro&&!figliodestro)
	  {
	  	std::cout<<"FOGLIA TROVATA: "<<spazio[n].valore<<std::endl;
	  	if(spazio[n].valore%2!=0)
	  	{
	  			  	erase(n);
	    }
	  }
	}
}

template <class T>
void Bin_treec<T>::previsita(Nodo n)	// Traverse the root, left sub-tree, right sub-tree
{
	if(n!=NIL)
	{
		std::cout<<"VALORE: "<<spazio[n].valore<<std::endl;
		if(!sx_empty(n))
		{
			previsita(spazio[n].sinistro);
		}
		if(!dx_empty(n))
		{
			previsita(spazio[n].destro);
		}
	}
}

template <class T>
void Bin_treec<T>::postvisita(Nodo n)	// Traverse left sub-tree, right sub-tree, root
{
	if(n!=NIL)
	{
		if(!sx_empty(n))
		{
			postvisita(spazio[n].sinistro);
		}
		if(!dx_empty(n))
		{
			postvisita(spazio[n].destro);
		}
		std::cout<<"VALORE: "<<spazio[n].valore<<std::endl;
	}
}

template <class T>
void Bin_treec<T>::invisita(Nodo n) // Traverse the left sub-tree, root, right sub-tree
{
	if(n!=NIL)
	{
		if(!sx_empty(n))
		{
			invisita(spazio[n].sinistro);
		}
		std::cout<<"VALORE: "<<spazio[n].valore<<std::endl;
		if(!dx_empty(n))
		{
			invisita(spazio[n].destro);
		}
	}
}


#endif /* _Bin_treecC_H_ */
