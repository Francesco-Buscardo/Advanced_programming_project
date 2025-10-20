#include "Department.h"
#include <iostream>
#include <set>
#include <utility>

Department::Department(): cars(), employees(){
}

Department::Department(const Department& _d): cars(_d.cars), employees(_d.employees){
}

Department::~Department(){
  for(auto e: employees){
    delete e;
  }
}
