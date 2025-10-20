#ifndef __FUEL_H__
#define __FUEL_H__

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
};

#endif