#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : dd(0), mm(0), yyyy(0){
  //cout << "Default Date create " << dd << "." << mm << "." << yyyy << endl;
}

Date::Date(int _d, int _m, int _y) : dd(_d), mm(_m), yyyy(_y){
  //cout << "Date create " << _d << "." << _m << "." << _y << endl;
} 

Date::~Date(){ 
  //cout << "Delete Date " << dd << "." << mm << "." << yyyy << endl;
}

ostream& operator <<(ostream& os, const Date& _date) {
  os << _date.dd << "." << _date.mm << "." << _date.yyyy;
  return os;
}
