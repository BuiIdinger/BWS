#pragma once

#include <string>

#define BWS_SUCCESS 0
#define BWS_FILE_SYSTEM_ERROR 13

/* Shutdown the server */
const void shutdown(const int& exitCode) noexcept;

const inline std::string baseDirectory = "/Users/shaydenseymour/bws/";