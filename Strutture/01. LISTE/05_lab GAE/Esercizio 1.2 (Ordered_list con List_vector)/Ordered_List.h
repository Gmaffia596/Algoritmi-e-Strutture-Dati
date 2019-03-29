#ifndef _ORDERED_LIST_H
#define _ORDERED_LIST_H

#include "Linear_List.h"

template< class T >
class Ordered_list : public Linear_list<T, int>
{
	public:
		typedef typename Linear_list<T, int>::value_type value_type;
		typedef typename Linear_list<T, int>::position position;
	
		// costruttori
		Ordered_list();
		Ordered_list(int);
		// costruttore per copia
		Ordered_list(const Ordered_list<T>& );
		//distruttore
		~Ordered_list();
	
		// operatori
		void create();
		bool empty() const;
		value_type read(position) const;
		void write(const value_type &, position);
		void insertOrd(const value_type &);
		void insert(const value_type&, position);
		position begin() const;
		position last() const;
		bool end(position) const;
		position next(position) const;
		position previous(position) const;
		void erase(position);
		bool isPalindrome();
		bool search(const value_type);
		void merge(Ordered_list<T>&);

		// sovraccarico di operatori
		Ordered_list<T>& operator=(const Ordered_list<T>&); // the assignment operator
		bool operator==(const Ordered_list<T> &) const; // tests two list for equality

	private:
		void change_dimension_(T*& , int , int );
		value_type* elements_;
		int length_; // the length of the list
		int array_dimension_; // array's dimension
};

template< class T >
class List_vector : public Linear_list<T, int>
{
 	public:
		typedef typename Linear_list<T, int>::value_type value_type;
		typedef typename Linear_list<T, int>::position position;
	
		// costruttori
		List_vector();    
		List_vector(int); 
		// costruttore per copia
		List_vector(const List_vector<T>& ); 
		//distruttore
		~List_vector();   
		
		// operatori
		void create();
		bool empty() const;
		value_type read(position) const;
		void write(const value_type &, position);
		position begin() const;
		position last() const;
		bool end(position) const;
		position next(position) const;
		position previous(position) const;
		void insert(const value_type &, position);
		void erase(position);
		
		void invert();
		bool isPalindrome();
	
		// sovraccarico di operatori
		List_vector<T>& operator=(const List_vector<T>&); // the assignment operator
		bool operator==(const List_vector<T> &) const; // tests two list for equality

 	private:
		void change_dimension_(T*& , int , int );
		value_type* elements_;
		int length_; // the length of the list
		int array_dimension_; // array's dimension
};

// costruttore
template< class T >
Ordered_list< T >::Ordered_list()
{
  array_dimension_ = 10;
  this->create();
}

// costruttore
template< class T >
Ordered_list< T >::Ordered_list(int dim)
{
  array_dimension_ = dim;
  this->create();
}

/* Il costruttore per copia effettua una copia o clone di un oggetto.  
 * Questo costruttore viene invocato, per esempio, quando un oggetto viene passato 
 * per valore ad una funzione o quando una funzione restituisce un oggetto. 
 */
template< class T >
Ordered_list< T >::Ordered_list(const Ordered_list<T>& Lista)
{
  	this->array_dimension_ = Lista.array_dimension_;
  	this->length_ = Lista.length_;
  	this->elements_ = new T[array_dimension_];
  	for (int i=0; i<Lista.array_dimension_; i++)
    this->elements_[i] = Lista.elements_[i];
}

// distruttore
template< class T >
Ordered_list< T >::~Ordered_list()
{
	delete elements_;
}

// operatori
template< class T >
void Ordered_list< T >::create()
{
  this->elements_ = new T[array_dimension_];
  this->length_ = 0;
}

template< class T >
bool Ordered_list< T >::empty() const
{
    return(length_ == 0);
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::begin() const
{
	return(1); // e quindi pos(1)=pos(n+1) se la lista -Ah vuota (n=0)
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::last() const
{
	return(length_); 
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::next(position p) const
{
	if ( (0 < p) && (p < length_+1)) // precondizione
		return(p+1);
	else
		return(p);
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::previous(position p) const
{
	if ( (1 < p) && (p < length_+1)) // precondizione
		return(p-1);
	else
		return(p);
}

template< class T >
bool Ordered_list< T >::end(position p) const
{
	if ( (0 < p) && (p <= length_+1)) // precondizione
		return( p == length_+1);
	else
		return(false);
}

template< class T >
typename Ordered_list< T >::value_type Ordered_list< T >::read(position p) const
{
	if ( (0 < p) && (p < length_+1)) // precondizione
		return(elements_[p-1]);
}

template< class T >
void Ordered_list< T >::write(const value_type &a, position p)
{
  if ( (0 < p) && (p < length_+1)) // precondizione
    elements_[p-1] = a;
}

template< class T >
void Ordered_list< T >::insert(const value_type &a, position p)
{
  	if (length_ == array_dimension_)
  	{
    	change_dimension_(elements_, array_dimension_, array_dimension_ * 2);
    	array_dimension_ = array_dimension_ * 2;
  	}
  	if ( (0 < p) && (p <= length_+1))
	{ // precondizione
		for (int i=length_; i>=p; i--)
			elements_[i] = elements_[i-1];
		elements_[p-1]=a;
		length_++;
	}
}

template< class T >
void Ordered_list< T >::erase(position p){
  if ( (0 < p) && ( p < length_ + 1)) // precondizione
    if (!empty()) {
			for (int i=p-1;i<(length_-1);i++)
				elements_[i]=elements_[i+1];
			length_--;
		}
}

template<class T>
void Ordered_list< T >::change_dimension_(T*& a, int vecchiaDim, int nuovaDim){

  T* temp = new T[nuovaDim];
  int number;
  if (vecchiaDim < nuovaDim) 
     number = vecchiaDim;
  else
     number = nuovaDim;
  for (int i=0; i<number; i++)
     temp[i]=a[i];
  delete [] a;
  a = temp;
}

/* operatore di assegnamento */
template<class T>
Ordered_list<T>& Ordered_list<T>::operator=(const Ordered_list<T>& l)
{
	if (this != &l){   // attenzione agli autoassegnamenti: l = l 
		this->array_dimension_ = l.array_dimension_;
		this->length_ = l.length_;
		delete this->elements_;
		this->elements_ = new T[array_dimension_];
		for (int i=0; i<l.array_dimension_; i++)
			this->elements_[i] = l.elements_[i];
	}
	return *this;
}

/* operatore di test di uguaglianza */
template<class T>
bool Ordered_list<T>::operator==(const Ordered_list<T> &l) const
{
	if (l.length_ != this->length_)
		return false;
  for (int i=0; i<this->array_dimension_; i++)
		if (this->elements_[i] != l.elements_[i])
			return false;
	return true;
}

template<class T>
bool Ordered_list<T>::isPalindrome()
{
	bool palindrome = false;
	position start = begin();
	position end = last();
	while(read(start) == read(end) && next(start)!=end && start!=end)
	{
		start = next(start);
		end = previous(end);
	}
	
	if(read(start) == read(end))
	{
		palindrome = true;
	}
	return palindrome;
}

template<class T>
void Ordered_list<T>::insertOrd(const value_type &a)
{
	bool stop = false;
	position p = begin();
	while(!end(p) && !stop)
	{
		if(a<read(p)) stop = true;
		else p = next(p);
	}
	insert(a,p);
}



template<class T>
bool Ordered_list<T>::search(const value_type value)
{
	bool found = false, stop = false;
	position p = begin();
	while(!end(p) && !found && !stop)
	{
		if(read(p)<=value)
		{
			if(read(p)==value) found = true;
			else p = next(p);
		}
		else stop = true;
	}
	return found;
}

template <class T>
void Ordered_list<T>::merge(Ordered_list<T>& list)
{
	position pList = list.begin();
	position p = begin();
	while(!list.end(pList))
	{
		cout<<*this<<endl;
		if(read(p)>=list.read(pList))
		{
			insert(list.read(pList),p);
			pList = list.next(pList);
		}
		else p = next(p);
	}
}


#endif // _ORDERED_LIST_H
