#ifndef STUDENTE_H
#define STUDENTE_H

#include <string>
#include <iostream>
using namespace std;

class Studente {
    friend ostream &operator<<(ostream&, const Studente &);
public:
   Studente(string, string, string);
   Studente();
   ~Studente();
   string getNome() const;
   void setNome(string);
   string getCognome() const ;
   string getMatricola() const;
   void stampa() const;
private:
   string nome;
   string cognome;
   string matricola;
};

#endif
