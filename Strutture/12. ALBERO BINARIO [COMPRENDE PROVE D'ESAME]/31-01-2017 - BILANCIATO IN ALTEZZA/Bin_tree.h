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

#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <iostream>

template <class T, class N>
class Bin_tree  //definizione della classe dell'albero binario
{
  static const int NIL = -1;

  public:

    // tipi
    typedef T value_type; //DEFINIZIONE DEL CAMPO DATO
    typedef N Nodo; //definizione del nodo

    // operatori della classe astratta
    virtual void create() = 0;	//operazione di creazione dell'albero binario
    virtual bool empty() const =  0;	//operazione di check se l'albero è vuoto

    virtual Nodo root() const = 0;	//funzione di restituzione della radice di un albero
    virtual Nodo parent(Nodo) const =  0;	//funzione che, dato un nodo, restituisce il nodo genitore
    virtual Nodo sx(Nodo) const = 0;	//funzione che, dato un nodo, restituisce il figlio sinistro
    virtual Nodo dx(Nodo) const = 0;	//funzione che, dato un nodo, restituisce il figlio destro
    virtual bool sx_empty(Nodo) const = 0;	//funzione che, dato un nodo, restituisce un valore booleano se non è presente il figlio sinistro
    virtual bool dx_empty(Nodo) const = 0;	//funzione che, dato un nodo, restituisce un valore booleano se non è presente il figlio destro

    //virtual void costr(Bin_tree<T,N>);
    virtual void erase(Nodo) = 0;		//funzione di eliminazione di un nodo dall'albero

    virtual T read(Nodo) const = 0;		//funzione per la lettura del campo dato di un nodo scelto
    virtual void write(Nodo , value_type ) = 0;		//funzione per l'avvaloramento del campo dato di un nodo scelto

    virtual void ins_root(Nodo) = 0;	//funzione per l'inserimento del nodo come radice
    virtual void ins_sx(Nodo) = 0;		//funzione per l'inserimento del nodo come figlio sinistro
    virtual void ins_dx(Nodo) = 0;		//funzione per l'inserimento del nodo come figlio destro

    // funzioni di servizio da implementare qui
    virtual void previsita(Nodo) = 0;
    virtual void invisita(Nodo) = 0;
    virtual void postvisita(Nodo) = 0;

    virtual void print() const;		//funzione di stampa dell'albero

private:
    virtual void printSubTree(const Nodo) const; //funzione di stampa del sottoalbero (RICORSIVO)


  };
//RIDEFINIZIONE DELL'OPERATORE DI STAMPA, FACENDO USO DI UNA FUNZIONE CHE MI STAMPA I SOTTOALBERI RICORSIVAMENTE
template <class T, class N>
void Bin_tree<T,N>::print() const
{
	if (!empty()) //se l'albero non è vuoto
		printSubTree(root()); //Stampa il sottoalbero partendo dalla radice
	else 
		std::cout << "[]" << std::endl; //altrimenti stampa []
	std::cout << std::endl;
}

template <class T, class N>
void Bin_tree<T,N>::printSubTree(const Nodo n) const	//stampa del sottoalbero, partendo da un nodo
{
	std::cout << "[" << read(n) << ", ";
	if (!sx_empty(n))		//se è presente il figlio sinistro
		printSubTree(sx(n));		//richiamo la procedura che analizzerà e stamperà tutti i figli sinistri di livello inferiore a n
	else std::cout << "NIL";		//se vuoto, scriverò NIL
	std::cout << ", ";
	if (!dx_empty(n))		//se è presente il figlio destro del nodo n
		printSubTree(dx(n));		//richiamo la procedura che analizzerà e stamperà tutti i figli destri di livello inferiore a n
	else std::cout << "NIL";		//se vuoto, scriverò NIL
	std::cout << " ]";
}

template<class T, class N>
std::ostream& operator<<(std::ostream& out, const Bin_tree<T, N>& t)		//RIDEFINIZIONE OPERATORE << 
{
	//QUANDO RICHIAMATO <<, effettua una t.print()
    t.print();
    return out;
}

#endif /* _BINALBEROC_H_ */
