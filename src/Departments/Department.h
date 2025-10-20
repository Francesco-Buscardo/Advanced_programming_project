#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__

#include "../car.h"
#include "../Staff/employee.h"
#include <iostream>
#include <set>
#include <utility>
using namespace std;

class Department {

  protected:
    set<pair<Car, int>> cars;
    set<Employee*>      employees;

  public:
    Department();
    Department(const Department& _d);
    virtual ~Department();

    virtual bool add_car         (const Car& _car)       = 0;   
    virtual bool remove_car      (const Car& _car)       = 0;
    virtual bool add_employee    (const Employee& _empl) = 0;
    virtual bool remove_employee (const Employee& _empl) = 0;
    virtual Car  find_car        (const Car& _car)       = 0;       
};

#endif
