#ifndef __RENTAL_H__
#define __RENTAL_H__

#include "Department.h"
#include "../Staff/rental_employee.h"
#include "../Customer/customer.h"
#include <iostream>
#include <set>
#include <utility>
#include <ctime>
using namespace std;

class Rental: public Department{

  static int                      count_rentals;
  int                             ID_rental;
  multiset<pair<Customer*, Date>> rentals_open;
  int                             rate = 10.0;

  int diff_in_days(const Date& _start, const Date& _today) const; //calculate diff now start rental

  public:
    Rental();
    Rental(const Rental& _ren);
    ~Rental() override;

    friend ostream& operator <<(ostream& os, const Rental& _ren);

    void   add_car           (Car* _car)               override;  //add car to cars
		void   remove_car        (Car* _car)               override;  //remove car from cars
    void   add_employee      (Employee* _empl)         override;  //add employee to employees
    void   remove_employee   (Employee* _empl)         override;  //remove employee from employees
    Car*   find_car_by_ID    (const int& _id)          override;  //find the _car in cars by id
    Car*   find_car_by_model (const string& _m)        override;  //find the _car in cars by model
    void   register_rental   (Customer* _c);                      //add Date to rentals_open
    void   register_return   (Customer* _c, Date _d);             //remove Date from rentals_open
    int    get_rate          () const;                            
    int    calculate_rental  (Customer* _c, const Date& _d);      //calculate how much a customer have to pay
};

ostream& operator <<(ostream& os, const Rental& _ren);

#endif