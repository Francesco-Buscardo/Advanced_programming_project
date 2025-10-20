#include "shop.h"
#include <iostream>
using namespace std;

int Shop::count_shops = 0;

Shop::Shop(): Department(), ID_shop(++count_shops){
}

Shop::Shop(const Shop& _shop): Department(_shop), ID_shop(_shop.ID_shop){
}

Shop::~Shop(){
} 

bool Shop::add_car(const Car& _car){

  auto it = cars_for_sale.find(_car);

  if(it == cars_for_sale.end()) {
    cars_for_sale.insert(_car);
  } else {
    cout << "Already in!" << endl;
  }
}

bool Shop::remove_car(const Car& _car){
  auto it = cars_for_sale.find(_car);

  if(it != cars_for_sale.end()) {
    cars_for_sale.erase(_car);
  } else {
    cout << "Car Already sold!" << endl;
  }
} 

bool add_employee(const Employee& _empl){}

bool remove_employee(const Employee& _empl){}

Car  find_car(const Car& _car){}       

void sell_to(const Car& _car, const Customer& _c){}