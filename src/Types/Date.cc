#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : dd(0), mm(0), yyyy(0){
}

Date::Date(const int& _d, const int& _m, const int& _y) : dd(_d), mm(_m), yyyy(_y){
} 

ostream& operator <<(ostream& os, const Date& _date){
  
  os << _date.dd << "." << _date.mm << "." << _date.yyyy;
  return os;
}

bool Date::operator ==(const Date& _c) const{

  return this->dd == _c.get_day() && this->mm == _c.get_month() && this->yyyy == _c.get_year();
}


int Date::get_day() const{

  return this->dd; 
}

int Date::get_month() const{

  return this->mm; 
}

int Date::get_year() const{

  return this->yyyy;
}
