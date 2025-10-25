#include "laboratory.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

int Laboratory::count_labs = 0;

Laboratory::Laboratory(): Department(), ID_laboratory(++count_labs), available_mechanics(){
}

Laboratory::Laboratory(const Laboratory& _lab) : Department(_lab), ID_laboratory(_lab.ID_laboratory), available_mechanics(_lab.available_mechanics){
}

Laboratory::~Laboratory(){

  for(auto m : available_mechanics) {
    delete m;
  }
  available_mechanics.clear();
}

ostream& Laboratory::print_operator(ostream& os) const{
  
  os << "-------------------------------------------" << endl
     << "Lab " << "ID: " << this->ID_laboratory << endl
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
  for(auto it: this->available_mechanics) {
		os << *it << endl;
	}

  return os;
}

ostream& operator <<(ostream& os, const Laboratory& _lab){
	
	return _lab.print_operator(os);
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
    //then remove the car from cars
    remove_car(_car);

    available_mechanics.insert(*it);  //re-push the mechanic in the set
  } else {
    cout << "Not available mechanics for repairing the car!" << endl;
  }
}

void Laboratory::add_mechanic(Employee* _mech){

  auto it = available_mechanics.find(_mech);

  if(it == available_mechanics.end()) {
    available_mechanics.insert(*it);
  } else {
    cout << "Mechanic already insert!" << endl;
  }
}

void Laboratory::remove_mechanic(Employee* _mech){
  
  auto it = available_mechanics.find(_mech);

  if(it != available_mechanics.end()) {
    delete *it;
    available_mechanics.erase(it);
  } else {
    cout << "Mechanic already removed!" << endl;
  }
}

int Laboratory::get_ID() const{

  return ID_laboratory;
}