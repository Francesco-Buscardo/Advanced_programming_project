#include "rental_employee.h"
#include <iostream>
#include <string>
using namespace std;

Rental_employee::Rental_employee(): Employee(){
}

Rental_employee::Rental_employee(const string _name, const string _last, const int _age): Employee(_name, _last, _age) {
}

Rental_employee::Rental_employee(const Rental_employee& _rempl): Employee(_rempl){
}

bool Rental_employee::operator <(const Employee& _rempl) const{
  
  return this->ID_employee < _rempl.get_ID();
}
