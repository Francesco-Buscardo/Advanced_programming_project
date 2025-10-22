#ifndef __MAIN_H__ 
#define __MAIN_H__

#include "car.h"
#include "Departments/laboratory.h"
#include "Departments/rental.h"
#include "Departments/shop.h"
#include "Staff/mechanic.h"
#include "Staff/rental_employee.h"
#include "Staff/shop_employee.h"
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

template<typename T>
Car* find_by_id            (T& _x);
template<typename T>
Car* find_by_model         (T& _x);
template<typename T>
void find_car              (T& _x);
template<typename T>
void add_car               (T& _x);
template<typename T>       
void remove_car            (T& _x);
void sell_to               (Shop& _shop);
template<typename T, typename K>
void add_employee          (T& _x);
template<typename T, typename K>
void remove_employee       (T& _x);
void fix_car               (Laboratory& _lab);
void management_shop       (Shop& _shop);
void management_laboratory (Laboratory& _lab);
void management_rental     (Rental& _rental);

#endif