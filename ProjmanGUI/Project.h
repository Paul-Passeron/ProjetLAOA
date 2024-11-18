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
  std::string buildPath = "build";

public:
  Project(std::string projectName, std::filesystem::path projectPath);
  virtual void addModule(std::string moduleName);
  void setBuildSystem(std::unique_ptr<BuildSystem> bs);
  void build();
  void run(const std::vector<std::string> &args);
  void install();
};

class CProject : public Project {
  std::vector<std::string> modules;

public:
  CProject(std::string name, std::filesystem::path path);
};

#endif // PROJECT_H
