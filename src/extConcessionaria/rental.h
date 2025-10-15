#ifndef RENTAL_H
#define RENTAL_H

#include "../Concessionaria.h"
#include "../car.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Rental: public Concessionaria{

  protected:
    string ID_rental;
    set<Car> rental_cars;

  public:
    Rental(string _id);
    Rental(const Rental& _ren);
    ~Rental();

    friend ostream& operator <<(ostream& os, const Rental& _ren);

    void add_car(const Car& _car);     //add car to rental_cars
		void remove_car(const Car& _car);  //remove car from rental_cars
};

#endif