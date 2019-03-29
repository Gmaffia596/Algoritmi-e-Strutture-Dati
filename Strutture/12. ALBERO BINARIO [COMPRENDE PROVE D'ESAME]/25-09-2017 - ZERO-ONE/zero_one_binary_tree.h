#ifndef ZERO_ONE_BINARY_TREE_H
#define ZERO_ONE_BINARY_TREE_H
#include "Bin_treec.h"
#include "Bin_tree.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class zero_one_binary_tree
{
	static const int NIL = -1;	
	public:
		typedef typename Bin_tree<T, int>::Nodo Nodo;					//definizione del campo nodo
		//stabilisce se un albero è zero-one o meno
		bool is_zero_one (const Bin_treec < T> &B);
		bool is_zero_one (const Bin_treec < T> &B, Nodo);
		//conta il numero di 0-nodi presenti dell'albero
		int zero_nodes (const Bin_treec < T> &B);
		int zero_nodes (const Bin_treec < T> &B, Nodo);
};

template <class T>
bool zero_one_binary_tree<T>::is_zero_one (const Bin_treec < T> &B)
{
	bool esito=true;
		if(B.root()!=NIL)
	{
		if(B.read(B.root())==0)
		{
			esito=is_zero_one(B,B.root());
		}
		else
		{
			return false; //altrimenti non continuare perchè la prima condizione non è verificata
		}
	}
}

template <class T>
bool zero_one_binary_tree<T>::is_zero_one (const Bin_treec < T> &B, Nodo n)
{
	static bool zerouno=true;
	static bool zero=true;
	if(B.read(n)==0)
	{
		zero=true;
	}
	else
	{
		zero=false;
	}
	if(!B.sx_empty(n)&&!B.dx_empty(n))
	{
		if(zero)
		{
			if(B.read(B.sx(n))==1 && B.read(B.dx(n))==1)
			{
				//cout<<B.read(B.sx(n))<<" - "<<B.read(B.dx(n))<<endl;
				zerouno=true;
			}
			else
			zerouno=false;
		}
		else
		{
			if(B.read(B.sx(n))==0 && B.read(B.dx(n))==0)
			{
				//cout<<B.read(B.sx(n))<<" - "<<B.read(B.dx(n))<<endl;
				zerouno=true;
			}
			else
			zerouno=false;
		}
	}
	if(!B.sx_empty(n)) zerouno = is_zero_one(B,B.sx(n));
	if(!B.dx_empty(n)) zerouno = is_zero_one(B,B.dx(n));
	
	return zerouno;	
}

template <class T>
int zero_one_binary_tree<T>::zero_nodes (const Bin_treec < T> &B)
{
	if(B.root()!=NIL)
	{
		zero_nodes(B,B.root());
	}
}

template <class T>
int zero_one_binary_tree<T>::zero_nodes (const Bin_treec < T> &B, Nodo n)
{
	static int count=0;
	if(!B.sx_empty(n))
	{
		zero_nodes(B, B.sx(n));
	}
	if(!B.dx_empty(n))
	{
		zero_nodes(B, B.dx(n));
	}
	
	std::cout<<"VALORE: "<<B.read(n)<<std::endl;
	if(B.read(n)==0)
	{
		count++;
	}
return count;
}

#endif
