//#include "GrafoMat.h"
#include "GrafoList.h"

#include <string>

using namespace std;

int main()
{
	GrafoList<string,double> G(10);		//DICHIARO UN GRAFO DI TIPO STRINGA
	
	GrafoList<string,double> G2(20);
	NodoG ng2;
	
	G2.insNodo(ng2);
	cout<<"STAMPO INDIRIZZO DEL GRAFO 2: "<<&G2<<endl;
	cout<<"STAMPO INDIRIZZO DI NG2: "<<ng2.getPuntatore()<<endl;

	NodoG n1,n2,n3,n4,n5,n6;			//DICHIARAZIONE DI DIFFERENTI NODI n1, n2, n3, n4, n5, n6
	
	if(G.vuoto()==true) cout<<"Il grafo risulta essere vuoto"<<endl;
	else cout<<"Il grafo non e' vuoto"<<endl;

	G.insNodo(n1);						//Al grafo inserisco il Nodo n1
	G.scriviEtichetta(n1,"a");			//Avvaloro l'etichetta n1 con la stringa "a"
	G.insNodo(n2);						//Al grafo inserisco il Nodo n2
	G.scriviEtichetta(n2,"b");			//Avvaloro l'etichetta n2 con la stringa "b"
	G.insNodo(n3);						//Al grafo inserisco il Nodo n3
	G.scriviEtichetta(n3,"c");			//Avvaloro l'etichetta n3
	G.insNodo(n4);						//Al grafo inserisco il Nodo n4
	G.scriviEtichetta(n4,"d");			//Avvaloro l'etichetta n4
	G.insNodo(n5);						//Al grafo inserisco il Nodo n5
	G.scriviEtichetta(n5,"e");			//Avvaloro l'etichetta n5
	G.insNodo(n6);						//Al grafo inserisco il Nodo n6
	G.scriviEtichetta(n6,"f");			//Avvaloro l'etichetta n6
	
	if(G.vuoto()==true) cout<<"Il grafo risulta essere vuoto"<<endl;
	else cout<<"Il grafo non e' vuoto"<<endl;


	//DEFINIZIONE DEGLI ARCHI TRA I NODI E I RELATIVI PESI
	G.insArco(n1,n2, 1.0);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n1,n3, 0.9);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n1,n5, 0.3);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n2,n4, 0.1);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n2,n6, 0.2);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n3,n4, 1.0);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n3,n6, 0.7);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n4,n1, 0.5);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n5,n2, 0.4);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n5,n3, 0.2);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n6,n4, 0.1);				//Inserisco un arco tra due nodi e ne inserisco il peso

	cout << "\nNumNodi " << G.numNodi();		//stampa il numero di nodi presenti nel grafo
	cout << "\nNumArchi " << G.numArchi();		//stampa il numero di archi presenti nel grafo

	//CANCELLAZIONE DI UN NODO
	G.cancNodo(n6);

	cout << "\nNumNodi " << G.numNodi() << endl;

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
    
    //TEST ESISTE ETICHETTA
    bool e_n=G.esisteNodo(n1);
    if(e_n)
    {
    	cout<<"Il nodo esiste"<<endl;
	}
	else
	{
		cout<<"Il nodo non esiste"<<endl;
	}
    
    //STAMPO INDIRIZZO DEL GRAFO
    cout<<"INDIRIZZO DEL GRAFO: "<<&G<<endl;
    cout<<n1.getPuntatore()<<endl;
    
    G.insArco(n2,ng2,5);
    
    //TEST ESISTE ARCO
    bool esiste=G.esisteArco(n1,n4);
    if(esiste)
    {
    	cout<<"ESISTE UN ARCO!"<<endl;
	}
	else
	{
		cout<<"NON ESISTE UN ARCO TRA I DUE NODI INSERITI"<<endl;
	}
	
	//TEST VERIFICA ESISTENODO - CANCELLAZIONE DEL NODO - NUOVA VERIFICA ESISTENODO (solo se un nodo ha nodi uscenti)
	e_n=G2.esisteNodo(ng2);
    if(e_n)
    {
    	cout<<"Il nodo esiste"<<endl;
	}
	else
	{
		cout<<"Il nodo non esiste"<<endl;
	}
	G2.cancNodo(ng2);
	e_n=G2.esisteNodo(ng2);
    if(e_n)
    {
    	cout<<"Il nodo esiste"<<endl;
	}
	else
	{
		cout<<"Il nodo non esiste"<<endl;
	}
}

