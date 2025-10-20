#include "rental.h"
#include <iostream>
#include <set>
using namespace std;

int Rental::count_rentals = 0;

Rental::Rental(): Department(), ID_rental(++count_rentals), rental_cars(){
}

Rental::Rental(const Rental& _ren): Department(_ren), ID_rental(_ren.ID_rental), rental_cars(_ren.rental_cars){
}

Rental::~Rental(){
}

bool Rental::add_car(const Car& _car){

  auto it = rental_cars.find(_car);

  if(it == rental_cars.end()) {
    rental_cars.insert(_car);
  } else {
    cout << "Already in!" << endl;
  }
}

bool Rental::remove_car(const Car& _car){
  auto it = rental_cars.find(_car);

  if(it != rental_cars.end()) {
    rental_cars.erase(_car);
  } else {
    cout << "Already out!" << endl;
  }
}

bool Rental::add_employee(const Employee& _empl){
  for(auto e : employees) {
    if(*e == *_empl) {
      cout << "Employee already hires!" << endl;

      return;
    }
  }

  employees.insert(_empl);
}

bool Rental::remove_employee(const Employee& _empl){
  for(auto it = employees.begin(); it != employees.end(); ++it) {
    if(*it == _empl) {
      employees.erase(it);

      cout << "Employee removed!" << endl;

      return;
    }
  }

  cout << "Employee not exits!" << endl;
}