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
  std::string buildPath = "build"; // default build path
  std::string includePath = "include";
  std::string sourcePath = "src";

public:
  virtual void initFileSystem() = 0;
  virtual void addModule(std::string moduleName) = 0;
  void setBuildSystem(std::unique_ptr<BuildSystem> bs);
  void build();
  void run(const std::vector<std::string> &args);
  void install();
  std::filesystem::path getProjectPath();
  std::string getProjectName();
  std::string getRealProjectName();
  std::string getBuildPath();
  std::string getIncludePath();
  std::string getSourcePath();
  void setProjectName(std::string s);
  void setBuildPath(std::string s);
  void setIncludePath(std::string s);
  void setSourcePath(std::string s);
  void setProjectPath(std::filesystem::path p);
  ~Project() = default;
  static Project *projectFromSpecs(std::string name, std::filesystem::path path,
                                   std::string lang, std::string bs);
};

class CProject : public Project {
  std::vector<std::string> modules;

public:
  CProject(std::string name, std::filesystem::path path);
  void initFileSystem() override;
  void addModule(std::string name) override;
};

#endif // PROJECT_H
