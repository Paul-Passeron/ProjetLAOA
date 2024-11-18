#include "Project.h"
#include "BuildSystem.h"
#include <QString>
#include <filesystem>
#include <stdexcept>
#include <stdio.h>
#include <string>

using namespace std::filesystem;

std::string exec(const char *cmd) {
  char buffer[256];
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    // TODO: hendle error internally
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer, static_cast<int>(sizeof buffer), pipe.get()) !=
         nullptr) {
    result += buffer;
  }
  return result;
}

void Project::install() {
  this->build();
  std::string command = "";
  path project_path = ::absolute(getProjectPath());
  path build_path = project_path / "build";
  path executable = absolute(build_path / getProjectName());
  command += "pkexec ";
  command += "cp ";
  command += executable.string();
  command += " /usr/bin/";
  std::string res = exec(command.c_str());
}

path Project::getProjectPath() { return projectPath; }

std::string Project::getRealProjectName() { return projectName; }

std::string Project::getProjectName(){
    QString n = QString::fromStdString(projectName);
    n.replace(' ', '_');
    return n.toStdString();
}

std::string Project::getBuildPath() {
  return buildPath;
}
std::string Project::getIncludePath() { return includePath; }
std::string Project::getSourcePath() { return sourcePath; }

void Project::setBuildSystem(std::unique_ptr<BuildSystem> bs) {
  buildSystem = std::move(bs); // transfer ownership
}

void Project::build() { buildSystem->build(); }

void Project::setProjectName(std::string s) { projectName = s; }
void Project::setBuildPath(std::string s) { buildPath = s; }
void Project::setIncludePath(std::string s) { includePath = s; }
void Project::setSourcePath(std::string s) { sourcePath = s; }
void Project::setProjectPath(std::filesystem::path p) { projectPath = p; }

CProject::CProject(std::string name, path path) {
  setProjectName(name);
  setProjectPath(path);
  setBuildSystem(std::unique_ptr<BuildSystem>(new MakefileBS()));
}

void CProject::initFileSystem() {
  throw std::runtime_error("TODO: implement CProject::initFileSystem");
  path project_path = ::absolute(getProjectPath());
  path build_path = project_path / getBuildPath();
  path include_path = project_path / getIncludePath();
  path src_path = project_path / getSourcePath();
  if (!exists(project_path)) {
    create_directories(project_path);
  }
  if (!exists(build_path)) {
    create_directory(build_path);
  }
  if (!exists(include_path)) {
    create_directory(include_path);
  }
  if (!exists(src_path)) {
    create_directory(src_path);
  }
}

void CProject::addModule(std::string name) {
  throw std::runtime_error("TODO: implement CProject::addModule");
}
