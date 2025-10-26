#include "concessionaria.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){

  string name;

  if(argc == 1) {
    name = "My Concessioanria";
  } else {
    name = argv[1];
  }

  Concessionaria c(name);

  c.init_datas();

  c.run_menu();

  return 0;
}