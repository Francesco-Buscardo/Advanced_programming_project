#include "laboratory.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

int Laboratory::count_labs = 0;

Laboratory::Laboratory(): Department(), ID_laboratory(++count_labs), under_maintenance_cars(), available_mechanics(){
}

Laboratory::Laboratory(const Laboratory& _lab) : Department(_lab), ID_laboratory(_lab.ID_laboratory), under_maintenance_cars(_lab.under_maintenance_cars), available_mechanics(_lab.available_mechanics){
}

Laboratory::~Laboratory(){
}

ostream& operator <<(ostream& os, const Laboratory& _lab){
	
	os << "-------------------------------------------" << endl
     << "Lab " << "ID: " << _lab.ID_laboratory << endl
     << "-------------------------------------------" << endl;
	for(auto* it: _lab.cars) {
		os << *it << endl;
	}
  for(auto it: _lab.under_maintenance_cars) {
		os << *it << endl;
	}
  for(auto it: _lab.available_mechanics) {
		os << *it << endl;
	}

	return os;
}

void Laboratory::add_car(Car* _car){
  
  auto it = cars.find(_car);

  if(it == cars.end()) {
    cars.insert(_car);  
  }
}  

void Laboratory::remove_car(Car* _car){
  
  auto it = cars.find(_car);

  if(it != under_maintenance_cars.end()) {
    cars.erase(_car);
  }
}

void Laboratory::add_employee(Employee* _empl){

  auto it = employees.find(_empl);

  if(it == employees.end()) {
    employees.insert(_empl);
  }
}
 
void Laboratory::remove_employee(Employee* _empl){

  auto it = employees.find(_empl);

  if(it != employees.end()) {
    employees.erase(_empl);
  }
}

Car* Laboratory::find_car_by_ID(const int& _id){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_id == (*it)->get_ID()) {
      return *it;
    }
  }

  return nullptr;
}

Car* Laboratory::find_car_by_model(const string& _m){

  for(auto it = cars.begin(); it != cars.end(); ++it){
    if(_m == (*it)->get_model()) {
      return *it;
    }
  }

  return nullptr;
}

void Laboratory::add_car_to_maintenance(Car* _car){

  auto it = under_maintenance_cars.find(_car);

  if(it == under_maintenance_cars.end()){
    under_maintenance_cars.insert(_car);
  }
}

void Laboratory::fix_car(Car* _car){

  if(available_mechanics.size() != 0) {
    auto it = available_mechanics.begin(); //doing a copy of the first available mechanic
    Employee* mech = *it;

    remove_mechanic(mech);

    //remove problems from car
    while(!_car->get_problems_car().empty()) {
      _car->remove_problem();
    }
    //then remove the car from under_maintenance_cars
    remove_car(_car);

    available_mechanics.insert(*it);  //re-push the mechanic in the set
  } else {
    cout << "Not available mechanics for repairing the car!" << endl;
  }
}

void Laboratory::add_mechanic(Employee* _mech){

  auto it = available_mechanics.find(_mech);

  if(it == available_mechanics.end()) {
    available_mechanics.insert(_mech);
  } else {
    cout << "Mechanic already insert!" << endl;
  }
}

void Laboratory::remove_mechanic(Employee* _mech){
  
  auto it = available_mechanics.find(_mech);

  if(it != available_mechanics.end()) {
    available_mechanics.erase(_mech);
  } else {
    cout << "Mechanic already removed!" << endl;
  }
}