#include <iostream>
#include "linked_list.h"
#include <string.h>
using namespace std;

class eo_strings {
public:
	// inserisce una stringa nella corrispondente lista
	void inserisci(string s);
	// rimuove la stringa dalla corrispondente lista
	void rimuovi(string s);
	// rimuove le stringhe di lunghezza pari che iniziano con il carattere c
	void rimuovi(char c);
	// restituisce il numero di stringhe di lunghezza pari
	int freq_pari();
	// visualizza le stringhe di lunghezza dispari ordinate per lunghezza
	void visualizza_dispari();

	void inserisci_posiziona(int p);
private:
	Linked_list<string> pari;
	Linked_list<string> dispari;
};


int main() {

	Linked_list<string>::position iter;
	eo_strings asd;
	asd.inserisci("ciao mamma");
	asd.inserisci("ciao");
	asd.inserisci("ciola");
	asd.inserisci("atre");
	asd.inserisci("aquattro");
	asd.inserisci("ciao papa");
	//cout<<asd.freq_pari();
	asd.visualizza_dispari();
	cout<<"\n------------------------------------------\n";
/*
	asd.rimuovi("ciao");
	cout<<asd.freq_pari();
	getchar();

	asd.rimuovi(2);
*/
	asd.rimuovi('c');
	asd.visualizza_dispari();

	getchar();

}

void eo_strings::inserisci(string s) {

	int l=s.size();
	if(l % 2 == 0){
		pari.insert(s,pari.begin());
		pari.next(pari.begin());
	}else{
		dispari.insert(s,dispari.begin());
		dispari.next(dispari.begin());
	}
}



 void eo_strings::rimuovi(string s) {
	 Linked_list<string>::position iter;
	 int l=s.size();
	 if(l % 2 == 0){
		 int i=0;
		 iter=pari.begin();
		 while(i<pari.size()){
			 if(pari.read(iter)==s){
				 cout<<pari.read(iter);
				 pari.erase(iter);
				 //cout<<"\nappoooo\n";
			 }
			 iter=pari.next(iter);
			 i++;
		 }
		 pari.begin();
	 }else{
		 int i=0;
		 iter=dispari.begin();
		 while(i<dispari.size()){
			 if(dispari.read(iter)==s){
				 cout<<dispari.read(iter);
				 dispari.erase(iter);
				 //cout<<"\nappoooo\n";
			 }
			 iter=dispari.next(iter);
			 i++;
		 }
		 dispari.begin();

	 }
 }

 void eo_strings::rimuovi(char c) {
	 Linked_list<string>::position iter;
	 iter=pari.begin();

	 int i=0;
	 while(i<=pari.size()){
		 string temp;
		 temp=pari.read(iter);
		 if(temp[0]==c){
			 pari.erase(iter);
		 }
		 iter=pari.next(iter);
		 i++;
	  }
 }


 void eo_strings::inserisci_posiziona(int p) {

	 Linked_list<string>::position iter;
	 iter=pari.begin();
	 int i=0;
	 while(i<=p){
		 iter=pari.next(iter);
		 i++;
	 }
	 pari.insert("asdasdasd", iter);

 }

int eo_strings::freq_pari() {

	return pari.size();
}

 void eo_strings::visualizza_dispari() {

	 cout<<dispari;
	 cout<<pari;
 }
