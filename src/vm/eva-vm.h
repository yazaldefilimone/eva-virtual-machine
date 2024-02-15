
#ifndef EvaVirtualMachine_h
#define EvaVirtualMachine_h
#include "../beytecode/operation-code.h"
#include <string>
#include <vector>

#define read_byte() *ip++

// Eva Virtual Machine
class EvaVirtualMachine {
public:
  EvaVirtualMachine() {}

  void exec(const std::string &program) {
    //
    code = {OPERATION_HALT};
    ip = &code[0];
    return eval();
  }

  void eval() {
    for (;;) {
      switch (read_byte()) {
      case OPERATION_HALT:
        return;
      }
    }
  }

  //  Instruction pointer (aka program counter)
  u_int8_t *ip;

  std::vector<u_int8_t> code;
};

#endif