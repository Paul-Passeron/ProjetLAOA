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

class MakefileBS : public BuildSystem {
public:
  void configure() override;
  void build() override;
  void clean() override;
};

#endif // BUILD_SYSTEM_H
