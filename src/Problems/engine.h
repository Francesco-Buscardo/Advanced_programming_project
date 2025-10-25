#ifndef  __ENGINE_H__ 
#define  __ENGINE_H__

#include "problem.h"
#include <iostream>
using namespace std;

class Engine: public Problem{

  public:
    Engine();
    Engine(const Problem_code_t& _c); 
    ~Engine() = default;
};

#endif