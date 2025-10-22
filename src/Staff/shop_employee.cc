#include "shop_employee.h"
#include <iostream>
#include <string>
using namespace std;

Shop_employee::Shop_employee(): Employee(){
}

Shop_employee::Shop_employee(const string _name, const string _last, const int _age): Employee(_name, _last, _age) {
}

Shop_employee::Shop_employee(const int _id, const string _name, const string _last, const int _age): Employee(_id, _name, _last, _age){ 
}

Shop_employee::Shop_employee(const Shop_employee& _sempl): Employee(_sempl){
}

bool Shop_employee::operator <(const Employee& _sempl) const{
  
  return this->ID_employee < _sempl.get_ID();
}
