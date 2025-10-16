#ifndef SHOP_H
#define SHOP_H

#include "Concessionaria.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Shop: public Concessionaria{

  protected:
    string ID_shop;
    set<Car> cars_for_sale; //available mechanics for repairing cars

  public:
    Shop(string _id);    
    Shop(const Shop& _shop);
    ~Shop();  

    friend ostream& operator <<(ostream& os, const Shop& _shop);


    void add_car(const Car& _car) override;     //add car to cars_for_sale
		void remove_car(const Car& _car) override;  //remove car from cars_for_sale 
};

#endif