#include "GrafoList.h"

#include <string>

using namespace std;


int main()
{
	//vado a creare un grafo di elementi di tipo stringa e come pesi numeri interi
	GrafoList<string,int> G(10);		//il grafo avrà 10 elementi
	
	//vado a creare i nodi del grafo
	NodoG n1,n2,n3,n4,n5,n6,n7;
	
	//vado ad inserire i nodi nel grafo e successivamente vado ad avvalorare le loro etichette
	G.insNodo(n1);
	G.scriviEtichetta(n1,"a");
	G.insNodo(n2);
	G.scriviEtichetta(n2,"b");
	G.insNodo(n3);
	G.scriviEtichetta(n3,"c");
	G.insNodo(n4);
	G.scriviEtichetta(n4,"d");
	G.insNodo(n5);
	G.scriviEtichetta(n5,"e");
	G.insNodo(n6);
	G.scriviEtichetta(n6,"f");
	G.insNodo(n7);
	G.scriviEtichetta(n7,"g");
	
	
	//vado a creare gli archi tra i vari nodi
	G.insArco(n1,n3,1);		//a con c
	G.insArco(n1,n4,2);		//a con d
	G.insArco(n1,n6,1);		//a con f
	
	G.insArco(n3,n6,1);		//c con f	
	G.insArco(n3,n1,1);		//c con a
	
	G.insArco(n6,n3,1);		//f con c
	G.insArco(n6,n4,1);		//f con d
	G.insArco(n6,n1,1);		//f con a
	
	G.insArco(n4,n1,1);		//d con a
	G.insArco(n4,n6,1);		//d con f
	G.insArco(n4,n2,1);		//d con b
	G.insArco(n4,n5,1);		//d con e
	
	G.insArco(n2,n4,1);		//b con d
	G.insArco(n2,n5,1);		//b con e
	
	G.insArco(n5,n4,1);		//e con d
	G.insArco(n5,n2,1);		//e con b
	
	cout<<"Il numero di nodi del grafo e': "<<G.numNodi()<<endl;
	cout<<"Il numero di archi del grafo e': "<<G.numNodi()<<endl;
	
	
	GrafoList<string,double>::ListaNodi L = G.Adiacenti(n1);		//creazione di una lista di nodi adiacenti, partendo da N1
	GrafoList<string,double>::ListaNodiPos p;					//dichiarazione di un puntatore posizionale P alla lista dei nodi
	cout << "Adiacenti di " << G.leggiEtichetta(n1) << "--> ";		//stampa adiacenti del nodo N1
	p = L.begin();													//Posiziono p all'inizio della lista
	while (!L.end(p))												//fino a quando non arrivo alla fine della lista
	{	
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
		p = L.next(p);											//incremento il puntatore
    }
    cout<<endl;
    
    
	L=G.Adiacenti(n2);
    cout << "Adiacenti di " << G.leggiEtichetta(n2) << "--> ";
    p=L.begin();
    while (!L.end(p))												//fino a quando non arrivo alla fine della lista
	{	
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
		p = L.next(p);											//incremento il puntatore
    }
    
    cout<<endl;
    
    cout<<"Il peso dell'arco che va da "<<G.leggiEtichetta(n1)<<" a "<<G.leggiEtichetta(n2)<<" e': "<<G.leggiPeso(n1,n3)<<endl;
	
	
	
	
}
