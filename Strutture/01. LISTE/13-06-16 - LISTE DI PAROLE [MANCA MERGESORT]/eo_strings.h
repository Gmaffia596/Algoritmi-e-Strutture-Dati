#ifndef EO_STRINGS_H
#define EO_STRINGS_H
#include <string>
#include "Linked_List.h"

using namespace std;

class eo_strings
{
	public:
		typedef typename Linear_list<string, List_node<string>*>::position position;
		void inserisci (string);	//inserisce una stringa nella corrispondente lista
		void rimuovi (string);		//rimuove la stringa dalla corrispondente lista
		void rimuovi (char);
		int freq_pari();
		void visualizza_dispari();
		
		//funzioni aggiuntive
		void stampa_dispari();
		void stampa_pari();
		void merge(Linked_list<string> list, Linked_list<string> &listaOrdinata);
	
	private:
		Linked_list<string> pari;
		Linked_list<string> dispari;
};

void eo_strings::inserisci(string s)
{
	//cout<<s.length();
	if(s.length()%2==0)		//la stringa è di lunghezza pari
	{
		pari.insert(s,pari.begin());
		//cout<<"Stringa inserita nella lista delle parole pari"<<endl;
	}
	else
	{
		dispari.insert(s,dispari.begin());
	}
}

void eo_strings::rimuovi(string s)
{
	bool trovato=false;
	if(s.length()%2==0)
	{
		//ricerca del termine nella lista
		position p = pari.begin();
		while(!pari.end(p) && !trovato)
		{
			if(pari.read(p)==s)
			{
				pari.erase(p);
				trovato = true;
				//cout<<"Elemento cancellato"<<endl;
			}
			p = pari.next(p);
		}
	}
	else
	{
		//ricerca del termine nella lista
		position p = dispari.begin();
		while(!dispari.end(p) && !trovato)
		{
			if(dispari.read(p)==s)
			{
				dispari.erase(p);
				trovato = true;
				//cout<<"Elemento cancellato"<<endl;
			}
			p = dispari.next(p);
		}
	}
	if(!trovato)
	{
		cout<<"L'elemento ricercato non e' presente"<<endl;
	}
}

void eo_strings::rimuovi(char c)
{
	bool trovato = false;
	position p = pari.begin();
	while(!pari.end(p))
	{
		//cout<<"Stampo primo carattere: "<<pari.read(p).at(0)<<endl;
		if(pari.read(p).at(0)==c)
		{
			pari.erase(p);
			trovato=true;
			//cout<<"Elemento eliminato"<<endl;
		}
		p=pari.next(p);
	}
	if(!trovato)
	{
		cout<<"Non ci sono stringhe che iniziano con tale carattere"<<endl;
	}
}

int eo_strings::freq_pari()
{
	return pari.size();
}

void eo_strings::visualizza_dispari()
{
	position p = dispari.begin();
	Linked_list<string> dispariOrd;
	merge(dispari, dispariOrd);
	dispari = dispariOrd;
	
}

template <class T>
void Ordered_list<T>::merge(Ordered_list<T>& list)
{
	position pList = list.begin();
	position p = begin();
	while(!list.end(pList))
	{
		if(read(p)>=list.read(pList))
		{
			insert(list.read(pList),p);
			pList = list.next(pList);
		}
		else p = next(p);
	}
}


/*

void mergesort(Item a[], int left, int right) 
{
	if (left<right) 
	{
		int center = (left+right)/2;
		mergesort(a, left, center);
		mergesort(a, center+1, right);
		merge(a, left, center, right);
	}
}

void merge(Item a[], int left, int center, int right) 
{
	Item* aux = new int[right + 1];
	int i,j;
	for (i = center+1; i > left; i--) 
		aux[i-1] = a[i-1];
	for (j = center; j < right; j++) 
		aux[right+center-j] = a[j+1];
	for (int k = left; k <= right; k++)
		if (aux[j] < aux[i]) 
			a[k] = aux[j--];
		else
			a[k] = aux[i++];
        delete [] aux;
}

//altra implementazione trovata
void bubblesort_c(position listapunt)
{

   int i,j,temp,elementi=0;
   position cursore,precedente,successivo;
   
   cursore=listapunt;

   while(cursore!=NULL)
   { //mi determino di quanti elementi è fatta la lista
      elementi++;
      cursore=cursore->prossimo;
   }

   // righe spostate da dentro il for //
   precedente=listapunt;
   successivo=listapunt;
   successivo=successivo->prossimo;
   // ------------------------------- //

   for(i=0;i<=elementi-2;i++)
   {//algoritmo bubblesort
      
      
      	for(j=0;j<=elementi-2;j++)
	  	{ //scorro la lista

        	if(precedente->dato > successivo->dato)
			{ //scambio
            	temp=precedente->dato;
            	precedente->dato=successivo->dato;
            	successivo->dato=temp;
         	}
      	}

      precedente=successivo;
      successivo=successivo->prossimo;
      
   }
   
}
*/

void eo_strings::stampa_dispari()
{
	bool presente=false;
	position p = dispari.begin();
	cout<<endl<<"-----------INIZIO STAMPA DISPARI---------------"<<endl;
	while(!dispari.end(p))
	{
		cout<<dispari.read(p)<<endl;
		presente=true;
		p=dispari.next(p);
	}
	if(!presente)
	cout<<"Non ci sono elementi da stampare"<<endl;
	cout<<"-----------FINE STAMPA-----------------"<<endl;
}

void eo_strings::stampa_pari()
{
	bool presente=false;
	position p = pari.begin();
	cout<<endl<<"-----------INIZIO STAMPA PARI---------------"<<endl;
	while(!pari.end(p))
	{
		cout<<pari.read(p)<<endl;
		presente=true;
		p=pari.next(p);
	}
	if(!presente)
	cout<<"Non ci sono elementi da stampare"<<endl;
	cout<<"-----------FINE STAMPA-----------------"<<endl;
}


#endif
