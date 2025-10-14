#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee{

  protected:
    string ID_employee;
    string name_employee;
    string lastname_employee;
    int age_employee;

  public:
    Employee();
    Employee(const string _id, const string _name, const string _last, const int _age);
    Employee(const Employee& _empl);
    virtual ~Employee() = default;

};

#endif
