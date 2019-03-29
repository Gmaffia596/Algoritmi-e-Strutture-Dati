#ifndef _CELLA_H
#define _CELLA_H
// stessa classe di ADT albero binario
// diversa denominazione dei campi
template <class T> class Cella
  {
  public:
    typedef T tipoelem;
    Cella();
    Cella(tipoelem);
    void setElemento(tipoelem);
    tipoelem getElemento() const;
    void setPRIMOFIGLIO(Cella<T>*);    // primo figlio
    void setPROXFRATELLO(Cella<T>*);   // fratello più prossimo
    void setPADRE(Cella<T>*);          // padre
    Cella<T>* getPRIMOFIGLIO() const;
    Cella<T>* getPROXFRATELLO() const;
    Cella<T>* getPADRE() const;
    bool operator ==(Cella<T>);
    bool operator <=(Cella<T>);
  private:
    tipoelem elemento;
    Cella<T>* PRIMOFIGLIO;
    Cella<T>* PROXFRATELLO;
    Cella<T>* PADRE;
    
  };

// Implementazione della classe Cella
// --------------------------------------

// costruttori
template <class T> Cella<T>::Cella(){
         PRIMOFIGLIO=NULL;
         PROXFRATELLO=NULL;
         PADRE=NULL;
}

template <class T> Cella<T>::Cella(tipoelem e)
{
  elemento = e;
}

template <class T> void Cella<T>::setElemento(tipoelem label)
{
  elemento = label;
}

template <class T>  T Cella<T>::getElemento() const
{
    return elemento;
}

template <class T> void Cella<T>::setPRIMOFIGLIO(Cella<T>* p)
{
  PRIMOFIGLIO=p;
}

template <class T> void Cella<T>::setPROXFRATELLO(Cella<T>* p)
{
  PROXFRATELLO=p;
}

template <class T> void Cella<T>::setPADRE(Cella<T>* p)
{
  PADRE=p;
}

template <class T> Cella<T>* Cella<T>::getPRIMOFIGLIO() const
  {
    return PRIMOFIGLIO;
  }

template <class T> Cella<T>* Cella<T>::getPROXFRATELLO() const
  {
    return PROXFRATELLO;
  }
  
  template <class T> Cella<T>* Cella<T>::getPADRE() const
  {
    return PADRE;
  }
  
// sovraccarico dell'operatore ==
template <class T> bool Cella<T>::operator==(Cella<T> cella)
{
  return (getElemento == cella.getElemento);
}

template <class T> bool Cella<T>::operator<=(Cella<T> cella)
{
  return (getElemento <= cella.getElemento);
}
#endif // _CELLA_H
