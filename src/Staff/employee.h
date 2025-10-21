#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <string>
using namespace std;

class Employee{

  protected:
    static int count_employees;
    int        ID_employee;
    string     name_employee;
    string     lastname_employee;
    int        age_employee;

  public:
    Employee();
    Employee(const string _name, const string _last, const int _age);
    Employee(const Employee& _empl);
    virtual ~Employee();

    virtual bool operator     < (const Employee& _empl) const = 0;
    friend  ostream& operator <<(ostream& os, const Employee& _empl);
};

ostream& operator <<(ostream& os, const Employee& _empl);

#endif
