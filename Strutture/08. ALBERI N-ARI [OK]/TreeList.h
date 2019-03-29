#ifndef TREELIST_H
#define TREELIST_H

#include "list_vector.h"
#include "Tree.h"


#define MAXNODES 100

template<class I>
class TreeList : public Tree<I, int> 	//DEFINIZIONE DELLA CLASSE TREELIST, SOTTOCLASSE DI TREE
{
 	public:

		typedef I item;
		typedef int node;
	
		// Costruttore
		TreeList()	//COSTRUTTORE
		{
			create();	//CREAZIONE DELL'ALBERO
		};
	
		virtual void create();
		virtual bool empty() const;
		virtual void insRoot(node);
		virtual node root() const;
		virtual node parent(node) const;
		virtual bool leaf(node) const;
		virtual node firstChild(node) const;
		virtual bool lastSibling(node) const;
		virtual node nextSibling(node) const;
		// DA IMPLEMENTARE
		//	virtual void insFirstSubTree (node, TreeList &) ;
		//	virtual void insSubTree (node, TreeList &) ;
		virtual void removeSubTree(node);
	
		void insFirst(node, item);
		void ins(node, item);
	
		virtual void writeNode(node, item);
		virtual item readNode(node) const;
	
		void print() const;

 	private:
		struct Record 	//DEFINIZIONE DEL CAMPO RECORD
		{
			item e;		//CAMPO CHE CONTIENE L'INFORMAZIONE
			bool used;	//CAMPO CHE DICE SE IL RECORD E' USATO O MENO
			List_vector<int> childs;		//LISTA DI RIFERIMENTO MEDIANTE INDICI INTERI DEI FIGLI
		};
		typedef List_vector<int>::position position_list;		//DEFINIZIONE DELL'INDICE DI SCORRIMENTO
	 
		Record nodes[MAXNODES];		//DEFINIZIONE DELL'ARRAY DI MAXNODES DI TIPO RECORD
		node _root;		//DEFINIZIONE DELLA RADICE
		int numNodes;	//CONTATORE DEL NUMERO DI NODI
};


template <class I>
void TreeList<I>::print() const		//FUNZIONE DI STAMPA
{
	cout << "\n{";
	for (int i=0; i < MAXNODES;i++)
	{
		if (nodes[i].used==true)
		{
			cout << "\n  " << readNode(i) << ":  ";
			if (!leaf(i))
			{
				position_list child = nodes[i].childs.begin();	//il puntatore alla lista dei figli, lo inizializzo all'inizio del vettore relativamente alla posizione I del padre				
				while (!nodes[i].childs.end(child))		//fino a quando i figli non terminano
				{
					cout << readNode(nodes[i].childs.read(child)) << " "; 		//Stampo il contenuto
					child = nodes[i].childs.next(child);						//Passo al figlio successivo
				}
			}
		}
	}
	cout << "\n}\n";
}

template <class I>
void TreeList<I>::create()		//FUNZIONE DI CREAZIONE
{
	numNodes = 0;	//imposto il numero di nodi a 0
	for (int i=0; i< MAXNODES;i++)
	{
		nodes[i].used = false;	//inizializzo il campo USED a FALSE
		nodes[i].childs.create();	//vado a chiamare la CREATE anche sui figli
	}
}

template <class I>
bool TreeList<I>::empty() const		//FUNZIONE DI CONTROLLO SE L'ALBERO N-ARIO E' VUOTO
{
	return(numNodes == 0);		//se il numero di nodi=0, allora ritorna TRUE. False, altrimenti.
}

template <class I>
void TreeList<I>::insRoot (node n)		//INSERIMENTO DEL NODO RADICE NELL'ALBERO N-ARIO
{
	if (empty())		//SE L'ALBERO N-ARIO è VUOTO
	{
		_root = 0;		//imposto la radice a 0
		nodes[0].used = true;		//IMPOSTO IL BOOLEAN RELATIVO ALLA RADICE (in posizione 0) a TRUE
		numNodes++;		//incremento il numero di nodi dell'albero a 1
	}
}

template <class I>
typename TreeList<I>::node TreeList<I>::root () const		//restituisce la radice
{
	return _root;			//restituisco il riferimento alla radice
}

template <class I>
typename TreeList<I>::node TreeList<I>::parent (node n) const		//restituisce il padre di un nodo passato come parametro
{
	position_list child;		//dichiaro il puntatore nel vettore per i figli
	int p;		//dichiarazione di un indice per il padre
	for (int i=0; i < MAXNODES; i++)		//fino a che non si raggiunge il numero massimo di nodi
	{
		if (!nodes[i].childs.empty())		//Se la lista dei figli di un nodo non è vuota
		{
			child = nodes[i].childs.begin();	//imposto l'indice al primo figlio
			bool found = false;					//imposto il boolean trovato=false
			while (!nodes[i].childs.end(child) && !found)	//fino a quando non finiscono i figli o fino a che non viene trovato
			{
				if (nodes[i].childs.read(child) == n)		//Se il nodo N passato come parametro=al figlio puntato
				{
					found = true;		//metto il trovato = TRUE
					p = i;				//Pongo l'indice del padre, uguale all'indice di scorrimento
				}
				child = nodes[i].childs.next(child);		//passo al figlio successivo
			}
			if (found)			//se trovato
				return(i);		//mi ritorni la posizione dell'indice
		}
	}
}

template <class I>
bool TreeList<I>::leaf(node n) const		//RESTITUISCE IL VALORE BOOLEANO SE IL NODO PASSATO E' UNA FOGLIA
{
	return(nodes[n].childs.empty());		//SE IL VETTORE DEI FIGLI E' VUOTO, RITORNO TRUE, FALSE ALTRIMENTI
}

template <class I>
typename TreeList<I>::node TreeList<I>::firstChild (node n) const		//RESTITUISCE IL RIFERIMENTO AL PRIMOFIGLIO
{
	if (!leaf(n))		//se il nodo non è foglia
	{
		return(nodes[n].childs.read(nodes[n].childs.begin()));	//ritorno il puntatore al primo elemento del vettore relativo ai figli del nodo N
	}
}

template <class I>
bool TreeList<I>::lastSibling (node n) const 	//RESTITUISCE IL VALORE BOOLEANO SE IL NODO E' ULTIMO FRATELLO
{
	position_list c;			//dichiaro un puntatore di posizione di nome C
	node p = parent(n);			//P indica il genitore di N
	c = nodes[p].childs.begin();	//C punta all'inizio del vettore dei figli di P
	while (!nodes[p].childs.end(nodes[p].childs.next(c)))		//fino a quando i figli non finiscono			<--- MODIFICATO QUI
		c = nodes[p].childs.next(c);	//ciclo sui figli
	return (n == nodes[p].childs.read(c));	//quando esco perchè sono arrivato all'ultimo figlio, ritorno true se la posizione = al nodo N passato
}

template <class I>
typename TreeList<I>::node TreeList<I>::nextSibling (node n) const		//restituisce il puntatore al successivo fratello rispetto al NODO N
{
	if (!lastSibling(n))		//se N non è l'ultimo nodo
	{
		position_list c;		//dichiaro un puntatore dei figli di nome C
		node p = parent(n);		//dichiaro un nodo P che punta al padre di N
		c = nodes[p].childs.begin();	//C punta all'inizio del vettore dei figli del padre
		while (!nodes[p].childs.end(c))		//fino a quando i figli non finiscono
		{
			if (nodes[p].childs.read(c) == n)		//se trovo il nodo
				return (nodes[p].childs.read(nodes[p].childs.next(c)));		//ritorno la posizione al successivo fratello
			c = nodes[p].childs.next(c);	//ciclo al successivo figlio
		}
	}
}


// inserisce un node come firstChild di n
template <class I>
void TreeList<I>::insFirst(node n, item el)		//INSERISCO IL FIGLIO NEL VETTORE DEI FIGLI IN PRIMA POSIZIONE
{
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	//HO TROVATO UNA POSIZIONE LIBERA
	if (k<MAXNODES) //se K < DEL NUMERO DI nodi massimi dichiarati
	{
		nodes[k].used = true;		//occupo il nodo in posizione K
		nodes[k].e = el;			//avvaloro il campo INFORMAZIONE
		nodes[n].childs.insert(k, nodes[n].childs.begin());		//inserisco tale nodo in prima posizione nel vettore dei figli
	}
}

// inserisce un node come fratello di n
template <class I>
void TreeList<I>::ins(node n, item el)
{
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	//HO TROVATO IL POSTO
	if (k<MAXNODES) //se K < DEL NUMERO DI nodi massimi dichiarati
	{
		nodes[k].used = true;		//pongo la cella occupata
		nodes[k].e = el;			//avvaloro il campo INFORMAZIONE
		node p = parent(n);			//Con il nodo P punto al padre di N
		position_list child = nodes[p].childs.begin();		//con l'indice punto all'inizio del vettore contenente i riferimenti ai figli del nodo Padre
		bool found = false;		//pongo trovato a FALSE
		while (!nodes[p].childs.end(child) && !found)	//fin quando non arrivo alla fine dei figli e non l'ho trovato
		{
			if (nodes[p].childs.read(child) == n)		//se il figlio è quello che sto cercando
					found = true;		//metto trovato a TRUE
			child = nodes[p].childs.next(child);		//altrimenti punto al fratello successivo
		}
		nodes[p].childs.insert(k, child);	//una volta che l'ho trovato, inserisco il nodo successivamente al fratello trovato
	}
}



template <class I>
void TreeList<I>::removeSubTree (node n)			//RIMUOVO IL SOTTOALBERO, PARTENDO DALLA RADICE N
{

	position_list c;		//dichiaro un puntatore C
	if (!leaf(n))		//se il nodo non è foglia
	{
		while (!nodes[n].childs.empty())		//se il vettore dei riferimenti ai figli non è vuoto
		{
			removeSubTree(nodes[n].childs.read(nodes[n].childs.begin()));		//rimuovo il sottoalbero, partendo dall'inizio del vettore dei figli
		}
	}
	node p = parent(n);		//imposto il nodo P al genitore di N
	c = nodes[p].childs.begin();	//C punta all'inizio dei vettori di riferimento ai figli del nodo PADRE P
	while(nodes[p].childs.read(c) != n)		//fino a quando il nodo è diverso da N
		c = nodes[p].childs.next(c);		//ciclo
	nodes[p].childs.erase(c);				//una volta uscito, cancello il nodo C dai figli di P
	nodes[n].used = false;					//pongo il nodo N a NON USATO
}

template <class I>
void TreeList<I>::writeNode (node n, item el)		//FUNZIONE DI SCRITTURA DEL CAMPO INFORMAZIONE DEL NODO
{
	nodes[n].e = el;		//nel nodo avvaloro il campo INFORMAZIONE
}

template <class I>
typename TreeList<I>::item TreeList<I>::readNode (node n) const		//FUNZIONE DI LETTURA DEL CAMPO INFORMAZIONE DEL CAMPO NODO
{
	return(nodes[n].e);		//RESTITUISCO IL CAMPO INFORMAZIONE DEL NODO N
}

#endif
