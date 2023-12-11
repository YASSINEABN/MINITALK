#include <unistd.h>
#include <signal.h>
#include  <stdio.h>
#include <stdlib.h>

void send(unsigned char signal, char *pid)
{
    int pidd = atoi(pid);
    int i = 0;
    while(i < 8)
    {
		if(signal >> i & 1)
			kill(pidd , SIGUSR1);
		else
			kill(pidd , SIGUSR2);
		usleep(100);
		i++;
    }
   
}
void sighandler(int sig)
{
	write(1,"dkshy nadi",10);
  exit(1);
}

int main(int argc , char **argv)
{
    int i;

    i =  0;
    signal(SIGUSR1,sighandler);
    if(argc == 3)
    {
        while(argv[2][i])
        {
            send(argv[2][i],argv[1]);
			i++;
        }
          send(0,argv[1]);
	
    }
	while(1)
		pause();
    return 0;
}
