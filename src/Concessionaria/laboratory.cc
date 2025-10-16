#include "laboratory.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

Laboratory::Laboratory(string _id) : ID_laboratory(_id), under_maintenance_cars(), available_mechanics(){
}

Laboratory::Laboratory(const Laboratory& _lab) : Concessionaria(_lab), ID_laboratory(_lab.ID_laboratory), under_maintenance_cars(_lab.under_maintenance_cars), available_mechanics(_lab.available_mechanics){
}

Laboratory::~Laboratory(){
}

void Laboratory::add_car(const Car& _car){//add car to under_maintenace_cars
  
  auto it = under_maintenance_cars.find(_car);

  if(it == under_maintenance_cars.end()) {
    under_maintenance_cars.insert(_car);  
  } else {
    cout << "Car already under maintenance!" << endl;
  }
}  

void Laboratory::remove_car(const Car& _car){//remove car from under_maintenace_cars
  
  auto it = under_maintenance_cars.find(_car);

  if(it == under_maintenance_cars.end()) {
    under_maintenance_cars.erase(_car);
  } else {
    cout << "Car already retired!" << endl;
  }
}

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

void Laboratory::add_mechanic(const Mechanic& _mech){
  auto it = available_mechanics.find(_mech);

  if(it == available_mechanics.end()) {
    available_mechanics.insert(_mech);
  } else {
    cout << "Mechanic already insert!" << endl;
  }
}