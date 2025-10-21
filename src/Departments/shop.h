#ifndef __SHOP_H__
#define __SHOP_H__

#include "Department.h"
#include "../Customer/customer.h"
#include <iostream>
using namespace std;

class Shop: public Department{

  static int                    count_shops;
  int                           ID_shop;
  vector<pair<Car*, Customer*>> sales;

  public:
    Shop();    
    Shop(const Shop& _shop);
    ~Shop() override;  

    friend ostream& operator <<(ostream& os, const Shop& _shop);

    void add_car         (Car* _car)                     override;  //add car to cars
		void remove_car      (Car* _car)                     override;  //remove car from cars
    void add_employee    (Employee* _empl)               override;  //add employee to employees
    void remove_employee (Employee* _empl)               override;  //remove employee from employees
    Car* find_car        (Car* _car)                     override;  //find the _car in cars       
    void sell_to         (Car* _car, Customer* _c);                 //sell the _car to _c and remove the _car from cars
};

ostream& operator <<(ostream& os, const Shop& _shop);

#endif