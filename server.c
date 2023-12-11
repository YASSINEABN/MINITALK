
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
# define RED "\033[31m"

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BOLD "\033[1m"
# define RESET "\033[0m"




void	print_banner(int pid)
{
	printf("%s%s ███▄ ▄███▓██▓███▄    █ ██▄▄▄█████▓▄▄▄      ██▓    ██ ▄█▀\n",
		BOLD, GREEN);
	printf("%s%s▓██▒▀█▀ ██▓██▒██ ▀█   █▓██▓  ██▒ ▓▒████▄   ▓██▒    ██▄█▒ \n",
		BOLD, YELLOW);
	printf("%s%s▓██    ▓██▒██▓██  ▀█ ██▒██▒ ▓██░ ▒▒██  ▀█▄ ▒██░   ▓███▄░ \n",
		BOLD, RED);
	printf("%s%s▒██    ▒██░██▓██▒  ▐▌██░██░ ▓██▓ ░░██▄▄▄▄██▒██░   ▓██ █▄ \n",
		BOLD, RESET);
	printf("%s%s▒██▒   ░██░██▒██░   ▓██░██░ ▒██▒ ░ ▓█   ▓██░██████▒██▒ █▄\n",
		BOLD, YELLOW);
	printf("%s%s░ ▒░   ░  ░▓ ░ ▒░   ▒ ▒░▓   ▒ ░░   ▒▒   ▓▒█░ ▒░▓  ▒ ▒▒ ▓▒\n",
		BOLD, GREEN);
	printf("%s%s░  ░      ░▒ ░ ░░   ░ ▒░▒ ░   ░     ▒   ▒▒ ░ ░ ▒  ░ ░▒ ▒░\n",
		BOLD, RED);
	printf("%s%s░      ░   ▒ ░  ░   ░ ░ ▒ ░ ░       ░   ▒    ░ ░  ░ ░░ ░ \n",
		BOLD, RED);
	printf("%s%s       ░   ░          ░ ░               ░  ░   ░  ░  ░   \n\
		%s", BOLD, RED, RESET);
	printf("													 		\n");
	printf("%s%s		by: yaboulan %s| %sPID: %d%s\n",
		BOLD, GREEN, YELLOW, GREEN, pid, RESET);
}

void printpid(int pid) {
    printf("                   \033[1;%dm%d\033[0m\n", 33, pid);
}

int ft_pow(int base, int num) {
    int i = 0;
    int n = 1;
    while (i < num) {
        n *= base;
        i++;
    }
    return n;
}
void sighandler(int sign , siginfo_t *t, void *oldaction) {
    static int i ;
	static int bit ;
    unsigned char c;

    if (sign == SIGUSR1) {
        i += ft_pow(2, bit);
        bit++;
    } else if (sign == SIGUSR2) {
        bit++;
    }

    if (bit == 8) {
        c = i;
        write(1, &c, 1);

        if (c == '\0')
        {
           write(1,"\n",1);
           kill(t->si_pid,SIGUSR1);
        }

        i = 0;
        bit = 0;
    }
}

int main() {
    print_banner(getpid());
    struct sigaction test;
    test.sa_sigaction = sighandler;
    test.sa_flags= SA_SIGINFO;
    if(sigaction(SIGUSR1,&test,NULL) == -1)
    {
         perror("Error setting up SIGUSR1 handler");
        return 1;
    }
       if(sigaction(SIGUSR2,&test,NULL) == -1)
    {
         perror("Error setting up SIGUSR1 handler");
        return 1;
    }

    // signal(SIGUSR1, sighandler);
    // signal(SIGUSR2, sighandler);

    while (1) {
        pause();
    }

    return 0;
}
