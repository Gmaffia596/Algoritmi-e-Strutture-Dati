#include "TreeList.h"
#include <string>

using namespace std;

int main()
{

	TreeList<string> Albero; //creazione di un albero n-ario di char

	TreeList<string>::node n; //definizione del nodo N di tipo char dell'albero n-ario
	Albero.insRoot(n);		//inserimento di N come radice dell'albero n-ario
	Albero.writeNode(Albero.root(),"Angelo Ruggieri 50");	//avvaloramento del nodo radice con il carattere A
	
	//INSERIMENTO PRIMO FIGLIO
	Albero.insFirst(Albero.root(), "Pino Ruggieri");	//inserimento del primo figlio (partendo da sinistra) del carattere B
	//INSERIMENTO SECONDO FIGLIO
	Albero.insFirst(Albero.root(), "Mauro Ruggieri");	//inserimento del secondo figlio (partendo da sinistra) del carattere C		a[c,b]
	//INSERIMENTO TERZO FIGLIO
	Albero.insFirst(Albero.root(), "Betty Ruggieri");

	
	
	//INSERIMENTO PRIMO FIGLIO DI PINO RUGGIERI
	n = Albero.root();	//n punta alla radice
	n = Albero.firstChild(n);		//n punta al primofiglio di N (BETTY RUGGIERI)
	n=Albero.nextSibling(n);
	n=Albero.nextSibling(n);
	Albero.insFirst(n,"Angelo Ruggieri 97");
	//INSERIMENTO SECONDO FIGLIO DI PINO RUGGIERI
	n=Albero.root();
	n=Albero.firstChild(n);
	n=Albero.nextSibling(n);
	n=Albero.nextSibling(n);
	Albero.insFirst(n,"Vanessa Ruggieri");
	
	//INSERIMENTO PRIMO FIGLIO DI MAURO RUGGIERI
	n=Albero.root();
	n=Albero.firstChild(n);
	n=Albero.nextSibling(n);
	Albero.insFirst(n,"Angelo Ruggieri 2011");
	
	//INSERIMENTO PRIMO FIGLIO DI BETTY RUGGIERI
	n=Albero.root();
	n=Albero.firstChild(n);
	Albero.insFirst(n,"Pamela Sasso");
	

	

	std::cout<<"Stampa dell'albero n-ario"<<std::endl;
	Albero.print();	

	n = Albero.root();	//n punta alla radice dell'albero
	n = Albero.firstChild(n);	//n (CHE PUNTA ALLA RADICE che sarebbe A) punta al primo figlio di n, che sarebbe c
	Albero.removeSubTree(n);	//rimuovo il sottoalbero di c, compresa la radice C

	std::cout<<"Stampa dell'albero n-ario dopo la rimozione di Betty Ruggieri e del suo sottoalbero"<<std::endl;
	Albero.print();	

	return 0;
} 
