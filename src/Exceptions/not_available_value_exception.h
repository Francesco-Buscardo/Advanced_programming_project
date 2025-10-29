#ifndef __NOT_AVAILABLE_VALUE_EXCEPTION__
#define __NOT_AVAILABLE_VALUE_EXCEPTION__

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Not_Available_Value_Exception: public exception{

  private:
    string msg;

  public:
    explicit Not_Available_Value_Exception(const string& _msg);
    const char* what() const noexcept override;
};

#endif