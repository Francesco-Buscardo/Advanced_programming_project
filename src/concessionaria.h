#ifndef __CONCESSIONARIA_H__
#define __CONCESSIONARIA_H__

#include "concessionaria.h"
#include "car.h"
#include "Departments/Department.h"
#include "Departments/laboratory.h"
#include "Departments/rental.h"
#include "Departments/shop.h"
#include "Staff/mechanic.h"
#include "Staff/rental_employee.h"
#include "Staff/shop_employee.h"
#include "Types/fuel.h"
#include "Types/Date.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <ctime>
using namespace std;

class Concessionaria{

  string           name_concessionaria;
  set<Shop*>       shops;
  set<Laboratory*> labs;
  set<Rental*>     rentals;

  public:
    Concessionaria(); 
    Concessionaria(const string& _n);
    Concessionaria(const Concessionaria& _c); 
    virtual ~Concessionaria();
     
    void        add_shop              (Shop* _x);
    void        add_laboratory        (Laboratory* _x);
    void        add_rental            (Rental* _x);
    void        remove_shop           (Shop* _x);
    void        remove_laboratory     (Laboratory* _x);
    void        remove_rental         (Rental* _x);

    Shop*       get_shop              (const int& _id) const;
    Laboratory* get_laboratory        (const int& _id) const;
    Rental*     get_rental            (const int& _id) const;

    template<typename T>
    Car*        find_by_id            (T& _x);
    template<typename T>
    Car*        find_by_model         (T& _x);
    template<typename T>
    void        find_car              (T& _x);
    template<typename T>
    void        add_car               (T& _x);
    template<typename T>       
    void        remove_car            (T& _x);
    void        sell_to               (Shop& _shop);
    template<typename T, typename K>
    void        add_employee          (T& _x);
    template<typename T, typename K>
    void        remove_employee       (T& _x);
    void        fix_car               (Laboratory& _lab);
    void        register_rental       (Rental& _rental);
    void        register_return       (Rental& _rental);
    void        calculate_return      (Rental& _rental);

    void        management_shop       (Shop& _shop);
    void        management_laboratory (Laboratory& _lab);
    void        management_rental     (Rental& _rental);
    
    void        init_datas            ();
    void        run_menu              ();
};

#endif