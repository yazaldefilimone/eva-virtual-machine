#include "./vm/eva-vm.h"

#include <iostream>

int main(int argc, char const *argv[]) {
  EvaVirtualMachine vm;
  vm.exec(R"(45)");

  std::cout << "All done!" << std::endl;
  return 0;
}
