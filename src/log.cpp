#include <source_location>
#include <string>
#include <iostream>
#include <fstream>
#include "bws.h"
#include <filesystem>
#include "log.h"
#include <ios>
#include <ctime>

std::ofstream infoStream;
std::ofstream warningStream;
std::ofstream errorStream;

void log::closeLogFiles() noexcept {
  infoStream.close();
  warningStream.close();
  errorStream.close();
}

void log::openLogFiles() noexcept {
  const std::string shortDate = timeFunctions::getShortDate() + "-";
  infoStream.open(baseDirectory + "logs/" + shortDate + "info.log", std::ios::app);
  if (!infoStream.is_open()) {
    log::error("Failed to open " + baseDirectory + "logs/info.log");
    shutdown(BWS_FILE_SYSTEM_ERROR);
  }

  warningStream.open(baseDirectory + "logs/" + shortDate + "warning.log", std::ios::app);
  if (!warningStream.is_open()) {
    log::error("Failed to open " + baseDirectory + "logs/warning.log");
    shutdown(BWS_FILE_SYSTEM_ERROR);
  }

  errorStream.open(baseDirectory + "logs/" + shortDate + "error.log", std::ios::app);
  if (!errorStream.is_open()) {
    log::error("Failed to open " + baseDirectory + "logs/error.log");
    shutdown(BWS_FILE_SYSTEM_ERROR);
  }
}

void log::info(const std::string& message, const std::source_location& location) noexcept {
  const std::string outputMessage = "[INFO] " + timeFunctions::getFormatted() + " " + location.file_name() + " " + location.function_name() + " (" + std::to_string(location.line()) + ":" + std::to_string(location.column()) + ") " + message;
  std::cerr << outputMessage << "\n";
  if (infoStream.is_open()) {
    infoStream << outputMessage << "\n";
  }
}

void log::warning(const std::string& message, const std::source_location& location) noexcept {
  const std::string outputMessage = "[WARNING] " + timeFunctions::getFormatted() + " " + location.file_name() + " " + location.function_name() + " (" + std::to_string(location.line()) + ":" + std::to_string(location.column()) + ") " + message;
  std::cout << outputMessage << "\n";
  if (warningStream.is_open()) {
    warningStream << outputMessage << "\n";
  }
}

void log::error(const std::string& message, const std::source_location& location) noexcept {
  const std::string outputMessage = "[ERROR] " + timeFunctions::getFormatted() + " " + location.file_name() + " " + location.function_name() + " (" + std::to_string(location.line()) + ":" + std::to_string(location.column()) + ") " + message;
  std::cout << outputMessage << std::endl;
  if (errorStream.is_open()) {
    errorStream << outputMessage << "\n";
  }
}