#include <iostream>
#include "TreeList.h"
#include "util_n_tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	TreeList<char> Tree;
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
	
	n=Tree.firstChild(Tree.root());
	n=Tree.nextSibling(n);
	Tree.insFirst(n,'z');
	n=Tree.nextSibling(n);
	Tree.insFirst(n,'h');
	n=Tree.firstChild(n);
	Tree.insFirst(n,'y');
	
	

	std::cout<<"Stampa dell'albero n-ario"<<std::endl;
	Tree.print();
	
	util_n_tree<char> utilTree;
	int nFoglie = utilTree.n_leaf(Tree);
	cout<<"Numero di foglie: "<<nFoglie<<endl;
	
	int nNodi = utilTree.n_level(Tree,1);
	if(nNodi!=-1) cout<<"Nodi presenti al livello desiderato: "<<nNodi<<endl;
	
	
	//cout<<"Valore: "<<utilTree.n_level(Tree,3)<<endl;
	
	
	return 0;
}
