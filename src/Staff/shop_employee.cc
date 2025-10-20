#include "shop_employee.h"
#include <iostream>
#include <string>
using namespace std;

Shop_employee::Shop_employee(): Employee(){
}

Shop_employee::Shop_employee(const string _name, const string _last, const int _age): Employee(_name, _last, _age) {
}

Shop_employee::Shop_employee(const Shop_employee& _sempl): Employee(_sempl){
}

bool Shop_employee::operator <(const Shop_employee& _sempl) const{
  
  return this->ID_employee <= _sempl.ID_employee;
}
