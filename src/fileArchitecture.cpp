#include <filesystem>
#include <string>
#include "fileArchitecture.h"
#include "bws.h"
#include "log.h"

namespace fileArchitecture {
  bool createDirectories() noexcept {
    if (!std::filesystem::exists(baseDirectory + "logs")) {
      if (!std::filesystem::create_directory(baseDirectory + "logs")) {
        log::error("Failed to create directory at " + baseDirectory + "logs");
        shutdown(BWS_FILE_SYSTEM_ERROR);
        return false;
      }
    }

    if (!std::filesystem::exists(baseDirectory + "sites")) {
      if (!std::filesystem::create_directories(baseDirectory + "sites")) {
        log::error("Failed to create directory at " + baseDirectory + "sites");
        shutdown(BWS_FILE_SYSTEM_ERROR);
        return false;
      }
    }
  }
} // namespace fileArchitecture