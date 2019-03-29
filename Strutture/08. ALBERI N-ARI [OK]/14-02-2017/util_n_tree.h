#ifndef UTIL_N_TREE_H
#define UTIL_N_TREE_H
#include "TreeList.h"
#include <iostream>

using namespace std;

template <class T>
class util_n_tree : public TreeList<T>
{
	typedef int Nodo;
	public:
		int n_leaf(const TreeList<T> &);
		int n_leaf(const TreeList<T> &, Nodo);
		
		int n_level (const TreeList<T> &, int k);
		int n_level(const TreeList<T> &B, int k, Nodo);
		//int n_figli(const TreeList<T> &, Nodo, int);
		int getProfondita(const TreeList<T> &, Nodo);
		int getProfondita(const TreeList<T> &, Nodo , Nodo, int, bool &);
};

template <class T>
int util_n_tree<T>::n_leaf(const TreeList<T> &B)
{
	int nFoglie = 0;
	if(!B.empty()) nFoglie = n_leaf(B,B.root());
	
	return nFoglie;
}

template <class T>
int util_n_tree<T>::n_leaf(const TreeList<T> &B, Nodo n)
{
	static int nFoglie = 0;
	
	if(!B.leaf(n))
	{
		n = B.firstChild(n);
		nFoglie = n_leaf(B,n);
		
		while(!B.lastSibling(n))
		{
			n = B.nextSibling(n);
			nFoglie = n_leaf(B,n);
		}
	}
	else nFoglie++;
	
	return nFoglie;
}

template <class T>
int util_n_tree<T>::n_level(const TreeList<T> &B, int k)
{
	if(B.empty()) return -1;
	else return n_level(B,k,B.root());
}

template <class T>
int util_n_tree<T>::n_level(const TreeList<T> &B, int k, Nodo n)
{
	static int nNodi = 0;
	if(getProfondita(B,n) == k) nNodi++;
	
	if(!B.leaf(n))
	{
		n = B.firstChild(n);
		nNodi = n_level(B, k, n);
		
		while(!B.lastSibling(n))
		{
			n = B.nextSibling(n);
			nNodi = n_level(B, k, n);
		}
	}
	return nNodi;
}

template <class T>
int util_n_tree<T>::getProfondita(const TreeList<T> &B, Nodo daCercare)
{
	if(B.empty()) return -1;
	else
	{
		bool trovato = false;
		return getProfondita(B,daCercare,B.root(), 0, trovato);
	} 
}

template <class T>
int util_n_tree<T>::getProfondita(const TreeList<T> &B, Nodo daCercare, Nodo n, int profondita, bool &trovato)
{
	if(n!=daCercare)
	{
		if(!B.leaf(n) && !trovato)
		{
			profondita++;
			n = B.firstChild(n);
			profondita = getProfondita(B, daCercare, n, profondita, trovato);
			
			int temp = profondita;
			while(!B.lastSibling(n) && !trovato)
			{
				n = B.nextSibling(n);
				profondita = getProfondita(B, daCercare, n, profondita, trovato);
			}
			if(!trovato)
			{
				if(n!=daCercare)
				{
					temp--;
					profondita = temp;
				}
			}
		}
	}
	else trovato = true;
	
	return profondita;
}

#endif
