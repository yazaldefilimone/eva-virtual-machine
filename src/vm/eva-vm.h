
#ifndef EvaVirtualMachine_h
#define EvaVirtualMachine_h
#include "../beytecode/operational-code.h"
#include "../logger.h"
#include "../value.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>

#define read_byte() *instruction_pointer++

#define STACK_LIMIT 556;
// Eva Virtual Machine
class EvaVirtualMachine {
public:
  EvaVirtualMachine() {}

  void exec(const std::string &program) {
    //
    constants.push_back(NUMBER(42));
    code = {OPERATIONAL_CONST, 0, OPERATIONAL_HALT};
    instruction_pointer = &code[0];
    return eval();
  }

  void push(const EvaValue *value) {
    if (((size_t)(&stack_pointer - stack.begin())) == 500) {
      DIE << "Stack overflow";
    }
    *stack_pointer = value;
    stack_pointer++;
  }

  void eval() {
    for (;;) {
      auto operationCode = read_byte();
      switch (operationCode) {
      case OPERATIONAL_HALT:
        return;
      case OPERATIONAL_CONST: {
        auto constantIndex = read_byte();
        auto constant = constants[constantIndex];
        push(constant);
      }
      default:
        DIE << "Unknown operation code: " << std::hex << operationCode;
      }
    }
  }

  // STACK
  std::array<EvaValue, 500> stack;
  //  Instruction pointer (aka program counter)
  u_int8_t *instruction_pointer;
  // Stack pointer
  u_int8_t *stack_pointer;
  std::vector<EvaValue> constants;
  std::vector<u_int8_t> code;
};

#endif