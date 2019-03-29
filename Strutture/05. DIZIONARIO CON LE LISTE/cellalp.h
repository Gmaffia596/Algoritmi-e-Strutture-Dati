#ifndef _CELLALP_H
#define _CELLALP_H

template <class T> class Cella //DEFINIZIONE DEL TIPO DI DATO CELLA
  {
  public:
    typedef T tipoelem; //tipo T generico
    Cella(); //COSTRUTTORE
    Cella(tipoelem); //COSTRUTTORE in base al tipo di dato
    void setElemento(tipoelem); //setto l'elemento della cella con l'elemento passato come parametro
    tipoelem getElemento() const; //restituisco l'elemento contenuto della cella
    void setSucc(Cella*);	//setto il puntatore al successivo elemento della lista
    Cella* getSucc() const; //mi restituisce il puntatore al successivo elemento della lista
    void setPrec(Cella*); //Setto il puntatore al precedente elemento della lista
    Cella* getPrec() const; //mi restituisce il puntatore al precedente elemento della lista
    bool operator ==(Cella); //ridefinizione dell'operatore == per controllare se due celle sono uguali (SOVRACCARICO)
  
  private:
    tipoelem elemento; //definizione dell'elemento (CAMPO DATO)
    Cella* prec; //definizione del puntatore all'elemento precedente
    Cella* succ; //definizione del puntatore all'elemento successivo
  };

// Implementazione della classe CellaLista
// --------------------------------------

// costruttori
template <class T> Cella<T>::Cella() //COSTRUTTORE
{}

template <class T> Cella<T>::Cella(tipoelem e) //SECONDO COSTRUTTORE a cui passo l'elemento E
{
  elemento = e;
}

template <class T> void Cella<T>::setElemento(tipoelem label) //SET del campo dato della cella costruita
{
  elemento = label;
}

template <class T>  T Cella<T>::getElemento() const //GET del campo dato della cella costruita
{
    return elemento;
}

template <class T> void Cella<T>::setSucc(Cella* p) //SET del puntatore all'elemento successivo 
{
  succ=p;
}

template <class T> Cella<T>* Cella<T>::getSucc() const //GET del puntatore all'elemento successivo 
  {
    return succ;
  }

template <class T> void Cella<T>::setPrec(Cella* p) //SET del puntatore all'elemento precedente 
{
  prec=p;
}

template <class T> Cella<T>* Cella<T>::getPrec() const //GET del puntatore all'elemento precedente 
  {
    return prec;
  }

// sovraccarico dell'operatore ==
template <class T> bool Cella<T>::operator==(Cella cella)
{
  return (getElemento == cella.getElemento);
}


#endif // _CELLALP_H
