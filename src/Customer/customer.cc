#include "customer.h"
#include <string>
#include <set>
using namespace std;

Customer::Customer(): ID_customer(-1), name_customer(""), lastname_customer(""), age_customer(0), rental_cars(), bought_cars(){
}

Customer::Customer(const string& _n, const string& _l, const int& _a): ID_customer(++count_customer), name_customer(_n), lastname_customer(_l), age_customer(_a), rental_cars(), bought_cars(){
}

Customer::Customer(const Customer& _c): ID_customer(_c.ID_customer), name_customer(_c.name_customer), lastname_customer(_c.lastname_customer), age_customer(_c.age_customer), rental_cars(_c.rental_cars), bought_cars(_c.bought_cars){
}

bool rent_car(const Car& _car){

}

bool return_car(const Car& _car){

}

bool buy_car(const Car& _car){

}

bool sell_car(const Car& _car){

}
