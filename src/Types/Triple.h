#ifndef __TRIPLE_H__
#define __TRIPLE_H__

#include "../Customer/customer.h"
#include "../car.h"
#include "Date.h"
#include <iostream>
using namespace std;

typedef struct{
  Customer* c; 
  Date*     d;
  Car*      cr;
}Triple_t;

class Triple {
  Triple_t t;

  public:
    Triple();
    Triple(const Customer& _c, const Date& _d, const Car& _cr);
    Triple(const Triple& _t);
    ~Triple();

    Customer* get_customer() const;
    Date*     get_date()     const;
    Car*      get_car()      const;
};

#endif