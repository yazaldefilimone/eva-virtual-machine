#include "./vm/eva-vm.h"

int main(int argc, char const *argv[]) {
  EvaVirtualMachine vm;
  vm.exec(R"(45)");

  return 0;
}
