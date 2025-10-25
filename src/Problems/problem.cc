#include "problem.h"
#include <iostream>
using namespace std;

Problem::Problem(): Problem(ENGINE){
}

Problem::Problem(const Problem_code_t& _c): problem_code(_c){
}

Problem::~Problem(){
}