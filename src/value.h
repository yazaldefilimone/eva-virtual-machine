#ifndef Value_h
#define Value_h

enum class EvaValueType { NUMBER };

struct EvaValue {
  EvaValueType type;
  union {
    double number;
  };
};

// constructors
#define NUMBER(value) ((EvaValue){EvaValueType::NUMBER, {.number = value}})
#endif