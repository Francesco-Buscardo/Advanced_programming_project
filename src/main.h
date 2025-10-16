#ifndef MAIN_H 
#define MAIN_H

#include "car.h"
#include "Concessionaria/Concessionaria.h"
#include "Concessionaria/laboratory.h"
#include "Concessionaria/rental.h"
#include "Concessionaria/shop.h"
#include "Staff/mechanic.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

istream& operator >>(istream& is, Power_supply& _ps);
ostream& operator <<(ostream& os, const Laboratory& _lab);
ostream& operator <<(ostream& os, const Mechanic& _mech);
ostream& operator <<(ostream& os, const Rental& _ren);
ostream& operator <<(ostream& os, const Shop& _shop);

vector<Car>        init_cars();
vector<Laboratory> init_labs(const vector<Car>& _car);
vector<Shop>       init_shops();
vector<Rental>     init_rentals();

#endif