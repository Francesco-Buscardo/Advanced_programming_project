#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "../car.h"
#include <iostream>
using namespace std;

class Concessionaria {
  protected:
    string name;

  public:
    Concessionaria();
    Concessionaria(string _n);
    Concessionaria(const Concessionaria& _c); // costruttore copia
    virtual ~Concessionaria() = default;

    virtual void add_car(const Car& _car);   
		virtual void remove_car(const Car& _car);
};

#endif
