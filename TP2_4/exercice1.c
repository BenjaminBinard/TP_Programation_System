#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

static int print_flag = false;

void handle_alarm() {
    print_flag = true;
}

int main() {
    signal(SIGALRM, handle_alarm); // Install handler first,
    alarm(1); // before scheduling it to be called.
    time_t t;

    for (;;) {
        if (print_flag) {
            time(&t);
            printf("%s", asctime(localtime(&t)));
            print_flag = false;
            alarm(5);
        }
    }
}
