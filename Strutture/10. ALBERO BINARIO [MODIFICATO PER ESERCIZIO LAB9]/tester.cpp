/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
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

#include "Bin_treec.h"
#include <iostream>

using namespace std;


int main()
{
	
	Bin_treec<int> T; //CREAZIONE dell'albero binario di tipo intero
	typename Bin_treec<int>::Nodo n1, n2; //definizione del nodo INTERO nodo 1, nodo 2

	T.ins_root(n1); //inserisco il nodo n1 nell'albero, che sar� la radice
	T.write(T.root(),1); //nella radice verr� posto il valore 1
	n1 = T.root(); //n1 PUNTA alla radice dell'albero
	//GESTIONE DELLA SENTINELLA
	T.ins_sx(n1); //la radice punta a sinistra al primo nodo n1
	T.ins_dx(n1); //la radice punta a destra al primo nodo n1
	
/**
	//INSERIMENTO DEL FIGLIO SINISTRO DEL NODO PADRE
	T.write(T.sx(n1),2); //inserisco il valore 2 nella posizione sinistra del nodo padre
	n1 = T.dx(n1); //n1 punta al valore destro del nodo padre
	T.write(n1, 3); //scrivo nel nodo puntato da n1 il valore 3
	T.ins_dx(n1); //al padre inserisco il figlio destro identificato come n1
	T.write(T.dx(n1), 4); //inserisco un figlio destro a n1, inserendo il valore 4

**/
	T.print(); //stampo l'albero binario
	//cout << T;		<- RIDEFINIZIONE FUNZIONANTE DELL'OPERATORE <<
}

