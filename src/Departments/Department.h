#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__

#include "../car.h"
#include "../Staff/employee.h"
#include "../Customer/customer.h"
#include <iostream>
#include <string>
#include <set>
#include <utility>
using namespace std;

class Department {

  protected:
    set<Car*>      cars;
    set<Employee*> employees;
    set<Customer*> customers;

  public:
    Department();
    Department(const Department& _d);
    virtual ~Department();

    void         register_customer (Customer* _c);
    void         remove_customer   (Customer* _c);
    Customer*    get_customer      (const int& _id) const;

    virtual void add_car           (Car* _car)        = 0;   
    virtual void remove_car        (Car* _car)        = 0;
    virtual void add_employee      (Employee* _empl)  = 0;
    virtual void remove_employee   (Employee* _empl)  = 0;
    virtual Car* find_car_by_ID    (const int& _id)   = 0;
    virtual Car* find_car_by_model (const string& _m) = 0;    
};

#endif
