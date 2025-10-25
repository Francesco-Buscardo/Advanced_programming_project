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

class Car;

class Rental: public Department{

  static int                       count_rentals;
  int                              ID_rental;
  int                              rate = 10.0;
  multiset<pair<Customer*, Date*>> rentals_open;

  int diff_in_days(const Date& _start, const Date& _today) const; //calculate diff now start rental

  public:
    Rental();
    Rental(const Rental& _ren);
    ~Rental() override;

    virtual ostream& print_operator (ostream& os) const;
    friend  ostream& operator <<    (ostream& os, const Rental& _ren);

    void   register_rental   (Customer* _c, Date* _d);                                 //add Date to rentals_open
    void   register_return   (Customer* _c, Date* _d);                       //remove Date from rentals_open
    int    get_rate          () const;                                  
    int    calculate_rental  (Customer* _c, Date* _d);                       //calculate how much a customer have to pay
    int    get_ID            ()                             const override;
};

ostream& operator <<(ostream& os, const Rental& _ren);

#endif