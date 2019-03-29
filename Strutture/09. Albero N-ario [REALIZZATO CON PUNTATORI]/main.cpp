#include <cstdlib>
#include <iostream>
#include "AlberoN.h"
#include "Cella.h"
#include "codavt.h"

using namespace std;

Coda<int> riempi()
{
   // inserimento in ampiezza
   Coda<int> c;
   c.inCoda(5);
   c.inCoda(4);
   c.inCoda(15);
   c.inCoda(6);
   c.inCoda(8);
   c.inCoda(9);
   c.inCoda(21);
   c.inCoda(20);
   c.inCoda(12);
   c.inCoda(11);
   c.inCoda(3);   
   return(c);
}

void riempi(Coda<int> dati,Albero<int>& t)
{
      if (!t.alberoVuoto())
      {
         Coda<Albero<int>::Nodo> s;
         s.inCoda(t.radice());
         while (!s.codaVuota()){
               Albero<int>::Nodo nn=s.leggiCoda(); // visito un nodo ...
               t.scriviNodo(nn,dati.leggiCoda());
               s.fuoriCoda();
               dati.fuoriCoda();
               if (!t.foglia(nn))
               {
                  s.inCoda(t.primoFiglio(nn)); // ... e accodo i figli di nn
                  bool ancora_fratelli=!t.ultimoFratello(t.primoFiglio(nn));
                  Albero<int>::Nodo next=t.primoFiglio(nn);
                  while (ancora_fratelli)
                  {
                     next=t.succFratello(next);
                     s.inCoda(next);
                     ancora_fratelli=!t.ultimoFratello(next);
                  }
               }               
         }
      }
}

Albero<int> acquisisci(int nfigli)
{
    Albero<int> tree;
    tree.insRadice(new Cella<int>);
    tree.radice()->setElemento(0);
    if (nfigli>0)
    {    
         Albero<int> sotto;
         Albero<int>::Nodo iter = new Cella<int>;
         sotto.insRadice(iter);
         sotto.radice()->setElemento(0);
         tree.insPrimoSottoalbero(tree.radice(),sotto);
         for (int i=1;i<=nfigli-1;i++)
         {
             Albero<int> figlio;
             figlio.insRadice(new Cella<int>);
             figlio.radice()->setElemento(0);
             tree.insSottoalbero(iter,figlio);
             iter=figlio.radice();
         }
    }  
    return tree;             
}
                  
int main(int argc, char *argv[])

{
    cout << "creazione albero" << endl;
    Albero<int> tree=acquisisci(0); // radice       
    Albero<int> t1=acquisisci(1);
    tree.insPrimoSottoalbero(tree.radice(),t1);
    Albero<int>::Nodo next=t1.radice();        
    Albero<int> t2=acquisisci(0);
    tree.insSottoalbero(next,t2);
    next=t2.radice();
    t2=acquisisci(2);
    tree.insSottoalbero(next,t2);
    t2=acquisisci(3);
    next=tree.primoFiglio(tree.radice());
    next=tree.primoFiglio(next);
    tree.insSottoalbero(next,t2);    
    // tree.stampa(tree.radice(),0);
    Coda<int> dati=riempi();    
    riempi(dati,tree);
    tree.stampa(tree.radice(),0);
    next=tree.radice();
    // decidiamo quale sottoalbero cancellare
    next=tree.primoFiglio(next);
    cout << "potatura nodo:" << next->getElemento() << endl;        
    tree.cancSottoalbero(next);
    cout << "dopo potatura nodo:" << next->getElemento() << endl;
    tree.stampa(tree.radice(),0);
    next = next=tree.primoFiglio(tree.radice());
    next = tree.succFratello(next);
    tree.stampa(next,0);
    tree.cancSottoalbero(next);
    tree.stampa(tree.radice(),0);    
    system("PAUSE");
    return EXIT_SUCCESS;
}
