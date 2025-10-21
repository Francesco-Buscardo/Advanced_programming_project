#ifndef __MAIN_H__ 
#define __MAIN_H__

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

// vector<Car>        init_cars();
// vector<Laboratory> init_labs(const vector<Car>& _car);
// vector<Laboratory> init_labs();
// vector<Shop>       init_shops();
// vector<Rental>     init_rentals();

void management_shop       (Shop& _shop);
void management_laboratory (Laboratory& _lab);
void management_rental     (Rental& _rental);

#endif