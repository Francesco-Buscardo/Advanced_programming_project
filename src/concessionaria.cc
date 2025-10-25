#include "concessionaria.h"
#include <string>
#include <set>
using namespace std;

Concessionaria::Concessionaria(): name_concessionaria(""), shops(), labs(), rentals(){
}

Concessionaria::Concessionaria(const string& _n): name_concessionaria(_n), shops(), labs(), rentals(){
}

Concessionaria::Concessionaria(const Concessionaria& _c): name_concessionaria(_c.name_concessionaria), shops(_c.shops), labs(_c.labs), rentals(_c.rentals){
}

Concessionaria::~Concessionaria(){
  
  for(auto r : rentals) {
    delete r;
  }
  rentals.clear();
  for(auto s : shops) {
    delete s;
  }
  shops.clear();
  for(auto l : labs) {
    delete l;
  }
  labs.clear();
}

void Concessionaria::add_shop(Shop* _x){

  auto it = shops.find(_x);

  if(it != shops.end()) {
    shops.insert(*it);
  } else {
    cout << "Already in!" << endl;
  }
}

void Concessionaria::add_laboratory(Laboratory* _x){
  
  auto it = labs.find(_x);

  if(it != labs.end()) {
    labs.insert(*it);
  } else {
    cout << "Already in!" << endl;
  }
}

void Concessionaria::add_rental(Rental* _x){

  auto it = rentals.find(_x);

  if(it != rentals.end()) {
    rentals.insert(*it);
  } else {
    cout << "Already in!" << endl;
  }
}

void Concessionaria::remove_shop(Shop* _x){

  auto it = shops.find(_x);

  if(it != shops.end()) {
    delete *it;
    shops.erase(it);
  } else {
    cout << "Already out!" << endl;
  }
}

void Concessionaria::remove_laboratory(Laboratory* _x){

  auto it = labs.find(_x);

  if(it != labs.end()) {
    delete *it;
    labs.erase(it);
  } else {
    cout << "Already out!" << endl;
  }
}

void Concessionaria::remove_rental(Rental* _x){

  auto it = rentals.find(_x);

  if(it != rentals.end()) {
    delete *it;
    rentals.erase(it);
  } else {
    cout << "Already out!" << endl;
  }
}

Shop* Concessionaria::get_shop(const int& _id) const{

  for(auto s : shops){
    if(s->get_ID() == _id) {
      return s;
    }
  }

  return nullptr;
}

Laboratory* Concessionaria::get_laboratory(const int& _id) const{

  for(auto l : labs){
    if(l->get_ID() == _id) {
      return l;
    }
  }

  return nullptr;
}

Rental* Concessionaria::get_rental(const int& _id) const{

  for(auto r : rentals){
    if(r->get_ID() == _id) {
      return r;
    }
  }

  return nullptr;
}