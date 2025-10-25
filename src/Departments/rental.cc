#include "rental.h"
#include <iostream>
#include <set>
#include <utility>
#include <ctime>
using namespace std;

int Rental::count_rentals = 0;

Rental::Rental(): Department(), ID_rental(++count_rentals), rentals_open(){
}

Rental::Rental(const Rental& _ren): Department(_ren), ID_rental(_ren.ID_rental){

  for(auto& r : _ren.rentals_open) {
    rentals_open.insert(new Triple(*r->get_customer(), *r->get_date(),*r->get_car()));
  }
}

Rental::~Rental(){

  for(auto r : rentals_open) {
    delete r->get_customer(); 
    delete r->get_date();
    delete r->get_car(); 
  }
  rentals_open.clear();
}

ostream& Rental::print_operator(ostream& os) const{

	os << "-------------------------------------------" << endl
     << "Shop " << "ID: " << this->ID_rental << endl
     << "-------------------------------------------" << endl;
	for(auto* it: this->cars) {
		os << *it << endl;
	}
  for(auto* it: this->employees) {
		os << *it << endl;
	}
  for(auto* it: this->customers) {
		os << *it << endl;
	}
	for(auto it: this->rentals_open) {
		os << "Customer: " << it->get_customer()
			 << ", Date: "   << it->get_date() 
       << ", Car: "    << it->get_car() << endl;
	}

	return os;
} 

ostream& operator <<(ostream& os, const Rental& _r){

  return _r.print_operator(os);
}

void Rental::register_rental(Customer* _c, Date* _d, Car* _car){

  cout << "Rental registered!" << endl;
  
  rentals_open.insert(new Triple(*_c, *_d, *_car)); 

  remove_car(_car);
}

void Rental::register_return(Customer* _c, Date* _d, Car* _car){

  for(auto it = rentals_open.begin(); it != rentals_open.end(); ++it) {
    if(((*it)->get_customer() == _c) && ((*it)->get_date() == _d) && ((*it)->get_car() == _car)) {
      rentals_open.erase(it);
      add_car(new Car(*(*it)->get_car()));

      delete _c; 
      delete _d;
      delete _car;
    }
  }
}

int Rental::get_rate() const{

  return this->rate;
}                            

int Rental::diff_in_days(const Date& _start, const Date& _today) const {
  
  tm a = {};
  a.tm_mday = _start.get_day();
  a.tm_mon  = _start.get_month() - 1;
  a.tm_year = _start.get_year() - 1900;

  tm b = {};
  b.tm_mday = _today.get_day();
  b.tm_mon  = _today.get_month() - 1;
  b.tm_year = _today.get_year() - 1900;

  time_t aa = mktime(&a);
  time_t bb = mktime(&b);

  return static_cast<int>(difftime(bb, aa) / (60 * 60 * 24));
}

int Rental::calculate_rental(Customer* _c, Date* _d, Car* _car){

  auto it = rentals_open.begin();
  while(it != rentals_open.end()) {
    if(((*it)->get_customer() == _c) && ((*it)->get_date() == _d) && ((*it)->get_car() == _car)) {
      break; 
    }
    ++it;
  }

  if(it == rentals_open.end()) {
    return 0;
  } else {
    Date start_rental = *(*it)->get_date();
    int  days         = diff_in_days(start_rental, *_d);
    int  hours        = days * 24;

    return hours * rate;
  }
}

int Rental::get_ID() const{

  return ID_rental;
}
