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

#ifndef _CODAVT_
#define _CODAVT_


//definiamo una coda di tipoelem mediante la realizzazione con vettore
template < class tipoelem >
class Coda 
{

public:

  Coda(int n) //costruttore della classe
  {
    maxlung = n; //impostiamo la lunghezza a quella passata per parametro
    creaCoda(); //invochiamo il metodo creaCreda
  }

  ~Coda() //distruttore della classe
  {
  	delete[] elementi; //cancello il vettore degli elementi
  } 	

  void creaCoda() //metodo di creazione della coda
  {  
    elementi = new tipoelem[maxlung]; //crea un vettore di tipoelem di maxlunghezza
    testa = 0; //pone la testa a 0
    lung = 0; //pone la lunghezza della coda a 0
  }

  bool codaVuota() //metodo che restituisce un booleano sul test di codavuota
  {
    return (lung == 0); //se la lunghezza della coda è 0, ritorna TRUE
  }
  
  tipoelem leggiCoda() //restituisce un oggetto di tipoelem letto dalla coda
  {  
    if (!codaVuota()) //se la coda non è vuota
      return (elementi[testa]); //ritorna l'elemento che si trova in posizione testa di elementi
  }

  void fuoriCoda() //elimina un elemento dalla coda
  {
    if (!codaVuota()) //se la coda non è vuota
	{
      testa = (testa + 1) % maxlung; //incrementa il puntatore alla testa % maxlung per ritrovarsi con indici del vettore
      lung--; //decrementa la lunghezza del vettore stesso
    }
  }

  void inCoda(tipoelem a) //inserisce in coda un elementoi di tipoelem
  {
    if (lung != maxlung) //se la coda non è vuota
	{
      elementi[(testa+lung) % maxlung] = a; //inserisce l'elemento in testa (testa+lungh) sarebbe l'offset
      lung++; //incrementa la lunghezza del vettore
    }
  }
 
 private:
  tipoelem *elementi; //crea un puntatore di tipo tipoelem
  int testa, lung, maxlung; //definisce la testa, la lunghezza e la massima lunghezza della coda
};

#endif //CODAVT_
