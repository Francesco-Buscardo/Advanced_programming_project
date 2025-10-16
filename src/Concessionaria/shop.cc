#include "shop.h"
#include <iostream>
#include <string>
using namespace std;

Shop::Shop(string _id): Concessionaria(), ID_shop(_id), cars_for_sale(){
}

Shop::Shop(const Shop& _shop): Concessionaria(_shop), ID_shop(_shop.ID_shop), cars_for_sale(_shop.cars_for_sale){
}

Shop::~Shop(){
} 

void Shop::add_car(const Car& _car){

  auto it = cars_for_sale.find(_car);

  if(it == cars_for_sale.end()) {
    cars_for_sale.insert(_car);
  } else {
    cout << "Already in!" << endl;
  }
}

void Shop::remove_car(const Car& _car){
  auto it = cars_for_sale.find(_car);

  if(it != cars_for_sale.end()) {
    cars_for_sale.erase(_car);
  } else {
    cout << "Car Already sold!" << endl;
  }
} 