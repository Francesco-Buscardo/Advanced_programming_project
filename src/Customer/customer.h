#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "../car.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car;

class Customer{

  static int    count_customer;
  int           ID_customer;
  string        name_customer;
  string        lastname_customer;
  int           age_customer;
  vector<Car*>  rental_cars;
  vector<Car*>  bought_cars;

  public:
    Customer();
    Customer(const string& _n, const string& _l, const int& _a);
    Customer(const Customer& _c);
    ~Customer();

    friend ostream& operator <<(ostream& os, const Customer& _c);
    bool            operator < (const Customer* _car) const;
    bool            operator ==(const Customer& _c)   const;


    void rent_car   (Car* _car); //add _car to rental_car
    void return_car (Car* _car); //remove _car from rental_car
    void buy_car    (Car* _car); //add _car to bought_cars
    void sell_car   (Car* _car); //remove _car from bought_cars
    int  get_ID     () const;
};

ostream& operator <<(ostream& os, const Customer& _c);

#endif