#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(){

}

Date::Date(int _d, int _m, int _y) : dd(_d), mm(_m), yyyy(_y){
  cout << "Date create " << _d << "." << _m << "." << _y << endl;
} 

Date::~Date(){ 
  cout << "Delete Date " << dd << "." << mm << "." << yyyy << endl;
}
