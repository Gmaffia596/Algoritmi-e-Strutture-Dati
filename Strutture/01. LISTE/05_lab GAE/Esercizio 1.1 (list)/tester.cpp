#include "Ordered_list.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Ordered_list<int> lista_ordinata;
	lista_ordinata.insert(1);
	lista_ordinata.outputList();
	lista_ordinata.insert(3);
	lista_ordinata.outputList();
	lista_ordinata.insert(2);
	lista_ordinata.outputList();
}
