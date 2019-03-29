#include <iostream>
#include <string>
#include "Studente.h"
using namespace std;


Studente::Studente(string n, string c, string m)
{
   nome=n;
   cognome=c;
   matricola = m;
}

Studente::Studente()
{
   nome="";
   cognome="";
   matricola = "";
}

Studente::~Studente() {}

void Studente::setNome(string n)
{
  nome = n;
}


string Studente::getNome() const
{
  return nome;
}

string Studente::getCognome() const
{
  return cognome;
}

string Studente::getMatricola() const
{
  return matricola;
}

void Studente::stampa() const
{
  cout << "Nome: " << nome <<"\n";
  cout << "Cognome: " << cognome <<"\n";
  cout << "Matricola: " << matricola <<"\n";
}

ostream &operator<<(ostream &os, const Studente &s)
{
     return (os << s.getMatricola() << " - " << s.getCognome() << " "<<s.getNome());
}
