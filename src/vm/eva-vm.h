
#ifndef EvaVirtualMachine_h
#define EvaVirtualMachine_h
#include "../beytecode/operation-code.h"
#include "../logger.h"
#include <iostream>
#include <string>
#include <vector>

#define read_byte() *ip++

// Eva Virtual Machine
class EvaVirtualMachine {
public:
  EvaVirtualMachine() {}

  void exec(const std::string &program) {
    //
    code = {1};
    ip = &code[0];
    return eval();
  }

  void eval() {
    for (;;) {
      auto operationCode = read_byte();
      switch (operationCode) {
      case OPERATION_HALT:
        return;
      default:
        DIE << "Unknown operation code: " << std::hex << operationCode;
      }
    }
  }

  //  Instruction pointer (aka program counter)
  u_int8_t *ip;
  std::vector<u_int8_t> code;
};

#endif