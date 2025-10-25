#include "shop.h"
#include <iostream>
using namespace std;

int Shop::count_shops = 0;

Shop::Shop(): Department(), ID_shop(++count_shops){
}

Shop::Shop(const Shop& _shop): Department(_shop), ID_shop(_shop.ID_shop){
}

Shop::~Shop(){

  for(auto s: sales) {
    delete s.first;
    delete s.second;
  }
  sales.clear();
} 

ostream& Shop::print_operator(ostream& os) const{

	os << "-------------------------------------------" << endl
     << "Shop " << "ID: " << this->ID_shop << endl
     << "-------------------------------------------" << endl;
	for(auto* it: this->cars) {
		os << *it << endl;
	}
  for(auto* it: this->employees) {
		os << *it << endl;
	}
  for(auto* it: this->customers) {
		os << *it << endl;
	}
	for(auto it: this->sales) {
		os << "Car: " << it.first
			 << ", Customer: " << it.second << endl;
	}

	return os;
} 

ostream& operator <<(ostream& os, const Shop& _shop){

  return _shop.print_operator(os);
}

void Shop::sell_to(Car* _car, Customer* _c){

  sales.push_back({_car, _c});

  remove_car(_car);
}

int Shop::get_ID() const{

  return ID_shop;
}