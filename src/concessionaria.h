#ifndef __CONCESSIONARIA_H__
#define __CONCESSIONARIA_H__

#include "Departments/Department.h"
#include "Departments/shop.h"
#include "Departments/laboratory.h"
#include "Departments/rental.h"
#include <string>
#include <set>
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
     
    void        add_shop          (Shop* _x);
    void        add_laboratory    (Laboratory* _x);
    void        add_rental        (Rental* _x);
    void        remove_shop       (Shop* _x);
    void        remove_laboratory (Laboratory* _x);
    void        remove_rental     (Rental* _x);

    Shop*       get_shop          (const int& _id) const;
    Laboratory* get_laboratory    (const int& _id) const;
    Rental*     get_rental        (const int& _id) const;
    
};

#endif