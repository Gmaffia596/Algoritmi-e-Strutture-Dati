#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Studente.h"
#include "Dizionario.h"


using namespace std;

void presente (string matricola, circLista<Studente>& l1, circLista<Studente>& l2) //CONTROLLO SE UNO STUDENTE è presente
{
  Dizionario<string,Studente> d1(3);
  Dizionario<string,Studente> d2(3);
  circLista<Studente>::posizione indiceElemento = l1.primoLista();
  while (!l1.finelista(indiceElemento))
  {
        d1.inserisci(l1.leggilista(indiceElemento).getMatricola(),l1.leggilista(indiceElemento));
        indiceElemento=l1.succlista(indiceElemento);
  }
  if (d1.appartiene(matricola))
  {
     cout << "Studente " << matricola << " presente nel primo dizionario\n";
     d1.recupera(matricola).stampa();
  }
  else
  {
      indiceElemento =  l2.primoLista();
      while (!l2.finelista(indiceElemento))
      {
        d2.inserisci(l2.leggilista(indiceElemento).getMatricola(),l2.leggilista(indiceElemento));
        indiceElemento=l2.succlista(indiceElemento);
      }
      if (d2.appartiene(matricola))
      {
              cout << "Studente " << matricola << " presente nel secondo dizionario \n";
         d2.recupera(matricola).stampa();
      }
      else
           cout << "Studente " << matricola << " assente\n";
  }
}

int conta_1_no_2(circLista<Studente>& l1, circLista<Studente>& l2)
{
     Dizionario<string,Studente> d(3);
     circLista<Studente>::posizione indiceElemento = l2.primoLista();
     while (!l2.finelista(indiceElemento))
      {
        d.inserisci(l2.leggilista(indiceElemento).getMatricola(),l2.leggilista(indiceElemento));
        indiceElemento=l2.succlista(indiceElemento);
      }
      // ho riempito il dizionario con gli elementi della lista2
      int counter=0;
      indiceElemento = l1.primoLista();
      while (!l1.finelista(indiceElemento))
      {
        if (!d.appartiene(l1.leggilista(indiceElemento).getMatricola())) //se nel dizionario non è presente la matricola letta dalla prima lista
           counter++; //incremento il contatore
        indiceElemento=l1.succlista(indiceElemento);
      }
      return counter;
}


int main(int argc, char *argv[])
{
    circLista<Studente> lezione1; //LISTA CIRCOLARE DELLA LEZIONE 1
    circLista<Studente> lezione2; //LSITA CIRCOLARE DELLA LEZIONE 2
    // studenti

    Studente s1("paolo","rossi","12354"); // lez1
    Studente s2("mario","bianchi","12366"); // lez1
    Studente s3("antonio","verdi","12386"); // lez1 + lez2
    Studente s4("pinco","pallino","12554"); // lez2
    Studente s5("rosa","berardi","14386"); // lez1
    Studente s6("arianna","longo","12777"); // lez 2
    Studente s7("anna","marchesi","13732"); // lez 2
    Studente s8("giulio","bernardi","15690"); // lez1 + lez 2

    // riempiamo la prima lista
    circLista<Studente>::posizione indiceElemento = lezione1.primoLista();
    lezione1.inslista(s1,indiceElemento=lezione1.succlista(indiceElemento));
    lezione1.inslista(s2,indiceElemento=lezione1.succlista(indiceElemento));
    lezione1.inslista(s3,indiceElemento=lezione1.succlista(indiceElemento));
    lezione1.inslista(s5,indiceElemento=lezione1.succlista(indiceElemento));
    lezione1.inslista(s8,indiceElemento=lezione1.succlista(indiceElemento));
    // riempiamo la seconda lista
    indiceElemento = lezione2.primoLista();
    lezione2.inslista(s3,indiceElemento=lezione2.succlista(indiceElemento));
    lezione2.inslista(s4,indiceElemento=lezione2.succlista(indiceElemento));
    lezione2.inslista(s6,indiceElemento=lezione2.succlista(indiceElemento));
    lezione2.inslista(s7,indiceElemento=lezione2.succlista(indiceElemento));
    lezione2.inslista(s8,indiceElemento=lezione2.succlista(indiceElemento));

    // stampo i dati acquisiti
    cout<<"------------------STAMPO LA LISTA DEGLI STUDENTI PRESENTI ALLA PRIMA LEZIONE-----------------"<<endl;
    lezione1.stampaLista();
    cout<<endl;
    cout<<"------------------STAMPO LA LISTA DEGLI STUDENTI PRESENTI ALLA SECONDA LEZIONE-----------------"<<endl;
    lezione2.stampaLista();
	cout<<endl;
	
	cout<<"->CONTROLLO SE LA MATRICOLA 13732 E' PRESENTE NEL DIZIONARIO<-"<<endl;
    presente("13732", lezione1,lezione2); //VUOLE SAPERE SE LA MATRICOLA ERA PRESENTE AD ENTRAMBE LE LEZIONI
    										//VUOLE SAPERE SE L'ELEMENTO E' PRESENTE IN ENTRAMBI I DIZIONARI
    cout<<"->CONTROLLO SE LA MATRICOLA 13731 E' PRESENTE NEL DIZIONARIO<-"<<endl;
	presente("13731", lezione1,lezione2);
    cout<<"->CONTROLLO SE LA MATRICOLA 12386 E' PRESENTE NEL DIZIONARIO<-"<<endl;
	presente("12386", lezione1,lezione2);
	cout<<endl;
    cout << "Partendo dalle persone della seconda lezione, rispetto alla prima mancano : " <<  conta_1_no_2(lezione1,lezione2) <<" persone all'appello"<< endl;
    return 0;
}
