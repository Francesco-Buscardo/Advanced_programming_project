#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__

#include "../car.h"
#include "../Staff/employee.h"
#include "../Customer/customer.h"
#include "../Exceptions/not_available_value_exception.h"
#include <iostream>
#include <string>
#include <set>
#include <utility>
using namespace std;

class Car;      
class Employee; 

class Department{

  protected:
    set<Car*>      cars;
    set<Employee*> employees;
    set<Customer*> customers;

  public:
    Department();
    Department(const Department& _d);
    virtual ~Department();

    virtual ostream& print_operator (ostream& os) const;
    friend  ostream& operator <<    (ostream& os, const Department& _dep);

    virtual void       register_customer (Customer* _c);
    virtual void       remove_customer   (Customer* _c);
    virtual Customer*  get_customer      (const int& _id)   const;
    virtual void       add_car           (Car* _car);                
    virtual void       remove_car        (Car* _car);             
    virtual void       add_employee      (Employee* _empl);        
    virtual void       remove_employee   (Employee* _empl);        
    virtual Car*       find_car_by_ID    (const int& _id);       
    virtual Car*       find_car_by_model (const string& _m);        
    virtual int        get_ID            ()                 const = 0;   
    virtual void       add_customer      ();
};

ostream& operator <<(ostream& os, const Department& _dep);

#endif
