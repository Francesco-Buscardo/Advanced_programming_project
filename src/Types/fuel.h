#ifndef __FUEL_H__
#define __FUEL_H__

#include <iostream>
using namespace std;

typedef enum{
  GASOLINE,
  HYBRID,
  DIESEL,
  GPL
} Fuel_t;

class Fuel{

  const Fuel_t fuel;

  public:
    Fuel();
    Fuel(const Fuel_t& _f);
    ~Fuel() = default;

    friend istream& operator >>(istream& is, Fuel& _fl);
    friend ostream& operator <<(ostream& os, const Fuel& _fl);
};

istream& operator >>(istream& is, Fuel& _fl);
ostream& operator <<(ostream& os, const Fuel& _fl);


#endif