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

  for(auto r : _ren.rentals_open) {
    rentals_open.insert(make_pair(new Customer(*r.first), new Date(*r.second)));
  }
}

Rental::~Rental(){

  for(auto r : rentals_open) {
    delete r.first; 
    delete r.second; 
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
		os << "Customer: " << it.first
			 << ", Date: "   << it.second << endl;
	}

	return os;
} 

ostream& operator <<(ostream& os, const Rental& _ren){

  return _ren.print_operator(os);
}

void Rental::register_rental(Customer* _c, Date* _d){

  cout << "Rental registered!" << endl; 
  
  rentals_open.insert({_c, _d}); 
}

void Rental::register_return(Customer* _c, Date* _d){

  if(rentals_open.find({_c, _d}) != rentals_open.end()) {
    rentals_open.erase({_c, _d});
    delete _c;
    delete _d;
  } else {
    cout << "Return already registered!" << endl;
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


int Rental::calculate_rental(Customer* _c, Date* _d){

  auto it = rentals_open.begin();
  while(it != rentals_open.end()) {
    if(it->first == _c) {
      break; 
    }
    ++it;
  }

  if(it == rentals_open.end()) {
    return 0;
  } else {
    Date start_rental = *it->second;
    int  days         = diff_in_days(start_rental, *_d);
    int  hours        = days * 24;

    return hours * rate;
  }
}

int Rental::get_ID() const{

  return ID_rental;
}
