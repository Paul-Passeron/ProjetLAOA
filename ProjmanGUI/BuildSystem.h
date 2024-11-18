#ifndef BUILD_SYSTEM_H
#define BUILD_SYSTEM_H

#include <string>

class BuildSystem {
  std::string name;

public:
  virtual void configure() = 0;
  virtual void build() = 0;
  virtual void clean() = 0;
};

#endif // BUILD_SYSTEM_H