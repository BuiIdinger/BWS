#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "timeFunctions.h"
#include <string>
#include <sstream>

std::time_t timeFunctions::getCurrent() noexcept {
  return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

std::string timeFunctions::getFormatted() noexcept {
  const std::time_t timeNow = timeFunctions::getCurrent();
  std::tm* localTime = std::localtime(&timeNow);

  /* Format the time into a string */
  std::ostringstream oss;
  oss << std::put_time(localTime, "%d/%m/%Y %H:%M:%S");
  return oss.str();
}

std::string timeFunctions::getShortDate() noexcept {
  std::time_t time = std::time(nullptr);
  struct tm *timeInfo = std::localtime(&time);
  
  std::string shortDate = std::to_string(timeInfo->tm_mday) + "-" + std::to_string(timeInfo->tm_mon + 1) + "-" + std::to_string(timeInfo->tm_year + 1900);
  return std::move(shortDate); 
}