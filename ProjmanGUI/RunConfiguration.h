#ifndef RUN_CONFIG_H
#define RUN_CONFIG_H

#include "Project.h"
#include <memory>
#include <string>

class RunConfiguration {
  std::string name;
  std::unique_ptr<Project> project;
  std::vector<std::string> args;

public:
  RunConfiguration(std::string name, std::unique_ptr<Project> project,
                   std::vector<std::string> args);
  void setArgs(std::vector<std::string> args);
  std::string getName() const;
  std::unique_ptr<Project> getProject() const;
  std::vector<std::string> getArgs() const;
  int execute();
};

#endif // RUN_CONFIG_H