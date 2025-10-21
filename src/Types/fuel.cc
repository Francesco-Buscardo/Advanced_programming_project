#include "fuel.h"
#include <iostream>
using namespace std;

Fuel::Fuel(): fuel(GASOLINE){ 
}

Fuel::Fuel(const Fuel_t& _f): fuel(_f){
}

// istream& operator >>(istream& is, Fuel& _fl){

// 	string _str;
// 	is >> _str;

// 	if(_str.compare("GASOLINE")) {
// 		Car = GASOLINE;
// 	} else if(_str.compare("HYBRID")) {
// 		_fl->fuel = HYBRID;
// 	} else if(_str.compare("DIESEL")) {
// 		_fl-> = DIESEL;
// 	} else {
// 		_fl-> = GPL;
// 	}

// 	return is;
// }

ostream& operator <<(ostream& os, const Fuel& _fl) {
  
  switch (_fl.fuel) {
    case GASOLINE: os << "Gasoline"; 
                  break;
    case DIESEL: os << "Diesel"; 
                break;
    case GPL: os << "Electric"; 
                  break;
    case HYBRID: os << "Hybrid"; 
                break;
    default: os << "Nothing"; 
            break;
  }

  return os;
}