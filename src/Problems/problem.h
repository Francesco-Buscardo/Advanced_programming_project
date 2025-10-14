#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <iostream>
using namespace std;

class Problem{
  protected:
    const int problem_code;

  public:
    Problem(int _c);
    virtual ~Problem() = default;
    virtual bool delete_problem() = 0;
};

#endif