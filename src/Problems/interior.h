#ifndef  INTERIOR_H 
#define  INTERIOR_H

#include "problem.h"
#include <iostream>
using namespace std;

class Interior: public Problem{
  public:
    Interior(); 
    ~Interior() override = default;

    bool delete_problem() override;
};

#endif