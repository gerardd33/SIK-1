#ifndef ERR_H_
#define ERR_H_

void syserr(const char* fmt, ...) __attribute__((noreturn));
void fatal(const char* fmt, ...) __attribute__((noreturn));

#endif  // ERR_H_
