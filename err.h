#ifndef ERR_H_
#define ERR_H_

/* Wypisuje informację o błędnym zakończeniu funkcji systemowej
i kończy działanie programu. */
void syserr(const char* fmt, ...) __attribute__((noreturn));

/* Wypisuje informację o błędzie i kończy działanie programu. */
void fatal(const char* fmt, ...) __attribute__((noreturn));

#endif  // ERR_H_
