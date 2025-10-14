#include "laboratory.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

Laboratory::Laboratory(string _id) : ID_laboratory(_id), under_maintenace_cars(){
}

Laboratory::Laboratory(const Laboratory& _lab) : Concessionaria(_lab), ID_laboratory(_lab.ID_laboratory), under_maintenace_cars(_lab.under_maintenace_cars){
}

Laboratory::~Laboratory(){
}

void Laboratory::add_car(const Car& _car){//add car to under_maintenace_cars
  
  auto it = under_maintenace_cars.find(_car);

  if(it == under_maintenace_cars.end()) {
    under_maintenace_cars.insert(_car);  
  } else {
    cout << "Car already under maintenace!" << endl;
  }
}  

void Laboratory::remove_cars(const Car& _car){//remove car from under_maintenace_cars
  
  auto it = under_maintenace_cars.find(_car);

  if(it == under_maintenace_cars.end()) {
    under_maintenace_cars.erase(_car);
  } else {
    cout << "Car already retired!" << endl;
  }
}

bool Laboratory::fix_car(Car& _car) {
  return true;
}