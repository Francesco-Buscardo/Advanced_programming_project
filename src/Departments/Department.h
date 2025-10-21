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
    set<Car*> cars;
    set<Employee*> employees;

  public:
    Department();
    Department(const Department& _d);
    virtual ~Department();

    virtual void add_car         (Car* _car)       = 0;   
    virtual void remove_car      (Car* _car)       = 0;
    virtual void add_employee    (Employee* _empl) = 0;
    virtual void remove_employee (Employee* _empl) = 0;
    virtual Car* find_car        (Car* _car)       = 0;       
};

#endif
