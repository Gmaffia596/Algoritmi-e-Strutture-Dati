#ifndef _ORDERED_LIST_H
#define _ORDERED_LIST_H

#include "Linear_List.h"

template<class T>
class Ordered_list;

template< class T >
class List_node
{
	friend class Ordered_list<T>;
 	private:
		T _value;
		List_node<T> * _pPrev;
		List_node<T> * _pNext;
};


template< class T >
class Ordered_list : public Linear_list<T, List_node<T>*>
{
	public:
		typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
		typedef typename Linear_list<T, List_node<T>*>::position position;
	
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
		int size() const{return _length;};
		bool isPalindrome();
		bool search(const value_type);
		void merge(Ordered_list<T>&);

		// sovraccarico di operatori
		Ordered_list<T>& operator=(const Ordered_list<T>&); // the assignment operator
		bool operator==(const Ordered_list<T> &) const; // tests two list for equality

	private:
		List_node<T> * _pHead;
		int _length; // the length of the list
};

template< class T >
Ordered_list< T >::Ordered_list()
{
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}


template< class T >
Ordered_list< T >::Ordered_list(const Ordered_list<T>& L)
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
Ordered_list< T >::~Ordered_list()
{
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class T >
void Ordered_list< T >::create()
{
	if (empty())
			_length = 0;
}

template< class T >
bool Ordered_list< T >::empty() const
{
	return(_pHead == _pHead->_pNext);
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::begin() const
{
	return (_pHead->_pNext);
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::last() const
{
	return (_pHead->_pPrev);
}


template< class T >
typename Ordered_list< T >::position Ordered_list< T >::next(position p) const
{
	return(p->_pNext);
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::previous(position p) const
{
	if (p != _pHead)
		return(p->_pPrev);
}

template< class T >
bool Ordered_list< T >::end(position p) const
{
	return(p == _pHead);
}

template< class T >
typename Ordered_list< T >::value_type Ordered_list< T >::read(position p) const
{
	if (!end(p))
		return(p->_value);
}

template< class T >
void Ordered_list< T >::write(const value_type &a, position p)
{
	if (!end(p))
    p->_value = a;
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
	position new_node = new List_node<T>;
	new_node->_pNext = p;
	new_node->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = new_node;
	p->_pPrev = new_node;
	new_node->_value = a;
	_length++;
}

template<class T>
void Ordered_list<T>::insert(const value_type &a, position p)
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
void Ordered_list< T >::erase(position p)
{
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
	}
}


template<class T>
Ordered_list<T>& Ordered_list<T>::operator=(const Ordered_list<T>& L)
{
	if (this != &L){
		_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

        cout << L.empty();
        cout << L.size();
		if (!L.empty())
		{
            position p = L.last();
			for (int i=0; i < L.size(); i++)
			{
				cout << i, L.read(p);
				insert(L.read(p));
				p = L.previous(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Ordered_list<T>::operator==(const Ordered_list<T> &L) const
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
		if(read(p)>=list.read(pList))
		{
			insert(list.read(pList),p);
			pList = list.next(pList);
		}
		else p = next(p);
	}
}


#endif // _ORDERED_LIST_H
