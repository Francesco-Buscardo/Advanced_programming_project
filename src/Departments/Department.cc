#include "Department.h"
#include <iostream>
#include <set>
#include <utility>

Department::Department(): cars(), employees(), customers(){
}

Department::Department(const Department& _d): cars(_d.cars), employees(_d.employees), customers(_d.customers){
}

Department::~Department(){

  for(auto c : cars) {
    delete c;
  }
  cars.clear();

  for(auto e : employees) {
    delete e;
  }
  employees.clear();
  
  for(auto c : customers) {
    delete c;
  }
  customers.clear();
}

ostream& Department::print_operator(ostream& os) const{

	os << "-------------------------------------------" << endl
     << "Department" << endl
     << "-------------------------------------------" << endl;
	for(auto* it: this->cars) {
		os << *it << endl;
	}
  for(auto* it: this->employees) {
		os << *it << endl;
	}
  for(auto* it: this->customers) {
		os << *it << endl;
	}

	return os;
} 

ostream& operator <<(ostream& os, const Department& _dep){

  return _dep.print_operator(os);
}

void Department::register_customer(Customer* _c){

  auto it = customers.find(_c);

  if(it == customers.end()) {
    customers.insert(*it);
  } else {
    cout << "Customer already registered!" << endl;
  }
}
    
void Department::remove_customer(Customer* _c){
  
  auto it = customers.find(_c);

  if(it != customers.end()) {
    customers.erase(*it);
  } else {
    cout << "Customer doesnt exist!" << endl;
  }
}

Customer* Department::get_customer(const int& _id) const{

  for(auto it = customers.begin(); it != customers.end(); ++it) {
    if((*it)->get_ID() == _id){
      return *it;
    }
  }

  return nullptr;
}

void Department::add_car(Car* _car){

  auto it = cars.find(_car);

  if(it == cars.end()) {
    cars.insert(*it);
  } else {
    cout << "Already in!" << endl;
  }
}

void Department::remove_car(Car* _car){
  
  auto it = cars.find(_car);

  if(it != cars.end()) {
    delete *it;
    cars.erase(*it);
  } else {
    cout << "Car Already sold!" << endl;
  }
} 

void Department::add_employee(Employee* _empl){
  
  auto it = employees.find(_empl);

  if(it == employees.end()) {
    employees.insert(*it);
  } else {
    cout << "Employee already hired!" << endl;
  }
}

void Department::remove_employee(Employee* _empl){
 
  auto it = employees.find(_empl);

  if(it != employees.end()) {
    delete *it;
    employees.erase(*it);
  } else {
    cout << "Employee not exits!" << endl;
  }
}

Car* Department::find_car_by_ID(const int& _id){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_id == (*it)->get_ID()) {
      return *it;
    }
  }

  return nullptr;
}

Car* Department::find_car_by_model(const string& _m){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_m == (*it)->get_model()) {
      return *it;
    }
  }

  return nullptr;
} 