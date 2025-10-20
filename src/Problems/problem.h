#ifndef __PROBLEMS_H__
#define __PROBLEMS_H__

#include <iostream>
using namespace std;

typedef enum{
  INTERIOR,
  TYRE,
  ENGINE
} Problem_code_t;

class Problem{
  
  protected:
    const Problem_code_t problem_code;

  public:
    Problem();
    Problem(const Problem_code_t& _c);
    virtual ~Problem();
};

#endif