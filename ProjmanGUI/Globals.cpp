#include "Globals.h"
#include <memory>
#include <stdexcept>

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
