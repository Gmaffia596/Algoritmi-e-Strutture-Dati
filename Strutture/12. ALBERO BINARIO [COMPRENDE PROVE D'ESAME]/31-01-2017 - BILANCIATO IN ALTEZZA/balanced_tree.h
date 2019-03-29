#ifndef BALANCED_TREE_H
#define BALANCED_TREE_H
#include "Bin_treec.h"
#include "Bin_tree.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class balanced_tree
{
	static const int NIL = -1;	
		public:
		typedef typename Bin_tree<T, int>::Nodo Nodo;					//definizione del campo nodo
		
		//stabilisce se l'albero è bilanciato in altezza
		bool is_height_balanced (const Bin_treec < T> &B);
		bool is_height_balanced(const Bin_treec<T> &, const Nodo, int &, int &, bool);
		//stabilisce se tutti i nodi non foglia dell'albero hanno esattamente due figli
		bool complete_nodes (const Bin_treec < T> &B);
		bool complete_nodes (const Bin_treec < T> &B, Nodo, bool);
		
		/*private:
			Bin_tree<T> albero;*/
		
};

template <class T>
bool balanced_tree<T>::is_height_balanced (const Bin_treec < T> &B)
{
	bool bilanciato = true;
	int path = 0, oldPath=0;
	static int count=0;
 	if(!B.empty())
	{
	 	bilanciato = is_height_balanced(B,B.root(), path, oldPath, bilanciato);
	}
	 
	return bilanciato;
}

template <class T>
bool balanced_tree<T>::is_height_balanced(const Bin_treec<T> &B, const Nodo n, int &path, int &oldPath, bool bilanciato)
{
	if(B.sx_empty(n) && B.dx_empty(n))
	{
		cout<<B.read(n)<<" FOGLIA RAGGIUNTA: path="<<path<<" oldPath="<<oldPath<<" path-oldPath="<<abs(path-oldPath)<<endl;
		if(oldPath==0 || path==oldPath || abs(path-oldPath)<=1)
		{
			if(path>=oldPath) oldPath = path;
			if(bilanciato) bilanciato = true;
		}
		else bilanciato = false;
	}
	else
	{
		if(!B.sx_empty(n) && bilanciato)
		{
			int temp = path;
			path++;
			cout<<B.read(n)<<" "<<path<<endl;
			bilanciato = is_height_balanced(B, B.sx(n),path,oldPath,bilanciato);
			path=temp;
		}
		if(!B.dx_empty(n) && bilanciato)
		{
			path++;
			cout<<B.read(n)<<" "<<path<<endl;
			bilanciato = is_height_balanced(B, B.dx(n),path,oldPath,bilanciato);
		}
		else
		{
			if(oldPath==0 || path==oldPath || abs(path-oldPath)<=1)
			{
				if(path>=oldPath) oldPath = path;
				if(bilanciato) bilanciato = true;
			}
			else bilanciato = false;
		}
	}
	return bilanciato;
}

/*template <class T>
int balanced_tree<T>::is_height_balanced (const Bin_treec < T> &B,Nodo n)
{
	bool bilanciato;
	static int count=0;
	if(!B.sx_empty(n))
	 	count+=is_height_balanced(B,B.sx(n));
	if(!B.dx_empty(n))
	 	count+=is_height_balanced(B,B.dx(n));
}*/


template <class T>
bool balanced_tree<T>::complete_nodes (const Bin_treec < T> &B)
{
	bool esito = true;
	if(!B.empty())
	{
		esito = complete_nodes(B,B.root(), esito);
	}
	else esito = false;
	cout<<esito<<endl;
	return esito;
}


template <class T>
bool balanced_tree<T>::complete_nodes (const Bin_treec < T> &B, Nodo n, bool esito)
{
	if(!B.sx_empty(n) && !B.dx_empty(n))
	{
		if(!B.sx_empty(n) && esito)
		{
			cout<<B.read(n)<<" "<<esito<<endl;
			esito = true;
			esito = complete_nodes(B, B.sx(n),esito);
		}
		else
		{
			cout<<B.read(n)<<" "<<esito<<endl;
			esito = false;
		}
		
		if(!B.dx_empty(n) && esito)
		{
			cout<<B.read(n)<<" "<<esito<<endl;
			esito = true;
			esito = complete_nodes(B, B.dx(n),esito);
		}
		else
		{
			cout<<B.read(n)<<" "<<esito<<endl;
			esito = false;
		}
	}
	else
	{
		if(!B.sx_empty(n) || !B.dx_empty(n))
		{
			cout<<B.read(n)<<" "<<esito<<endl;
			esito = false;	
		}
	}
	return esito; //se true indica che ogni nodo ha due figli
}


#endif
