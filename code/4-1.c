#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#define sleep_sec(n) Sleep((n) * 1000)
#else
#include <unistd.h>
#define sleep_sec(n) sleep(n)
#endif

int main(void) {
    printf("[1] before fflush - ");
    sleep_sec(2);
    printf("(2s elapsed, no fflush)\n");

    printf("[2] after explicit fflush - ");
    fflush(stdout);
    sleep_sec(2);
    printf("(2s elapsed, fflush was called)\n");

    return 0;
}
