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

bool Laboratory::add_car(const Car& _car){
  
  auto it = under_maintenance_cars.find(_car);

  if(it == under_maintenance_cars.end()) {
    under_maintenance_cars.insert(_car);  
  } else {
    cout << "Car already under maintenance!" << endl;
  }
}  

bool Laboratory::remove_car(const Car& _car){
  
  auto it = under_maintenance_cars.find(_car);

  if(it == under_maintenance_cars.end()) {
    under_maintenance_cars.erase(_car);
  } else {
    cout << "Car already retired!" << endl;
  }
}

bool add_employee(const Employee& _empl){}
 
bool remove_employee(const Employee& _empl){}

Car find_car(const Car& _car){}

bool add_car_to_maintenance(Car& _car){}

bool Laboratory::fix_car(Car& _car) {

  if(available_mechanics.size() != 0) {
    auto it = available_mechanics.begin(); //doing a copy of the first available mechanic
    auto mech = *it;
    available_mechanics.erase(it);        //then erase the mechanic from the set

    //rimuovo tutti i problemi dalla macchina
    if(_car.remove_problems()) {//rimosssi tutti i problemi tolgo la macchina dal lab
      remove_car(_car);

      available_mechanics.insert(*it);  //re-push the mechanic in the set

      return true;
    } else {
      return false;
    }
  } else {
    cout << "Not available mechanics for repairing the car!" << endl;
    return false;
  }
}

bool Laboratory::add_mechanic(const Mechanic& _mech){

  auto it = available_mechanics.find(_mech);

  if(it == available_mechanics.end()) {
    available_mechanics.insert(_mech);
  } else {
    cout << "Mechanic already insert!" << endl;
  }
}

bool remove_mechanic(const Mechanic& _mech){}