#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static void sig_usr(int signo) {
    if (signo == SIGUSR1) {
        printf("1\n");
    } else if (signo == SIGUSR2) {
        printf("0\n");
    } else {
        printf("error\n");
    }
}

int main() {
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        perror("Can't catch the signal");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        perror("Can't catch the signal");
    }

    for (;;) {
        sleep(1);
    }

    return 0;
}

