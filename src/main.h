#ifndef MAIN_H 
#define MAIN_H

#include "car.h"
#include "extConcessionaria/laboratory.h"
#include "extConcessionaria/rental.h"
#include "extConcessionaria/shop.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

istream& operator >>(istream& is, Power_supply& _ps);
vector<Car>&        init_cars();
vector<Laboratory>& init_labs();
vector<Shop>&       init_shops();
vector<Rental>&     init_rentals();

#endif