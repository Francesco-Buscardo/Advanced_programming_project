#ifndef  ENGINE_H 
#define  ENGINE_H

#include "problem.h"
#include <iostream>
using namespace std;

class Engine: public Problem{
  public:
    Engine(); 
    ~Engine() override = default;

    bool delete_problem() override;
};

#endif