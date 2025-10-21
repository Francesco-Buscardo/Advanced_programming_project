#include "rental.h"
#include <iostream>
#include <set>
using namespace std;

int Rental::count_rentals = 0;

Rental::Rental(): Department(), ID_rental(++count_rentals), rentals_open(){
}

Rental::Rental(const Rental& _ren): Department(_ren), ID_rental(_ren.ID_rental), rentals_open(_ren.rentals_open){
}

Rental::~Rental(){
}

ostream& operator <<(ostream& os, const Rental& _ren){
	
	os << "-------------------------------------------" << endl
     << "Rental " << "ID: " << _ren.ID_rental << endl
     << "-------------------------------------------" << endl;
  for(auto* it: _ren.cars) {
		os << *it << endl;
	}
  for(auto it: _ren.rentals_open) {
		os << "Customer: " << *(it.first) 
			 << ", Date: " << it.second << endl;
	}
	
	return os;
}

void Rental::add_car(Car* _car){

  auto it = cars.find(_car);

  if(it == cars.end()) {
    cars.insert(_car);
  } else {
    cout << "Car already in!" << endl;
  }
}

void Rental::remove_car(Car* _car){
  
  auto it = cars.find(_car);

  if(it != cars.end()) {
    cars.erase(_car);
  } else {
    cout << "Already out!" << endl;
  }
}

void Rental::add_employee(Employee* _empl){
  
  auto it = employees.find(_empl);

  if(it == employees.end()) {
    employees.insert(_empl);
  } else {
    cout << "Employee already hired!" << endl;
  }
}

void Rental::remove_employee(Employee* _empl){
 
  auto it = employees.find(_empl);

  if(it != employees.end()) {
    employees.erase(_empl);
  } else {
    cout << "Employee not exits!" << endl;
  }
}

Car* Laboratory::find_car(Car* _car){

  auto it = cars.find(_car);

  return *it;
}

void Rental::register_rental(Customer* _c){

  Date d;

  rentals_open.insert({_c, d});
  
  cout << "Rental registered!" << endl; 
}

void Rental::register_return(Customer* _c, Date _d){

  auto it = rentals_open.find({_c, _d});

  if(it != rentals_open.end()) {
    rentals_open.erase({_c, _d});
  } else {
    cout << "Return already registered!" << endl;
  }
}

int Rental::calculate_rental(Customer* _c, Date _d){

  //10 euro x hour
  auto it = rentals_open.find({_c, _d});

  if(it == rentals_open.end()) {
    return 0;
  } else {
    int c; 

    

    return c;
  }
}
