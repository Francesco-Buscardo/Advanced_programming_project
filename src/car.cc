#include "car.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Car::count_cars = 0;

Car::Car() : ID_car(-1), fuel_car(GASOLINE), price_car(0.0), model_car("null"), problems_car(){
}

Car::Car(const Fuel _fl, const long double _prc, const string _mdl): ID_car(++count_cars), fuel_car(_fl), price_car(_prc), model_car(_mdl), problems_car(){
}

Car::Car(const Car& _car): ID_car(_car.ID_car), fuel_car(_car.fuel_car), price_car(_car.price_car), model_car(_car.model_car){

  for(auto p : _car.problems_car){
    problems_car.push_back(new Problem(*p));
  }
}

Car::~Car(){

  for(auto p : problems_car){
    delete p;
  }
  problems_car.clear();
}

ostream& operator <<(ostream& os, const Car& _car){
 
  os << "-------------------------------------------" << endl
     << "Car " << "ID: " << _car.ID_car << endl
     << "-------------------------------------------" << endl
     << "Model: " << _car.model_car << endl 
     << "Price: " << _car.price_car << endl
     << "Fuel: " << _car.fuel_car << endl
     << "-------------------------------------------" << endl;
  return os;
}

bool Car::operator <(const Car* _car) const {
  
  return this->ID_car < _car->ID_car;
}

bool Car::operator ==(const Car& _c) const{
  
  return this->ID_car == _c.get_ID();
}

void Car::add_problem(Problem* _p){

  problems_car.push_back(_p);
}

void Car::remove_problem() {

  delete problems_car.back();
  problems_car.pop_back();
}

vector<Problem*> Car::get_problems_car() const{

  return problems_car;
}

int Car::get_ID() const{
  
  return ID_car;
}

string Car::get_model() const{
  
  return model_car;
}