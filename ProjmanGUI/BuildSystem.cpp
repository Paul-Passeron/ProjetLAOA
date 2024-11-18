#include "BuildSystem.h"
#include <stdexcept>

void MakefileBS::configure() {
  throw std::runtime_error("MakefileBS::configure() is not implemented");
}

void MakefileBS::build() {
  throw std::runtime_error("MakefileBS::build() is not implemented");
}

void MakefileBS::clean() {
  throw std::runtime_error("MakefileBs::clean() is not implemented");
}