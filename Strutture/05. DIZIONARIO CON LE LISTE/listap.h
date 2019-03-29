#ifndef _LISTAP_H
#define _LISTAP_H

#include "cellalp.h"
#include <iostream>
using namespace std;

template<class T>
class circLista //CREAZIONE DELLA LISTA CIRCOLARE CHE INGLOBA ELEMENTI DI TIPO CELLALP
  {
  public:
    circLista();	//Costruttore della lista circolare
    ~circLista();	//Distruttore della lista circolare
    //----- circLista(const circLista<T>&);   
    
    /* posizione è un puntatore a cella */
    typedef Cella<T>* posizione;
    typedef T tipoelem;
    /* Prototipi degli operatori */
    void crealista(); //CREAZIONE DELLA LISTA
    bool listavuota() const; //TEST SE LISTA VUOTA O MENO
    tipoelem leggilista(posizione) const; //RITORNA L'ELEMENTO PRESENTE IN POSIZIONE posizione
    void scrivilista(tipoelem, posizione); //SCRIVO NELLA LISTA L'ELEMENTO IN POSIZIONE posizione
    posizione primoLista() const; //RITORNO LA POSIZIONE DELL'ELEMENTO PRIMO NELLA LISTA
    bool finelista(posizione) const; //RITORNA IL VALORE BOOLEANO SE CI TROVIAMO ALLA FINE DELLA LISTA
    posizione succlista(posizione) const; //RITORNA LA POSIZIONE SUCCESSIVA RELATIVA ALLA POSIZIONE ATTUALE
    posizione preclista(posizione) const; //RITORNA LA POSIZIONE PRECEDENTE RELATIVA ALLA POSIZIONE ATTUALE
    void inslista(tipoelem,posizione&);	//INSERISCE L'ELEMENTO NELLA POSIZIONE INDICATA
    void canclista(posizione&); //CANCELLA L'ELEMENTO PRESENTE NELLA POSIZIONE
    // funzioni di servizio
    void stampaLista();		//STAMPO LA LISTA DI TUTTI GLI ELEMENTI PRESENTI
  private:
    posizione lista; //la lista è un puntatore ad oggetto Cella
  };

/* Liste: Rappresentazione collegata circolare (con sentinella)
 * realizzata mediante doppi puntatori (o simmetrica)
 */

template <class T> circLista<T>::circLista() //COSTRUTTORE
{crealista();}

template <class T> circLista<T>::~circLista() //DISTRUTTORE con implementazione
{
    while (lista->getSucc() != lista->getPrec()) 
    {
       Cella<T>* posizione = lista->getSucc();
       canclista(posizione);
    }   
    delete lista;
}

template <class T> void circLista<T>::crealista() //CREA la lista
{
  T ElementoNullo; //creo la sentinella 
  lista = new Cella<T>; //alloco la lista
  lista->setElemento(ElementoNullo); //inserisco nella lista la sentinella
  lista->setSucc(lista);
  lista->setPrec(lista);
  //la sentinella punta a se stessa
}

template <class T> bool circLista<T>::listavuota() const
  {
    return ((lista->getSucc() == lista) &&  (lista->getPrec()==lista)); //se la sentinella punta a se stessa, allora è vuota
  }

template <class T> Cella<T>* circLista<T>::primoLista() const
  {
    return lista->getSucc(); //ritorno l'elemento iniziale della lista
  }

template <class T> Cella<T>* circLista<T>::succlista(posizione p) const
  {
    return p->getSucc(); //incremento la posizione al successivo
  }

template <class T> Cella<T>* circLista<T>::preclista(posizione p) const
  {
    return p->getPrec(); //decremento la posizione al precedente
  }

template <class T>  bool circLista<T>::finelista(posizione p) const
  {
    return (p==lista); //ritorno un valore booleano se sono arrivato, con tale posizione, alla fine della lista
  }

template <class T> T circLista<T>::leggilista(posizione p) const
  {
    return p->getElemento(); //leggo l'elemento puntato da P
  }

template <class T> void circLista<T>::scrivilista(tipoelem a, posizione p)
{
  p->setElemento(a); //scrivo nella lista, in posizione P, l'elemento
}

template <class T> void circLista<T>::inslista(tipoelem a, posizione &p) //INSERIMENTO DI UN NODO NELLA LISTA
{  
  Cella<T>* temp = new Cella<T>; //creo una cella temporanea
  temp->setElemento(a); //setto il valore
  //EFFETTUO IL COLLEGAMENTO
  temp->setPrec(p->getPrec());
  temp->setSucc(p);
  (p->getPrec())->setSucc(temp);
  p->setPrec(temp);
  p=temp; // se p era la posizione dell'elemento n-mo, adesso lo è temp 
}

template <class T> void circLista<T>::canclista(posizione &p) //CANCELLO UN NODO NELLA LISTA
{
  Cella<T>* temp = new Cella<T>; //creo una cella temporanea
  temp=p; //porto il puntatore a puntare alla cella di posizione P
  //collego la precedente a P con il successivo di P
  (p->getSucc())->setPrec(p->getPrec());
  (p->getPrec())->setSucc(p->getSucc());
  p=p->getSucc();
  //RIMUOVO IL NODO PUNTATO DA TEMP, ORMAI SCOLLEGATO DALLA LISTA
  delete(temp);
}

template <class T> void circLista<T>::stampaLista() //stampo il contenuto della lista
{
  cout<<"[";
  Cella<T>* indice=primoLista();
  while (!finelista(indice))
  {
      cout << leggilista(indice);
      if (!finelista(succlista(indice)))
        cout << ", ";
      indice = succlista(indice);
      
    }
  cout<<"]\n";
}

#endif // _LISTAP_H
