#include "rental.h"
#include <iostream>
using namespace std;

Rental::Rental(string _id): ID_rental(_id), rental_cars(){
}

Rental::Rental(const Rental& _ren): Concessionaria(_ren), ID_rental(_ren.ID_rental), rental_cars(_ren.rental_cars){
}

Rental::~Rental(){
}

void Rental::add_car(const Car& _car){

  auto it = rental_cars.find(_car);

  if(it == rental_cars.end()) {
    rental_cars.insert(_car);
  } else {
    cout << "Already in!" << endl;
  }
}

void Rental::remove_car(const Car& _car){
  auto it = rental_cars.find(_car);

  if(it != rental_cars.end()) {
    rental_cars.erase(_car);
  } else {
    cout << "Already out!" << endl;
  }
}