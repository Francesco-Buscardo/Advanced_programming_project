#include "car.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Car::count_cars = 0;

ostream& operator <<(ostream& os, const Fuel& _ps) {
  
  switch (_ps) {
    case GASOLINE: os << "Gasoline"; 
                  break;
    case DIESEL: os << "Diesel"; 
                break;
    case ELECTRIC: os << "Electric"; 
                  break;
    case HYBRID: os << "Hybrid"; 
                break;
    default: os << "Nothing"; 
            break;
  }
  return os;
}

ostream& operator <<(ostream& os, const Car& _car) {
 
  os << "-------------------------------------------" << endl
     << "Car " << "ID: " << _car.ID_car << endl
     << "-------------------------------------------" << endl
     << "Model: " << _car.model_car << endl 
     << "Price: " << _car.price_car << endl
     << "Production Year: " << _car.production_year_car << endl
     << "Power Supply: " << _car.power_supply_car << endl
     << "Color (HEX): " << _car.color_car << endl
     << "Size (mm): " << _car.size_car << endl
     << "-------------------------------------------" << endl;
  return os;
}

bool Car::operator <(const Car& _car) const {
  
  return this->ID_car <= _car.ID_car;
}

Car::Car() : ID_car(-1), fuel_car(NOTHNG), price_car(0.0), model_car("null"), problems_car(){
}

Car::Car(const Fuel _fl, const long double _prc, const string _mdl): ID_car(++count_cars), fuel_car(_fl), price_car(_prc), model_car(_mdl){
}

Car::Car(const Car& _car): ID_car(_car.ID_car), fuel_car(_car.fuel_car), price_car(_car.price_car), model_car(_car.model_car){

  problems_car.clear();
  for(auto it : _car.problems_car){
    problems_car.push_back(it);
  }
}

void Car::add_problem(const Problem& _p){
  
  for(auto p : problems_car) {
    if(*p == _p) {
      cout << "Problem already in!" << endl;

      return;
    } 
  }

  problems_car.push_back(new Problem(_p));
}

bool Car::remove_problems() {

  problems_car.clear();

  return problems_car.empty();
}