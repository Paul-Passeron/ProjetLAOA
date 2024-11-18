#ifndef PROJECT_H
#define PROJECT_H

#include "BuildSystem.h"
#include <filesystem>
#include <string>
#include <vector>

class Project {
  std::string projectName;
  std::filesystem::path projectPath;
  std::unique_ptr<BuildSystem> buildSystem;

public:
  virtual void addModule(std::string moduleName);
  virtual void build();
  virtual void run(const std::vector<std::string> &args);
  virtual void install();
};

#endif // PROJECT_H