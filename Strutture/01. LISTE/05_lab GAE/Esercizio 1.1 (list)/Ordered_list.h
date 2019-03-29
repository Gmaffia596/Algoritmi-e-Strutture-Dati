#ifndef _ORDERED_LIST_H
#define _ORDERED_LIST_H

#include <list>
#include <iostream>
using namespace std;

template<class T>
class Ordered_list
{
	public:
		void insert(T);
		void remove(T);
		bool search(T);
		merge(Ordered_list<T> &);
		
		void outputList();
		//ostream& operator<<(ostream&, const Ordered_list<T>&);
		
	private:
		list<T> l;
};

template <class T>
void Ordered_list<T>::insert(T element)
{
	auto iter = l.begin();
	bool stop = false;
	while(iter!=l.end() && !stop)
	{
		if(element<*iter) stop = true;
		else iter++;
	}
	l.insert(iter,element);
}

template<class T>
void Ordered_list<T>::outputList()
{
	auto iter = l.begin();
	cout<<"[ ";
	while(iter!=l.end())
	{
		cout<<*iter<<" ";
		iter++;	
	}
	cout<<"]"<<endl;
}

/*template <class T>
ostream& operator<<(ostream &out, const Ordered_list<T> &list)
{
	auto iter = list.begin();
	out<<"[";
	while(iter!=list.end()) out<<*iter<<" ";
	out<<"]"<<endl;
	return out;
}*/

#endif //_ORDERED_LIST_H
