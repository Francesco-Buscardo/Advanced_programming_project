#include "customer.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

int Customer::count_customer = 0;

Customer::Customer(): ID_customer(-1), name_customer(""), lastname_customer(""), age_customer(0), rental_cars(), bought_cars(){
}

Customer::Customer(const string& _n, const string& _l, const int& _a): ID_customer(++count_customer), name_customer(_n), lastname_customer(_l), age_customer(_a), rental_cars(), bought_cars(){
}

Customer::Customer(const Customer& _c): ID_customer(_c.ID_customer), name_customer(_c.name_customer), lastname_customer(_c.lastname_customer), age_customer(_c.age_customer){

  for(auto c : _c.rental_cars) {
    rental_cars.push_back(new Car(*c));
  }
  for(auto c : _c.bought_cars) {
    bought_cars.push_back(new Car(*c));
  }
}

Customer::~Customer(){

  for(auto c : rental_cars) {
    delete c;
  }
  rental_cars.clear();
  
  for(auto c : bought_cars) {
    delete c;
  }
  bought_cars.clear();
}

ostream& operator <<(ostream& os, const Customer& _c){

	os << "Customer ID: " << _c.ID_customer; 

	return os; 
}

bool Customer::operator <(const Customer* _c) const {
  
  return this->ID_customer < _c->ID_customer;
}

bool Customer::operator ==(const Customer& _c) const{

  return this->ID_customer == _c.get_ID();
}

void Customer::rent_car(Car* _car){

  rental_cars.push_back(_car);

  cout << "Car rental!" << endl;
}

void Customer::return_car(Car* _car){

  for(auto it = rental_cars.begin(); it != rental_cars.end();  ++it) {
    if(*it == _car) {
      rental_cars.erase(it);
      delete *it;
      cout << "Car returned!" << endl;
    }
  }

  cout << "Car didnt rental!" << endl;
}

void Customer::buy_car(Car* _car){
  
  bought_cars.push_back(_car);

  cout << "Car bought!" << endl;
}

void Customer::sell_car(Car* _car){

  for(auto it = bought_cars.begin(); it != bought_cars.end();  ++it) {
    if(*it == _car) {
      bought_cars.erase(it);
      delete *it;
      cout << "Car sold!" << endl;
    }
  }

  cout << "Car didnt bought!" << endl;
}

int  Customer::get_ID() const{

  return this->ID_customer;
}