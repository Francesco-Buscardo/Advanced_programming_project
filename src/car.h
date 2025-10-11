#ifndef CAR_H
#define CAR_H

#include "./Types/Date.h"
#include "./Types/Power_supply.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car{
  const string ID_car;
  long double price_car;
  const Date production_year_car;
  const Power_supply power_supply_car;
  const string color_car;
  const vector<int> size_car; //u: mm
  const string model_car;

  public:
    Car();                //default
    Car(string _id, long double _price, Date _date, Power_supply _ps, string _color, vector<int> _size, string _model);  //params
    Car(const Car& _car); //copy
    ~Car();               //dist

    //operator << per date - ps - car
    friend ostream& operator <<(ostream& os, const Power_supply& _ps);
    friend ostream& operator <<(ostream& os, const vector<int>& _size); 
    friend ostream& operator <<(ostream& os, const Car& _car);
};

#endif
