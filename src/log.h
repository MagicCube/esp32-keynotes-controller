#include <Arduino.h>

#include <memory>
#include <stdarg.h>

using namespace std;

enum class LogLevel { DEBUG = 1, INFO = 2, WARN = 3, ERROR = 4 };

void LOG(const string fmt_str, ...) {
  Serial.print("[INF] ");
  int final_n,
      n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
  unique_ptr<char[]> formatted;
  va_list ap;
  while (1) {
    formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
    strcpy(&formatted[0], fmt_str.c_str());
    va_start(ap, fmt_str);
    final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
    va_end(ap);
    if (final_n < 0 || final_n >= n) {
      n += abs(final_n - n + 1);
    } else {
      break;
    }
  }

  Serial.println(formatted.get());
}
