#ifndef __CAR_H__
#define __CAR_H__

#include "./Types/Date.h"
#include "./Types/fuel.h"
#include "Problems/problem.h"
#include "./Departments/laboratory.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car{

  static int       count_cars; 
  const int        ID_car;  
  const Fuel       fuel_car;       
  long double      price_car;
  const string     model_car;
  vector<Problem*> problems_car;

  public:
    Car();               
    Car(const Fuel _fl, const long double _prc, const string _mdl);
    Car(const Car& _car); 
    ~Car() = default;               

    //operator << per date - fl - car
    friend ostream& operator << (ostream& os, const Fuel& _fl);
    friend ostream& operator << (ostream& os, const Car& _car);
  	bool            operator <  (const Car* _car) const;
    friend bool     operator == (const Car& _sx, const Car& _dx);

    void               add_problem      (Problem* _p);
    void               remove_problem   ();
    vector<Problem*>&  get_problems_car ();
    int                get_ID           ();
    string             get_model        ();
};

ostream& operator << (ostream& os, const Fuel& _fl);
ostream& operator << (ostream& os, const Car& _car);
bool     operator == (const Car& _sx, const Car& _dx);


#endif
