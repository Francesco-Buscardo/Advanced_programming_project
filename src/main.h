#ifndef MAIN_H 
#define MAIN_H

#include "car.h"
#include "extConcessionaria/laboratory.h"
#include "extConcessionaria/rental.h"
#include "extConcessionaria/shop.h"
#include "./staff/mechanic.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

istream& operator >>(istream& is, Power_supply& _ps);
ostream& operator <<(ostream& os, const Laboratory& _lab);
ostream& operator <<(ostream& os, const Mechanic& _mech);
ostream& operator <<(ostream& os, const Rental& _ren);

vector<Car>        init_cars();
vector<Laboratory> init_labs(const vector<Car>& _car);
vector<Shop>       init_shops();
vector<Rental>     init_rentals();

#endif