#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include <iostream>
using namespace std;

class Concessionaria {
  string name;

  public:
    Concessionaria();
    Concessionaria(string _n);
    Concessionaria(const Concessionaria& _c); // costruttore copia
    ~Concessionaria();

    //OPERATORI
    
    //METODI
};

#endif
