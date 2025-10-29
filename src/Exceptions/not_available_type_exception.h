#ifndef __NOT_AVAILABLE_TYPE_EXCEPTION__
#define __NOT_AVAILABLE_TYPE_EXCEPTION__

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Not_Available_Type_Exception: public exception{

  private:
    string msg;

  public:
    Not_Available_Type_Exception(const string& _msg);
    const char* what() const noexcept override;
};

#endif