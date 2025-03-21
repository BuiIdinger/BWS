#pragma once

#include <source_location>
#include <string>
#include <iostream>
#include <fstream>
#include "bws.h"
#include <filesystem>
#include "timeFunctions.h"

namespace log {
  static bool openLogFiles() noexcept;

  void info(const std::string& message, const std::source_location& location = std::source_location::current()) noexcept;
  void warning(const std::string& message, const std::source_location& location = std::source_location::current()) noexcept;
  void error(const std::string& message, const std::source_location& location = std::source_location::current()) noexcept;
} // namespace log