#ifndef __SHOP_H__
#define __SHOP_H__

#include "Department.h"
#include <iostream>
using namespace std;

class Shop: public Department{

  static int count_shops;
  int        ID_shop;

  public:
    Shop();    
    Shop(const Shop& _shop);
    ~Shop() override;  

    friend ostream& operator <<(ostream& os, const Shop& _shop);


    bool add_car         (const Car& _car)                     override;  //add car to cars
		bool remove_car      (const Car& _car)                     override;  //remove car from cars
    bool add_employee    (const Employee& _empl)               override;  //add employee to employees
    bool remove_employee (const Employee& _empl)               override;  //remove employee from employees
    Car  find_car        (const Car& _car)                     override;  //find the _car in cars       
    void sell_to         (const Car& _car, const Customer& _c);           //sell the _car to _c and remove the _car from cars
};

#endif