#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "../car.h"
#include <string>
#include <set>
using namespace std;

class Customer{

  static int count_customer;
  int        ID_customer;
  string     name_customer;
  string     lastname_customer;
  int        age_customer;
  set<Car>   rental_cars;
  set<Car>   bought_cars;

  public:
    Customer();
    Customer(const string& _n, const string& _l, const int& _a);
    Customer(const Customer& _c);
    ~Customer() = default;

    bool rent_car   (const Car& _car); //add _car to rental_car
    bool return_car (const Car& _car); //remove _car from rental_car
    bool buy_car    (const Car& _car); //add _car to bought_cars
    bool sell_car   (const Car& _car); //remove _car from bought_cars
};

#endif