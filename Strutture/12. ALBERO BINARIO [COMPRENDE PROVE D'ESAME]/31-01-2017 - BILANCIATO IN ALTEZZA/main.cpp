#include <iostream>
#include "balanced_tree.h"
#include "Bin_treec.h"
#include <string>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	Bin_treec<int> T; //CREAZIONE dell'albero binario di tipo intero
	typename Bin_treec<int>::Nodo n1, n2, n3; //definizione del nodo STRINGA nodo 1, nodo 2

	
	T.ins_root(n1);
	T.write(T.root(),1);
	n1 = T.root(); //n1 PUNTA alla radice dell'albero
	//GESTIONE DELLA SENTINELLA
	T.ins_sx(n1); //INSERISCO IL NODO FIGLIO SINISTRO
	T.ins_dx(n1); //INSERISCO IL NODO FIGLIO DESTRO
	T.write(T.sx(n1),2);	//AVVALORO il nodo figlio sinistro di n1
	//n1=T.dx(n1);	//n1 punta al figlio destro di n1
	T.write(T.dx(n1),3); //AVVALORO il nodo figlio destro di n1
	n2=T.dx(n1);		//dichiaro il nodo n2 come figlio destro di n1 (di Mauro Ruggieri) -> per poter inserire successivamente i suoi figli
	
	
	n1=T.sx(n1);
	T.ins_sx(n1);
	T.ins_dx(n1);
	T.write(T.sx(n1),4);
	/*n3=T.sx(T.sx(T.root()));
	T.ins_sx(n3);
	T.write(T.dx(n3),6);*/
	T.write(T.dx(n1),5);
	
	T.ins_dx(n2);
	T.write(T.dx(n2),6);
	//T.print(); //stampo l'albero binario
	cout << T;	//	<- RIDEFINIZIONE FUNZIONANTE DELL'OPERATORE <<
	
	//ESERCIZIO LAB 31/01/2017
	balanced_tree<int> alberobilanciato;
	bool esito = alberobilanciato.complete_nodes(T);
	if(esito) cout<<"vero"<<endl;
	else cout<<"falso"<<endl;
	//alberobilanciato.previsita(T,T.root());
	
	
	//altro punto
	bool bilanciato = alberobilanciato.is_height_balanced(T);
	if(bilanciato) cout<<"L'albero e' bilanciato"<<endl;
	else cout<<"Non bilanciato"<<endl;
	
	return 0;
}
