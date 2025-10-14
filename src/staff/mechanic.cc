#include "mechanic.h"
#include <iostream>
#include <string>
using namespace std;

Mechanic::Mechanic(): Employee(){
} 

Mechanic::Mechanic(const string _id, const string _name, const string _last, const int _age): Employee(_id, _name, _last, _age){
}

Mechanic::Mechanic(const Mechanic& _mech): Employee(_mech.ID_employee, _mech.name_employee, _mech.lastname_employee, _mech.age_employee){
}

bool Mechanic::operator <(const Mechanic& _mech) const{
  return this->ID_employee < _mech.ID_employee;
}  