#ifndef TREE_H
#define TREE_H

template<class I, class N>
	class Tree 		//DEFINIZIONE DELLA CLASSE VIRTUALE DELL'ALBERO N-ARIO
	{
 public:
	typedef I item;		//definizione del campo INFORMAZIONE
	typedef N node;		//definizione del campo contenente la POSIZIONE
	
	virtual void create () = 0;						//FUNZIONE CHE CREA L'ALBERO
	virtual bool empty () const = 0;				//FUNZIONE CHE INDICA CON UN VALORE BOOLEANO SE L'ALBERO E' VUOTO O MENO
	virtual void insRoot (node) = 0;				//FUNZIONE CHE INSERISCE LA RADICE NELL'ALBERO N-ARIO
	virtual node root () const = 0;					//FUNZIONE CHE RESTITUISCE IL NODO RADICE DELL'ALBERO
	virtual node parent (node) const = 0;			//FUNZIONE CHE INDICA, DATO IL NODO, IL NODO PADRE
	virtual bool leaf (node) const = 0;				//FUNZIONE CHE INDICA CON UN VALORE BOOLEAN SE IL NODO PASSATO E' UN NODO FOGLIA
	virtual node firstChild (node) const = 0;		//FUNZIONE CHE RESTITUISCE IL PRIMOFIGLIO DEL NODO PASSATO
	virtual bool lastSibling (node) const = 0;		//FUNZIONE CHE INDICA CON UN VALORE BOOLEAN SE IL NODO PASSATO E' L'ULTIMO FRATELLO
	virtual node nextSibling (node) const = 0;		//FUNZIONE CHE RESTITUISCE IL NODO FRATELLO A QUELLO PASSATO
	// DA IMPLEMENTARE
	//	virtual void insFirstSubTree (node, Tree &) = 0;
	//	virtual void insSubTree (node, Tree &) = 0;
	virtual void removeSubTree (node) = 0;			//FUNZIONE CHE, DATO UN NODO, CANCELLA TALE NODO E IL RELATIVO SOTTOALBERO
	virtual void writeNode (node, item) = 0;		//FUNZIONE CHE, DATO UN NODO E IL CAMPO INFORMAZIONE, SCRIVE TALE INFORMAZIONE NEL NODO
	virtual item readNode (node) const = 0;			//FUNZIONE CHE, DATO UN NODO, RESTITUISCE IL CAMPO INFORMAZIONE

	//template<class V> void BFS(node);
	//template<class V> void preorder(node);
	//template<class V> void postorder(node);

};

#endif
