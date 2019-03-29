#include "TreeList.h"

int main()
{

	TreeList<char> Tree; //creazione di un albero n-ario di char

	TreeList<char>::node n; //definizione del nodo N di tipo char dell'albero n-ario
	Tree.insRoot(n);		//inserimento di N come radice dell'albero n-ario
	Tree.writeNode(Tree.root(),'a');	//avvaloramento del nodo radice con il carattere A
	Tree.insFirst(Tree.root(), 'b');	//inserimento del primo figlio (partendo da sinistra) del carattere B
	Tree.insFirst(Tree.root(), 'c');	//inserimento del secondo figlio (partendo da sinistra) del carattere C		a[c,b]

	n = Tree.root();	//n punta alla radice
	n = Tree.firstChild(n);		//n punta al primofiglio di N 

	Tree.ins(n, 'd');		//dopo il nodo N (c) inserisco come successivo il nodo con il carattere D	a[c,d,b]
	n = Tree.root();		//n punta alla radice
	n = Tree.firstChild(n);	//n punta al primo figlio di n (c)
	Tree.insFirst(n, 'e');	//al nodo N inserisco come primo figlio il nodo con carattere E		c[e]
	Tree.insFirst(n, 'f');	//al nodo N inserisco come primo figlio, spostando quello già esistente, il nodo con carattere F	c[f,e]

	std::cout<<"Stampa dell'albero n-ario"<<std::endl;
	Tree.print();	

	n = Tree.root();	//n punta alla radice dell'albero
	n = Tree.firstChild(n);	//n (CHE PUNTA ALLA RADICE che sarebbe A) punta al primo figlio di n, che sarebbe c
	Tree.removeSubTree(n);	//rimuovo il sottoalbero di c, compresa la radice C

	std::cout<<"Stampa dell'albero n-ario dopo la rimozione di C e del suo sottoalbero"<<std::endl;
	Tree.print();	

	return 0;
}
