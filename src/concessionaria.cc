#include "concessionaria.h"
#include <string>
#include <set>
using namespace std;

Concessionaria::Concessionaria(): name_concessionaria(""), shops(), labs(), rentals(){
}

Concessionaria::Concessionaria(const string& _n): name_concessionaria(_n), shops(), labs(), rentals(){
}

Concessionaria::Concessionaria(const Concessionaria& _c): name_concessionaria(_c.name_concessionaria), shops(_c.shops), labs(_c.labs), rentals(_c.rentals){
}

bool add_shop(const Shop& _x){

}

bool add_laboratory(const Laboratory& _x){

} 

bool add_rental(const Rental& _x){

}

bool remove_shop(const Shop& _x){

}

bool remove_laboratory(const Laboratory& _x){

}

bool remove_rental(const Rental& _x){

}