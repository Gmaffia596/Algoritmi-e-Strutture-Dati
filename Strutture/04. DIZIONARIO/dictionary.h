/* A dictionary is a collection of pairs of the form (k,v), where k is a key and v is the value
 * associated with the key k (equivalently, v is the value whose key is k). 
 */

/* The pair */

#ifndef _DICTIONARY_H
#define _DICTIONARY_H

template<class K, class E>
struct mypair 
{
  K first; //first è la chiave identificativa
  E second; // second è l'attributo
  bool never_used; //campo booleano inserito secondo la traccia per gestire le eliminazioni

  // methods
  mypair() {} //costruttore vuoto
  
  mypair(mypair<K,E>& the_pair) //Secondo costruttore che inizializza la coppia ad una coppia che viene passata per parametro
  {
    first = the_pair.first; //first chiave
    second = the_pair.second; //second attributo
    never_used=true;
  }
};


template <class K, class E>
class dictionary //definizione della classe
{

public:
  virtual ~dictionary() {} //DISTRUTTORE
  
  virtual void create() = 0;	//viene creato un dizionario vuoto
  virtual bool empty() const = 0;	// ritorna true se il dizionario è vuoto
  virtual int size() const = 0;		//ritorna il numero di elementi salvati nel dizionario
  virtual mypair< K, E>* find(const K& k) const = 0;	//ritorna la coppia con la chiave K indicata
  virtual void insert( mypair< K, E>& p) = 0;	//inserisce una coppia p all'interno del dizionario	
  virtual void erase(const K& k) = 0;	//cancella una coppia con la chiave K indicata
  virtual void modify(const K& k, const E& e) = 0; //modifica il valore della coppia (indicata con la chiave K) assegnando il valore e
};

#endif
