#ifndef __RENTAL_H__
#define __RENTAL_H__

#include "Department.h"
#include "../Staff/rental_employee.h"
#include <iostream>
#include <set>
#include <utility>
using namespace std;

class Rental: public Department{

  static int                count_rentals;
  int                       ID_rental;
  set<pair<Customer, Date>> rentals_open;

  public:
    Rental();
    Rental(const Rental& _ren);
    ~Rental() override;

    friend ostream& operator <<(ostream& os, const Rental& _ren);

    bool add_car          (const Car& _car)       override;  //add car to rental_cars
		bool remove_car       (const Car& _car)       override;  //remove car from rental_cars
    bool add_employee     (const Employee& _empl) override;  //add employee to employees
    bool remove_employee  (const Employee& _empl) override;  //remove employee from employees
		Car  find_car         (const Car& _car)       override;  //find a car in cars
    bool register_rental  (const Customer& _c);              //add Date to rentals_open
    bool register_return  (const Customer& _c);              //remove Date from rentals_open
    int  calculate_rental (const Customer& _c);              //calculate how much a customer have to pay
};

#endif