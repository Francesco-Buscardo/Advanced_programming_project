#include "rental.h"
#include <iostream>
#include <set>
#include <utility>
#include <ctime>
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

Car* Rental::find_car_by_ID(const int& _id){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_id == (*it)->get_ID()) {
      return *it;
    }
  }

  return nullptr;
}

Car* Rental::find_car_by_model(const string& _m){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_m == (*it)->get_model()) {
      return *it;
    }
  }

  return nullptr;
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

int Rental::get_rate() const{

  return this->rate;
}                            


int Rental::diff_in_days(const Date& _start, const Date& _today) const {
  tm a = {0,0,0, _start.get_day(), _start.get_month() - 1, _start.get_year() - 1900};
  tm b = {0,0,0, _today.get_day(), _today.get_month() - 1, _today.get_year() - 1900};

  time_t aa = mktime(&a);
  time_t bb = mktime(&b);

  return static_cast<int>(difftime(bb, aa) / (60 * 60 * 24));
}


int Rental::calculate_rental(Customer* _c, const Date& _d){

  auto it = rentals_open.begin();
  while(it != rentals_open.end()) {
    if(it->first == _c) {
      break; 
    }
    ++it;
  }

  if(it == rentals_open.end()) {
    return 0;
  } else {
    Date start_rental = it->second;
    int  days         = diff_in_days(start_rental, _d);
    int  hours        = days * 24;

    return hours * rate;
  }
}
