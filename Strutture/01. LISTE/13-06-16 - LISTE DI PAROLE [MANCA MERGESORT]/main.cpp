#include <iostream>
#include "eo_strings.h"

using namespace std;

int main(int argc, char** argv) 
{
	eo_strings e,e2;
	e.inserisci("Pipo");
	e.inserisci("Ciao");
	//e.rimuovi("Ciao");
	
	e.inserisci("Pippo");
	e.inserisci("A");
	e.inserisci("Bac");
	e.inserisci("wertyui");
	//e.rimuovi('C');
	
	cout<<"Il numero di stringhe di lunghezza pari sono: "<<e.freq_pari()<<endl;
	
	e.stampa_dispari();
	e.visualizza_dispari();
	e.stampa_dispari();
	
	
	
	e.stampa_pari();
	return 0;
}
