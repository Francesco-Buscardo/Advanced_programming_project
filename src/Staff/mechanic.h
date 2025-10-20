#ifndef __MECHANIC_H__
#define __MECHANIC_H__

#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

class Mechanic: public Employee{
  public: 
    Mechanic(); 
    Mechanic(const string _name, const string _last, const int _age);
    Mechanic(const Mechanic& _mech);
    ~Mechanic() override = default;

    friend ostream& operator <<(ostream& os, const Mechanic& _mech);
    bool operator <(const Mechanic& _mech) const;
};

#endif