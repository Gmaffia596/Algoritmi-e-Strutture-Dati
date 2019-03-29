#ifndef _ALBERON_H_
#define _ALBERON_H_
#include "Cella.h"
#include <cassert>    
#include <iostream>
using namespace std;

template <class T> class Albero {
public:
// tipi
typedef T tipoelem;
typedef Cella<T>* Nodo; 

// costruttori e distruttori
Albero(); 
~Albero();
// operatori
void creaAlbero();
bool alberoVuoto();
void insRadice(Nodo);
Nodo radice();
Nodo padre(Nodo);
bool foglia(Nodo);
Nodo primoFiglio(Nodo);
bool ultimoFratello(Nodo);
Nodo succFratello(Nodo);
void insPrimoSottoalbero(Nodo,Albero<T>&);
void insSottoalbero(Nodo,Albero<T>&);
void cancSottoalbero(Nodo); //
// operazioni di lettura / scrittura sui nodi
void scriviNodo(Nodo,tipoelem);
tipoelem leggiNodo(Nodo);
// servizio
void stampa(Nodo,int); // stampa il sottoalbero di radice Nodo posto a livello int
// gli algoritmi di visita sono gli stessi degli alberi binari

private:
bool appartiene(Nodo);        
Nodo root; // un albero è identificato dalla sua radice
};

template <class T> Albero<T>::Albero()
{creaAlbero();}

template <class T> Albero<T>::~Albero()
{}

template <class T> void Albero<T>::creaAlbero()
{
  root=NULL;
}

template <class T> bool Albero<T>::alberoVuoto()
{
  return (root==NULL);
}

template <class T> void Albero<T>::insRadice(Nodo n)
{
   assert (alberoVuoto());
   root=n;
   root->setPRIMOFIGLIO(NULL);    // non ha figli
   root->setPROXFRATELLO(NULL);    // non ha fratelli           
   root->setPADRE(NULL);  // non ha genitore
}

template <class T> Cella<T>* Albero<T>::radice() 
{
    assert (!alberoVuoto());
    return (root);
}

template <class T> Cella<T>* Albero<T>::padre(Nodo n) 
{
      assert (n!=radice());
      assert (appartiene(n));
      return (n->getPADRE());
}

template <class T> bool Albero<T>::appartiene(Nodo n) 
{
      // va implementato il controllo se il nodo
      // appartiene all'albero
      return (true);
}

template <class T> bool Albero<T>::foglia(Nodo n) 
{
      assert(appartiene(n));
      return (n->getPRIMOFIGLIO()==NULL); // NODO FOGLIA SE NON HA FIGLI
      
}

template <class T> Cella<T>* Albero<T>::primoFiglio(Nodo n) 
{
      assert (appartiene(n));
      assert (n->getPRIMOFIGLIO()!=NULL);
      return (n->getPRIMOFIGLIO());
}

template <class T> bool Albero<T>::ultimoFratello(Nodo n) 
{
      assert (appartiene(n));
      return (n->getPROXFRATELLO()==NULL); // ULTIMO FRATELLO SE NON HA FRATELLI
}

template <class T> Cella<T>* Albero<T>::succFratello(Nodo n) 
{
      assert (appartiene(n));
      assert (!ultimoFratello(n));
      return (n->getPROXFRATELLO());
}

template <class T> void Albero<T>::insPrimoSottoalbero(Nodo n, Albero<T> &a) 
{
      assert (!a.alberoVuoto()); // a non è vuoto
      assert (appartiene(n)); // n è nell'albero corrente
      a.radice()->setPROXFRATELLO(n->getPRIMOFIGLIO());  // quello che era il primo figlio di n diventa fratello della radice di a           
      a.radice()->setPADRE(n); // n diventa padre della radice di a
      n->setPRIMOFIGLIO(a.radice()); // la radice di a diventa primo figlio di n
}

template <class T> void Albero<T>::insSottoalbero(Nodo n, Albero<T> &a) 
{
      assert (!a.alberoVuoto()); // a non è vuoto
      assert (appartiene(n)); // n è nell'albero corrente
      assert (radice()!=n); // n è nell'albero corrente
      a.radice()->setPROXFRATELLO(n->getPROXFRATELLO());  // quello che era il fratello di n diventa fratello della radice di a      
      // ERRATO a.radice()->setPADRE(radice()); // n diventa padre della radice di a
      a.radice()->setPADRE(n->getPADRE()); // il padre di n diventa padre della radice di a            
      n->setPROXFRATELLO(a.radice()); // la radice di a diventa primo figlio di n
}

template <class T> void Albero<T>::scriviNodo(Nodo n, tipoelem e) 
{
      assert (appartiene(n)); // n è nell'albero corrente
      n->setElemento(e);
}

template <class T> T Albero<T>::leggiNodo(Nodo n) 
{
      assert (appartiene(n)); // n è nell'albero corrente
      return (n->getElemento());
}

template <class T> void Albero<T>::stampa(Nodo n, int livello) 
{
   assert(appartiene(n));
   assert(livello>=0);
   if (alberoVuoto())
   {
      cout << "albero vuoto!" << endl;
      return;
   }
   const int Nspaces=4;
   int spaces=livello*Nspaces;
   // stampo il nodo 
   for (int i=1;i<spaces;i++) 
          cout << " "; 
   cout << leggiNodo(n) << endl; // stampo il nodo
   if (!foglia(n))
   {      
      livello++; // ed i suoi eventuali figli: passo al livello successivo
      stampa(primoFiglio(n),livello);
      Nodo iter=primoFiglio(n);
      bool ancora_fratelli = !ultimoFratello(iter);
      while (ancora_fratelli)
      {
            iter=succFratello(iter);
            stampa(iter,livello);
            ancora_fratelli=!ultimoFratello(iter);
      }      
   }      
}

template <class T> void Albero<T>::cancSottoalbero(Nodo n) 
{
      assert (appartiene(n)); // n è nell'albero corrente
      cout << "entro nella procedura per eliminare nodo: " << n->getElemento() << endl;
      // spezzo i legami tra n, il padre ed i fratelli
      if (radice()==n)
      {
         cout << "cancellazione dalla radice!" << endl;
         delete root;
      }
      else
      {
         if (n==primoFiglio(padre(n))) // n è il primo figlio
         {
            cout << "cancello un primogenito!" << endl;
            if (ultimoFratello(n)) 
               padre(n)->setPRIMOFIGLIO(NULL);
            else
               padre(n)->setPRIMOFIGLIO(succFratello(n));// allora ha un fratello che diventa il primo figlio         
         }
         else
         {
            // sono nel ramo else dunque n non è primo figlio            
            Nodo prec=primoFiglio(padre(n));
            cout << "prec: " << leggiNodo(prec) << endl;
            Nodo current=succFratello(prec);
            cout << "current: " << leggiNodo(current) << endl;
            while (current!=n)
            {
               prec=current;
               current=succFratello(current);
            }
            cout << "trovato!" << endl;
            // current=n
            if (ultimoFratello(n))
               prec->setPROXFRATELLO(NULL);
            else
               prec->setPROXFRATELLO(succFratello(n));            
         }
      }
      delete n;
}



#endif /* _ALBERON_H_ */
