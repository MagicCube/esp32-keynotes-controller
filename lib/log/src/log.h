#pragma once

#include <Arduino.h>

#include <memory>
#include <stdarg.h>

// Print INFO log.
void LOG_I(const std::string fmt_str, ...);

// Print DEBUG log.
void LOG_D(const std::string fmt_str, ...);
