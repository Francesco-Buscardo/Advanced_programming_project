#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
  int dd;
  int mm; 
  int yyyy;

  public:
    Date();
    Date(int _d, int _m, int _y);
    ~Date();
};

#endif