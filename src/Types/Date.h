#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>
using namespace std;

class Date {

  const int dd;
  const int mm; 
  const int yyyy;

  public:
    Date();
    Date(const int& _d, const int& _m, const int& _y);
    ~Date();

    friend ostream& operator <<(ostream& os, const Date& _date);
};

ostream& operator <<(ostream& os, const Date& _date);

#endif