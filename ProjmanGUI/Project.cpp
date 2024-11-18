#include "Project.h"
#include "BuildSystem.h"
#include <stdexcept>
#include <stdio.h>
#include <string>

Project::Project(std::string name, std::filesystem::path path)
    : projectName(name), projectPath(path) {}

CProject::CProject(std::string name, std::filesystem::path path)
    : Project(name, path) {
  setBuildSystem(std::unique_ptr<BuildSystem>(new MakefileBS()));
}

std::string exec(const char* cmd) {
    char buffer[256];
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer, static_cast<int>(sizeof buffer), pipe.get()) != nullptr) {
        result += buffer;
    }
    return result;
}

void Project::install() {
    build();
    std::string command = "";
    command.append("pkexec ");
    command.append("cp ");
    command.append(projectPath.c_str());
    command.append("/");
    command.append(buildPath.c_str());
    command.append("/");
    command.append(projectName.c_str());
    command.append(" /usr/bin/");
    std::string res = exec(command.c_str());
}
