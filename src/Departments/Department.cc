#include "Department.h"
#include <iostream>
#include <set>
#include <utility>

Department::Department(): cars(), employees(), customers(){
}

Department::Department(const Department& _d){

  for(auto c : _d.cars) {
    cars.insert(new Car(*c));
  }
  for(auto e : _d.employees) {
    employees.insert(new Employee(*e));
  }
  for(auto c : _d.customers) {
    customers.insert(new Customer(*c));
  }
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

  if(customers.find(_c) == customers.end()) {
    customers.insert(_c);
  } else {
    cout << "Customer already registered!" << endl;
  }
}
    
void Department::remove_customer(Customer* _c){
  
  if(customers.find(_c) != customers.end()) {
    customers.erase(_c);
    delete _c;
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

  if(cars.find(_car) == cars.end()) {
    cars.insert(_car);
  } else {
    cout << "Already in!" << endl;
  }
}

void Department::remove_car(Car* _car){
  
  if(cars.find(_car) != cars.end()) {
    cars.erase(_car);
    delete _car;
  } else {
    cout << "Car Already sold!" << endl;
  }
} 

void Department::add_employee(Employee* _empl){
  
  if(employees.find(_empl) == employees.end()) {
    employees.insert(_empl);
  } else {
    cout << "Employee already hired!" << endl;
  }
}

void Department::remove_employee(Employee* _empl){
 
  if(employees.find(_empl) != employees.end()) {
    employees.erase(_empl);
    delete _empl;
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

void Department::add_customer(){

  string name_customer;
  string lastname_customer;
  int    age_customer;

  cout << "Ins name: ";
  cin  >> name_customer;
  cout << "Ins name: ";
  cin  >> lastname_customer;
  cout << "Ins name: ";
  cin  >> age_customer;
  if(age_customer < 18) {
    throw Not_Available_Value_Exception("Age < 18");
  }

  customers.insert(new Customer(name_customer, lastname_customer, age_customer));
}
