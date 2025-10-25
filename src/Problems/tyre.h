#ifndef  __TYRE_H__ 
#define  __TYRE_H__

#include "problem.h"
#include <iostream>
using namespace std;

class Tyre: public Problem{

  public:
    Tyre();
    Tyre(const Problem_code_t& _c);
    ~Tyre() = default;
};

#endif