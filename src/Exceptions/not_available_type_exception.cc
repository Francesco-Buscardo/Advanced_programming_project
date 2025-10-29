#include "not_available_type_exception.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

Not_Available_Type_Exception::Not_Available_Type_Exception(const string& _msg): msg(_msg){
}

const char* Not_Available_Type_Exception::what() const noexcept{
  
  return msg.c_str();
}

