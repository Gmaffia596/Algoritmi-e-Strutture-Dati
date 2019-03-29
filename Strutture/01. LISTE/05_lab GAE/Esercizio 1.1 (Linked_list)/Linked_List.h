#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "Linear_List.h"

template<class T>
class Linked_list;

template< class T >
class List_node
{
	friend class Linked_list<T>;
 	private:
		T _value;
		List_node<T> * _pPrev;
		List_node<T> * _pNext;
};


template< class T >
class Linked_list : public Linear_list<T, List_node<T>*>
{
	public:
		typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
		typedef typename Linear_list<T, List_node<T>*>::position position;
	
		// costruttori
		Linked_list();
		Linked_list(int);
		// costruttore per copia
		Linked_list(const Linked_list<T>& );
		//distruttore
		~Linked_list();
	
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
		int size() const{return _length;};
		void invert();
		bool isPalindrome();

		// sovraccarico di operatori
		Linked_list<T>& operator=(const Linked_list<T>&); // the assignment operator
		bool operator==(const Linked_list<T> &) const; // tests two list for equality

	private:
		List_node<T> * _pHead;
		int _length; // the length of the list
};

template< class T >
Linked_list< T >::Linked_list()
{
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}


template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L)
{
  	_length = L.size();

	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;

	if (!L.empty())
	{
		position p = L.last();
		for (int i=0; i <= L._length; i++)
		{
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
}


template< class T >
Linked_list< T >::~Linked_list()
{
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class T >
void Linked_list< T >::create()
{
	if (empty())
			_length = 0;
}

template< class T >
bool Linked_list< T >::empty() const
{
	return(_pHead == _pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::begin() const
{
	return (_pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::last() const
{
	return (_pHead->_pPrev);
}


template< class T >
typename Linked_list< T >::position Linked_list< T >::next(position p) const
{
	return(p->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::previous(position p) const
{
	if (p != _pHead)
		return(p->_pPrev);
}

template< class T >
bool Linked_list< T >::end(position p) const
{
	return(p == _pHead);
}

template< class T >
typename Linked_list< T >::value_type Linked_list< T >::read(position p) const
{
	if (!end(p))
		return(p->_value);
}

template< class T >
void Linked_list< T >::write(const value_type &a, position p)
{
	if (!end(p))
    p->_value = a;
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p)
{
	position t = new List_node<T>;
	t->_value = a;

	t->_pNext = p;
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;
}

template< class T >
void Linked_list< T >::erase(position p)
{
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
	}
}


template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L)
{
	if (this != &L){
		_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

        cout << L.empty();
        cout << L.size();
		if (!L.empty()){
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const
{
	if (L.size() != _length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->_value != pL->_value)
			return false;
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true; 
}

/*template< class T >
void Linked_list< T >::invert()
{
	position p;
	p = _pHead;
	List_node<T> *temp;
	temp = new List_node<T>;
	int i=0;
	do
	{	
		temp = p->_pPrev;
		p->_pPrev = p->_pNext;
		p->_pNext = temp;
		p = p->_pPrev;
		cout<<i++<<endl;
	}
	while(!end(p));
}*/

template< class T >
void Linked_list< T >::invert()
{
	position start = begin();
	position end = last();
	value_type temp;
	do
	{	
		temp = read(start);
		write(read(end),start);
		write(temp,end);
		start = next(start);
		end = previous(end);
	}
	while(previous(start)!=end && start!=end);
}

/*template<class T>
bool Linked_list<T>::isPalindrome()
{
	bool palindrome = false;
	position start = _pHead->_pNext;
	position end = _pHead->_pPrev;
	while(start->_value == end->_value && start->_pNext!=end && start!=end)
	{
		start = start->_pNext;
		end = end->_pPrev;
	}
	
	if(start->_value == end->_value)
	{
		palindrome = true;
	}
	return palindrome;
}*/

template<class T>
bool Linked_list<T>::isPalindrome()
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


#endif // _LINKED_LIST_H
