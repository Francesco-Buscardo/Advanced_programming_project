#include "mechanic.h"
#include <iostream>
#include <string>
using namespace std;

Mechanic::Mechanic(): Employee(){
} 

Mechanic::Mechanic(const string _name, const string _last, const int _age): Employee(_name, _last, _age){
}

Mechanic::Mechanic(const int _id, const string _name, const string _last, const int _age): Employee(_id, _name, _last, _age){
}

Mechanic::Mechanic(const Mechanic& _mech): Employee(_mech.name_employee, _mech.lastname_employee, _mech.age_employee){
}
