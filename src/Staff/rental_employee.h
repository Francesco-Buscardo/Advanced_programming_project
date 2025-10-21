#ifndef __RENTAL_EMPLOYEE_H__
#define __RENTAL_EMPLOYEE_H__

#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

class Rental_employee: public Employee{
  public: 
    Rental_employee(); 
    Rental_employee(const string _name, const string _last, const int _age);
    Rental_employee(const Rental_employee& _rempl);
    ~Rental_employee() override = default;

    bool operator <(const Rental_employee& _rempl) const;
};

#endif