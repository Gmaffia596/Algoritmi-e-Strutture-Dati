#include <iostream>
#include <stdlib.h>
#include "balanced_treec.h"
#include "Bin_treec.h"
using namespace std;



int main() {

	Bin_treec<int> asd;

	typename Bin_treec<int>::Nodo n1,n2,n3;

	asd.ins_root();
	asd.write(asd.root(),1);

	n1=asd.root();

	asd.ins_sx(n1);
	asd.ins_dx(n1);
	asd.write(asd.sx(n1),2);
	asd.write(asd.dx(n1),3);

	n2=asd.sx(n1);
	asd.ins_sx(n2);
	asd.ins_dx(n2);
	asd.write(asd.sx(n2),4);
	asd.write(asd.dx(n2),5);

	n3=asd.dx(n1);
	asd.ins_sx(n3);
	asd.ins_dx(n3);
	asd.write(asd.sx(n3),6);
	asd.write(asd.dx(n3),7);



	//asd.print();
	asd.stampa_albero_binario_pre_order(n1);
	//cout<<asd <<"\n";
	getchar();

	cout<<"tutti i nodi non foglia hanno esattamente due figli?\n";
	balanced_tree<int> asdBilanciato;
	bool risultato = asdBilanciato.complete_nodes(asd);
	if(risultato){
		cout<<"SI"<<"\n";
	}else{
		cout<<"NO"<<"\n";
	}

	getchar();

	cout<<"l'albero è bilanciato?\n";
	bool bil = asdBilanciato.is_height_balanced(asd);
	if(bil){
		cout<<"SI\n";
	}else{
		cout<<"NO\n";
	}

	getchar();
}


