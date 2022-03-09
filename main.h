#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define SALDO 1
#define SAIR 2

void cumprimentar();
void ver_saldo();
int comandar();

