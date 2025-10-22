#ifndef __CONCESSIONARIA_H__
#define __CONCESSIONARIA_H__

#include "Departments/shop.h"
#include "Departments/laboratory.h"
#include "Departments/rental.h"
#include <string>
#include <set>
using namespace std;

class Concessionaria{

  string          name_concessionaria;
  set<Shop>       shops;
  set<Laboratory> labs;
  set<Rental>     rentals;

  public:
    Concessionaria(); 
    Concessionaria(const string& _n);
    Concessionaria(const Concessionaria& _c); 
    ~Concessionaria() = default;
     
    bool        add_shop          (const Shop& _x);
    bool        add_laboratory    (const Laboratory& _x);
    bool        add_rental        (const Rental& _x);
    bool        remove_shop       (const Shop& _x);
    bool        remove_laboratory (const Laboratory& _x);
    bool        remove_rental     (const Rental& _x);
    Shop&       get_shop          () const;
    Laboratory& get_laboratory    () const;
    Rental&     get_rental        () const;
};

#endif