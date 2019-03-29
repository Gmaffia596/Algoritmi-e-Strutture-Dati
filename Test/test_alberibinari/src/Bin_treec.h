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
class Bin_treec : public Bin_tree<T, int>{
    static const int NIL = -1;	//-1 non valido negli array -> NULL

  public:
	typedef typename Bin_tree<T, int>::value_type value_type;
	typedef typename Bin_tree<T, int>::Nodo Nodo;

    struct _cella{
        Nodo genitore;	//indice nodo genitore
        Nodo sinistro;	//indice nodo sx
        Nodo destro;	//indice nodo dx
        value_type valore;	//valore
    };

    typedef struct _cella Cella;

    // costruttori e distruttori
    Bin_treec();	//costruttore di lunghezza default [100]
    Bin_treec(int);	//costruttore di array di N elementi
    ~Bin_treec();

    // operatori
    void create();
    bool empty() const;

    Nodo root() const;			//ritorna radice
    Nodo parent(Nodo) const;	//ritorna genitore
    Nodo sx(Nodo) const;		//ritorna figlio sx
    Nodo dx(Nodo) const;		//ritorna figlio dx
    bool sx_empty(Nodo) const;	//esiste figlio sx
    bool dx_empty(Nodo) const;	//esiste figlio dx

    //void costr(Bin_treec<T>);
    void erase(Nodo);			//cancella nodo

    T read(Nodo) const;				//leggi valore del nodo
    void write(Nodo , value_type );	//modifica il valore del nodo

    void ins_root();	//inserisce nodo radice
    void ins_sx(Nodo);		//inserisce figlio sx
    void ins_dx(Nodo);		//inserisce figlio dx

	int height(Nodo) const;
    void stampa_albero_binario_pre_order(Nodo n);


  private:
    int MAXLUNG;		//Lunghezza dell'array
    Cella *spazio;		//Array (allocato dinamicamente) contenente l'albero
    int nNodi;			//numero di nodi
    Nodo inizio;		//nodo radice
    Nodo libera;		//primo nodo libero per l'inserimento
};

template <class T>
Bin_treec<T>::Bin_treec()
{
  MAXLUNG = 100;
  spazio = new Cella[MAXLUNG];
  create();
}

template <class T>
Bin_treec<T>::Bin_treec(int nNodi): MAXLUNG(nNodi)
{
  spazio = new Cella[nNodi];
  create();
}


template <class T>
Bin_treec<T>::~Bin_treec()
{
  erase(inizio);	//cancella partendo dalla radice
  delete[] spazio;	//dealloca array
}

template <class T>
void Bin_treec<T>::create()
{
  inizio = NIL;
  //utile per la ricerca della prima cella libera (SX)
  for (int i = 0; i < MAXLUNG; i++)
    {
      spazio[i].sinistro = (i+1) % MAXLUNG;
    }

  libera = 0;
  nNodi = 0;
}

template <class T>
bool Bin_treec<T>::empty() const
{
  return(nNodi == 0);
}

template <class T>
typename Bin_treec<T>::Nodo
Bin_treec<T>::root() const
{
  return(inizio);		//ritorna l'indice della radice
}

template <class T>
typename Bin_treec<T>::Nodo
Bin_treec<T>::parent(Nodo n) const
{
  if (n != inizio)
    return (spazio[n].genitore);	//ritorna genitore se n non è la radice
  else
    return(n);
}

template <class T>
typename Bin_treec<T>::Nodo
Bin_treec<T>::sx(Nodo n) const
{
  if (!sx_empty(n))
    return (spazio[n].sinistro);	//ritorna figlio sx (se esiste)
  else
    return(n);
};

template <class T>
typename Bin_treec<T>::Nodo
Bin_treec<T>::dx(Nodo n) const
{
  if (!dx_empty(n))
    return (spazio[n].destro); 		//ritorna figlio dx (se esiste)
  else
    return(n);
}

template <class T>
bool Bin_treec<T>::sx_empty(Bin_treec<T>::Nodo n) const
{
  return (spazio[n].sinistro == NIL);	//se NIL, ritorna vero
}

template <class T>
bool Bin_treec<T>::dx_empty(Bin_treec<T>::Nodo n) const
{
  return (spazio[n].destro == NIL);		//se NIL, ritorna vero
}

template <class T>
void Bin_treec<T>::ins_root()
{
  if (inizio == NIL)
    {
      inizio = libera;						//radice è la prima cella libera
      libera = spazio[libera].sinistro;		//aggiorna libera al figlio sx (vedi creazione)
      spazio[inizio].sinistro = NIL;		//figlio sx è NIL
      spazio[inizio].destro = NIL;			//figlio dx è NIL
      nNodi++;
    }
	else
		throw RootExists();					//chiama eccezione
}


template <class T>
void Bin_treec<T>::ins_sx(Nodo n)
{
	if (inizio == NIL)
		throw EmptyTree();				//se albero vuoto, chiama eccezione
	if (n == NIL)
		throw NullNode();				//se nodo non esistente, chiama eccezione
	if (spazio[n].sinistro != NIL)
		throw NodeExists();				//se ha già figlio sx, chiama eccezione
	if (nNodi >= MAXLUNG)
		throw FullSize();				//se spazio finito, chiama eccezione
  else
    {
      Nodo q = libera;						//alloca nodo q
      libera = spazio[libera].sinistro;		//aggiorna libera
      spazio[n].sinistro = q;				//figlio sx di n è q

      spazio[q].genitore = n;				//genitore di q è n
      spazio[q].sinistro = NIL;				//figlio sx di q è NIL
      spazio[q].destro = NIL;				//figlio dx di q è NIL
      nNodi++;
    }
}

template <class T>
void Bin_treec<T>::ins_dx(Nodo n)
{
	if (inizio == NIL)
		throw EmptyTree();				//se albero vuoto, chiama eccezione
	if (n == NIL)
		throw NullNode();				//se nodo non esistente, chiama eccezione
	if (spazio[n].destro != NIL)
		throw NodeExists();				//se ha già figlio dx, chiama eccezione
	if (nNodi >= MAXLUNG)
		throw FullSize();				//se spazio finito, chiama eccezione
	else
    {
	  //come SX
      Nodo q = libera;
      libera = spazio[libera].sinistro;
      spazio[n].destro = q;

      spazio[q].genitore = n;
      spazio[q].sinistro = NIL;
      spazio[q].destro = NIL;
      nNodi++;
    }
}

template <class T>
void Bin_treec<T>::erase(Nodo n)
{
	if (n != NIL) {
		if (!sx_empty(n))
			erase(spazio[n].sinistro);		//cancella sottoalbero sx (se esiste)
		if (!dx_empty(n))
			erase(spazio[n].destro);		//cancella sottoalbero dx (se esiste)
		if (n != inizio) {
			Nodo p = parent(n);			//salvo genitore di n (nodo in cancellazione)
			if (spazio[p].sinistro == n)
				spazio[p].sinistro = NIL;	//se è figlio sx, setto a NIL figlio sx del genitore p
			else
				spazio[p].destro = NIL;		//se è figlio dx, setto a NIL figlio dx del genitore p
		} else
			inizio = NIL;

		nNodi--;
		spazio[n].sinistro = libera;
		libera = n;
	}
	else
		throw NullNode();
}

template <class T>
T Bin_treec<T>::read(Nodo n) const
{
  if (n != NIL)
    return (spazio[n].valore);	//ritorna valore del nodo n
	else
		throw NullNode();
}

template <class T>
void Bin_treec<T>::write(Nodo n, value_type a)
{
  if (n != NIL)
    spazio[n].valore = a;	//modifica valore del nodo n, inserendo valore a
	else
		throw NullNode();
}

template <class T>
int Bin_treec<T>::height(Nodo n) const {
	int nodes_sx = 0;
	int nodes_dx = 0;
	if(!sx_empty(n)) {
		nodes_sx++;
		nodes_sx += height(sx(n));
	}
	if(!dx_empty(n)) {
		nodes_dx++;
		nodes_dx += height(dx(n));
	}
	if(nodes_sx > nodes_dx)
		return nodes_sx;
	else
		return nodes_dx;
}

//stampa a partire dalla radice. stampa prima i nodi sx e poi i nodi dx.
template<class T>
void Bin_treec<T>::stampa_albero_binario_pre_order(Nodo n) {
	//if(n != NIL){
		std::cout << read(n) <<",";
		if(sx_empty(n)!=true){
			stampa_albero_binario_pre_order(sx(n));
		}
		if(dx_empty(n)!=true){
			stampa_albero_binario_pre_order(dx(n));
		}
	//}
}

#endif /* _Bin_treecC_H_ */
