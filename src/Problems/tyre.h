#ifndef  TYRE_H 
#define  TYRE_H

#include "problem.h"
#include <iostream>
using namespace std;

class Tyre: public Problem{

  public:
    Tyre();
    ~Tyre() override = default;

    bool delete_problem() override;
};

#endif