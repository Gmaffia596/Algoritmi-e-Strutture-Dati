#include <iostream>
#include "zero_one_binary_tree.h"
#include "Bin_treec.h"
#include <string>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Bin_treec<int> T; //CREAZIONE dell'albero binario di tipo intero
	
	typename Bin_treec<int>::Nodo n1, n2, n3; //definizione del nodo STRINGA nodo 1, nodo 2

	
	T.ins_root(n1);
	T.write(T.root(),0);
	n1 = T.root(); //n1 PUNTA alla radice dell'albero
	//GESTIONE DELLA SENTINELLA
	T.ins_sx(n1); //INSERISCO IL NODO FIGLIO SINISTRO
	T.ins_dx(n1); //INSERISCO IL NODO FIGLIO DESTRO
	T.write(T.sx(n1),1);	//AVVALORO il nodo figlio sinistro di n1
	//n1=T.dx(n1);	//n1 punta al figlio destro di n1
	T.write(T.dx(n1),1); //AVVALORO il nodo figlio destro di n1
	n2=T.dx(n1);		//dichiaro il nodo n2 come figlio destro di n1 (di Mauro Ruggieri) -> per poter inserire successivamente i suoi figli
	
	
	n1=T.sx(n1);
	T.ins_sx(n1);
	T.ins_dx(n1);
	T.write(T.sx(n1),0);
	/*n3=T.sx(T.sx(T.root()));
	T.ins_sx(n3);
	T.write(T.dx(n3),6);*/
	T.write(T.dx(n1),0);
	T.ins_sx(n2);
	T.write(T.sx(n2),0);
	T.ins_dx(n2);
	T.write(T.dx(n2),0); //OK
	//T.print(); //stampo l'albero binario
	cout << T;	//	<- RIDEFINIZIONE FUNZIONANTE DELL'OPERATORE <<
	
	//ESERCIZIO 25/09/2017
	zero_one_binary_tree <int> zerouno;
	int contatore= zerouno.zero_nodes(T);
	cout<<"Il numero di zeri e': "<<contatore<<endl;
	
	bool esito = zerouno.is_zero_one(T);
	if(esito) 
	{
		cout<<"L'albero e' in forma ZERO_ONE"<<endl;
	}
	else
	{
		cout<<"L'albero NON e' in forma ZERO_ONE"<<endl;
	}
	return 0;
}
