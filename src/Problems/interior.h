#ifndef  __INTERIOR_H__ 
#define  __INTERIOR_H__

#include "problem.h"
#include <iostream>
using namespace std;

class Interior: public Problem{

  public:
    Interior(); 
    Interior(const Problem_code_t& _c);
    ~Interior() override = default;
};

#endif