#include <stdlib.h>
#include "fileArchitecture.h"
#include "log.h"
#include "bws.h"

const void shutdown(const int& exitCode) noexcept {
  exit(exitCode);
}

int main(int argc, char *argv[]) {
  fileArchitecture::createDirectories();
  log::openLogFiles();

  log::error("Oh noes!");
  log::info("INFO LOG");
  
  return BWS_SUCCESS;
}