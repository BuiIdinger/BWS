#pragma once

#include <chrono>
#include <string>

namespace timeFunctions {
  std::time_t getCurrent() noexcept;
  std::string getFormatted() noexcept;
  std::string getShortDate() noexcept;
} // namespace timeFunctions