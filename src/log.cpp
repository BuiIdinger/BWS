#include <source_location>
#include <string>
#include <iostream>
#include <fstream>
#include "bws.h"
#include <filesystem>
#include "log.h"

std::fstream infoStream;
std::fstream warningStream;
std::fstream errorStream;

static bool openLogFiles() noexcept {
  errorStream.open(baseDirectory + "logs/error.log");
  if (errorStream.is_open()) {
    std::cerr << "Failed to open " + baseDirectory + "logs/error.log" << std::endl;
    shutdown(EXIT_FAILURE);
  }

  infoStream.open(baseDirectory + "logs/info.log");
  if (errorStream.is_open()) {
    std::cerr << "Failed to open " + baseDirectory + "logs/info.log" << std::endl;
    shutdown(EXIT_FAILURE);
  }

  warningStream.open(baseDirectory + "logs/warning.log");
  if (warningStream.is_open()) {
    std::cerr << "Failed to open " + baseDirectory + "logs/info.log" << std::endl;
    shutdown(EXIT_FAILURE);
  }
}

void log::info(const std::string& message, const std::source_location& location) noexcept {
  std::cerr << "[INFO] " << timeFunctions::getFormatted() << " " << location.file_name() << " " << location.function_name() <<  " (" << std::to_string(location.line()) << ":" << std::to_string(location.column()) << ") " + message << std::endl;
}

void log::warning(const std::string& message, const std::source_location& location) noexcept {
  std::cerr << "[WARNING] " << timeFunctions::getFormatted() << " " << location.file_name() << " " << location.function_name() <<  " (" << std::to_string(location.line()) << ":" << std::to_string(location.column()) << ") " + message << std::endl;
}

void log::error(const std::string& message, const std::source_location& location) noexcept {
  std::cerr << "[ERROR] " << timeFunctions::getFormatted() << " " << location.file_name() << " " << location.function_name() <<  " (" << std::to_string(location.line()) << ":" << std::to_string(location.column()) << ") " + message << std::endl;
}