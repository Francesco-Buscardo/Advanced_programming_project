#ifndef __SHOP_EMPLOYEE_H__
#define __SHOP_EMPLOYEE_H__

#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

class Shop_employee: public Employee{
  public: 
    Shop_employee(); 
    Shop_employee(const string _name, const string _last, const int _age);
    Shop_employee(const Shop_employee& _sempl);
    ~Shop_employee() override = default;

    friend ostream& operator <<(ostream& os, const Shop_employee& _sempl);
    bool operator <(const Shop_employee& _sempl) const;
};

#endif