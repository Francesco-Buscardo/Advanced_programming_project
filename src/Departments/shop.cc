#include "shop.h"
#include <iostream>
using namespace std;

int Shop::count_shops = 0;

Shop::Shop(): Department(), ID_shop(++count_shops){
}

Shop::Shop(const Shop& _shop): Department(_shop), ID_shop(_shop.ID_shop){
}

Shop::~Shop(){
} 

ostream& operator <<(ostream& os, const Shop& _shop){

	os << "-------------------------------------------" << endl
     << "Shop " << "ID: " << _shop.ID_shop << endl
     << "-------------------------------------------" << endl;
	for(auto* it: _shop.cars) {
		os << *it << endl;
	}
	for(auto it: _shop.sales) {
		os << "Car: " << *(it.first) 
			 << ", Customer: " << it.second << endl;
	}

	return os;
}

void Shop::add_car(Car* _car){

  auto it = cars.find(_car);

  if(it == cars.end()) {
    cars.insert(_car);
  } else {
    cout << "Already in!" << endl;
  }
}

void Shop::remove_car(Car* _car){
  
  auto it = cars.find(_car);

  if(it != cars.end()) {
    cars.erase(_car);
  } else {
    cout << "Car Already sold!" << endl;
  }
} 

void Shop::add_employee(Employee* _empl){
  
  auto it = employees.find(_empl);

  if(it == employees.end()) {
    employees.insert(_empl);
  } else {
    cout << "Employee already hired!" << endl;
  }
}

void Shop::remove_employee(Employee* _empl){
 
  auto it = employees.find(_empl);

  if(it != employees.end()) {
    employees.erase(_empl);
  } else {
    cout << "Employee not exits!" << endl;
  }
}

Car* Shop::find_car_by_ID(const int& _id){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_id == (*it)->get_ID()) {
      return *it;
    }
  }

  return nullptr;
}

Car* Shop::find_car_by_model(const string& _m){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_m == (*it)->get_model()) {
      return *it;
    }
  }

  return nullptr;
}      

void Shop::sell_to(Car* _car, Customer* _c){

  sales.push_back({_car, _c});

  remove_car(_car);
}