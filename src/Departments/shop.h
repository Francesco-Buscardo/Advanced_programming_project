#ifndef __SHOP_H__
#define __SHOP_H__

#include "Department.h"
#include "../Customer/customer.h"
#include <iostream>
using namespace std;

class Car;

class Shop: public Department{

  static int                    count_shops;
  int                           ID_shop;
  vector<pair<Car*, Customer*>> sales;

  public:
    Shop();    
    Shop(const Shop& _shop);
    ~Shop() override;  

    virtual ostream& print_operator (ostream& os) const;
    friend  ostream& operator <<    (ostream& os, const Shop& _shop);

    void sell_to (Car* _car, Customer* _c);      //sell the _car to _c and remove the _car from cars
    int  get_ID  ()                         const override;
};

ostream& operator <<(ostream& os, const Shop& _shop);

#endif