#include "Bin_treec.h"
#ifndef BALANCED_TREEC_H_
#define BALANCED_TREEC_H_


template<class _value_type>
class balanced_tree{
	/* Stabilisce se l'albero e bilanciato in altezza.
	 * Un albero binario e bilanciato in altezza se
	 * a) e vuoto, o
	 * b) se per ogni nodo le altezze dei suoi due sottoalberi differiscono al piu di uno e i due sottoalberi sono bilanciati in altezza.
	 */
public:
	bool is_height_balanced(const Bin_treec< _value_type > &B);

	/* Stabilisce se tutti i nodi non foglia dell'albero hanno esattamente due figli */
	bool complete_nodes(const Bin_treec< _value_type > &B);

	// altre che servono
	bool isBalanced_recursive(const Bin_treec< _value_type > &B, typename Bin_treec<_value_type>::Nodo curr);
	bool isComplete_recursive(const Bin_treec< _value_type > &B, typename Bin_treec< _value_type >::Nodo curr);
};



template<class _value_type>
 bool balanced_tree<_value_type>::is_height_balanced(const Bin_treec<_value_type>& B) {
	if(B.empty())
			return true;
		return isBalanced_recursive(B,B.root());
}


template<class _value_type>
bool balanced_tree<_value_type>::isBalanced_recursive(const Bin_treec<_value_type> &B, typename Bin_treec<_value_type>::Nodo curr) {
	if(B.dx_empty(curr) && B.sx_empty(curr))
		return true;
	int h_left = B.height(B.sx(curr));
	int h_right = B.height(B.dx(curr));
	if(abs(h_left - h_right) > 1)
		return false;
	return isBalanced_recursive(B,B.sx(curr)) && isBalanced_recursive(B,B.dx(curr));
}



template<class _value_type>
bool balanced_tree< _value_type >::complete_nodes(const Bin_treec< _value_type > &B) {
	if(B.empty())
		return true;
	return isComplete_recursive(B,B.root());
}

template<class _value_type>
bool balanced_tree< _value_type >::isComplete_recursive(const Bin_treec< _value_type > &B, typename Bin_treec< _value_type >::Nodo curr) {
	if((B.dx_empty(curr) && !B.sx_empty(curr)) || (!B.dx_empty(curr) && B.sx_empty(curr)))
		return false;
	if((B.dx_empty(curr) && B.sx_empty(curr)))
		return true;
	else
		return isComplete_recursive(B,B.dx(curr)) && isComplete_recursive(B,B.sx(curr));
}


#endif /* BALANCED_TREEC_H_ */
