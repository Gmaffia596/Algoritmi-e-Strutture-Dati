#ifndef DIZENTRY_H
#define DIZENTRY_H

template<typename Key, typename Value> class Entry 
{
// E=tipo elemento, K=tipo chiave

public:

	Entry (const Key&, const Value&); // costruttore
	Entry (); // costruttore

	Value getValue(); // restituisce il valore dell'attributo
	Key getKey(); // restituisce la chiave

	// metodi di set
	void setValue(const Value&);
	void setKey(const Key&);


private:
Key k;
Value v;
};


template<typename Key, typename Value> Entry<Key,Value>::Entry(const Key& chiave, const Value& valore)
{
k=chiave;
v=valore;
}

template<typename Key, typename Value> Entry<Key,Value>::Entry() //COSTRUTTORE VUOTO
{}

template<typename Key, typename Value> Key Entry<Key,Value>::getKey()
{
return k;
}



template<typename Key, typename Value> Value Entry<Key,Value>::getValue()
{
return v;
}

template<typename Key, typename Value> void Entry<Key,Value>::setKey(const Key& chiave)
{
k=chiave;
}

template<typename Key, typename Value> void Entry<Key,Value>::setValue(const Value& valore)
{
v=valore;
}

#endif // _DIZENTRY_H
