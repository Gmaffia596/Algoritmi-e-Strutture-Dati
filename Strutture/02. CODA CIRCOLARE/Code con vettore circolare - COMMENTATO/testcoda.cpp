#include "codavt.cpp"
#include <iostream>

using namespace std;

int main()
{

  Coda<int> C(3); //creo una coda di interi di 3 elementi
  
  C.inCoda(1);
  C.inCoda(2);
  C.inCoda(3);
 // C.inCoda(4); questo inserimento causa un errore - la situazione è [1-2-3]
  cout << " " << C.leggiCoda()<<endl; //mi stampa 1
  C.fuoriCoda(); //vado ad eliminare 1 dalla testa, facendo diventare il primo elemento 2 - la situazione è 2-3
  C.inCoda(4); //la situazione è 2-3-4 perchè ho incodato il 4
  cout << " " << C.leggiCoda()<<endl; //mi stampa 2, che sarebbe il primo elemento della lista
  C.fuoriCoda(); //vado ad eliminare 2 dalla testa, facendo diventare il primo elemento 3, la situazione 3-4
  cout << " " << C.leggiCoda()<<endl; //mi stampa 3
  C.inCoda(5); //la situazione sarà 3-4-5
  C.fuoriCoda(); //rimuovo 3 dalla coda, facendo diventare la seguente situazione: 4-5
  cout << " " << C.leggiCoda()<<endl; //mi stampa 4
  C.fuoriCoda(); //rimuovo 4, facendo diventare la seguente situazione 5
  cout << " " << C.leggiCoda()<<endl; //mi stampa 5
  C.fuoriCoda(); //rimuovo 5, ottenendo la lista vuota
  
  return 0;
}
