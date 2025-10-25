#include "Triple.h"
#include <iostream>
using namespace std;

Triple::Triple(){
  t.c  = new Customer();
  t.d  = new Date();
  t.cr = new Car();
}

Triple::Triple(const Customer& _c, const Date& _d, const Car& _cr){
  t.c  = new Customer(_c);
  t.d  = new Date(_d);
  t.cr = new Car(_cr);
} 

Triple::Triple(const Triple& _t){
  t.c  = new Customer(*_t.t.c);
  t.d  = new Date(*_t.t.d);
  t.cr = new Car(*_t.t.cr);
}

Triple::~Triple(){
  delete t.c;
  delete t.d;
  delete t.cr;
}

Customer* Triple::get_customer() const{

  return t.c;
}

Date* Triple::get_date() const{

  return t.d;
}

Car* Triple::get_car() const{

  return t.cr;
}