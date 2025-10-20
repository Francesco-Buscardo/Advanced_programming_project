#ifndef MAIN_H 
#define MAIN_H

#include "car.h"
#include "Departments/laboratory.h"
#include "Departments/rental.h"
#include "Departments/shop.h"
#include "Staff/mechanic.h"
#include "Types/fuel.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

istream& operator >>(istream& is, Fuel& _fl);
ostream& operator <<(ostream& os, const Laboratory& _lab);
ostream& operator <<(ostream& os, const Mechanic& _mech);
ostream& operator <<(ostream& os, const Rental& _ren);
ostream& operator <<(ostream& os, const Shop& _shop);

// vector<Car>        init_cars();
// vector<Laboratory> init_labs(const vector<Car>& _car);
vector<Laboratory> init_labs();
vector<Shop>       init_shops();
vector<Rental>     init_rentals();

void management_shop();
void management_laboratory();
void management_rental();

#endif