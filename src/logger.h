
#ifndef Logger_h
#define Logger_h
#include <sstream>
class ErrorLogger : public std::basic_stringstream<char> {
public:
  ~ErrorLogger() {
    fprintf(stderr, "Fatal error: %s\n", str().c_str());
    exit(EXIT_FAILURE);
  }
};

#define DIE ErrorLogger()
#endif