// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <signal.h>
// #include <math.h>

//  volatile int i = 0;
//  volatile int bit = 0;
//  volatile int check = 0;
// void printColorText(const char *text, int colorCode) {
    
//     printf("\033[1;%dm%s\033[0m\n", colorCode, text);
// }
// void printpid(int pid)
// {
//      printf("                   \033[1;%dm%d\033[0m\n", 33, pid);
// }
// int pow(int base , int num)
// {
// 	int i = 0;
// 	int n = 1;
// 	while(i < num)
// 	{
// 		n*=base;
// 		i++;
// 	}
// 	return n;
// }


// void sighandler(int sign) {
//  if (sign == SIGUSR1) {
// 		i+=pow(2,bit);
// 		bit++;
//         printf(" ");
//     } else if (sign == SIGUSR2) {
// 		bit++;
//         // printf("0   i=   %d ;    bit = %d\n",i,bit);
        
//     } 
//     if(bit == 8)
//     {
//         char c = (char)i;
//        write(1,&c,1);
      
//          i = 0;
//          bit = 0 ;
//         // printf("\n");

//     }
//     // printf("\n  i vf =     %d   \n",i);
// 	// if(bit == 8)
// 	// {
// 	// 	printf("hhh");
// 	// 	putchar(i);
// 	// 	bit =0;
// 	// 	i = 0;
// 	// }
	
// }
	



// int main() {
  
    
//     printColorText("**********************************************", 33); 
//     printColorText("*                                            *", 33);
//     printColorText("*    THIS IS THE SERVER MAKED BY YASSINE     *", 33);
//     printColorText("*             MY PID IS BELLOW               *", 33);
//     printpid(getpid());
//     printColorText("*                                            *", 33);
//     printColorText("**********************************************", 33);



//     if (signal(SIGUSR1, sighandler) == SIG_ERR)
//     {
        
//         perror("Can't catch the signal");
//     }
//     if(signal(SIGUSR2, sighandler) == SIG_ERR)
// 	    perror("Can't catch the signal");

//     while (42) {
//         pause();
//     }

//     return 0;
// }



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
volatile int i = 0;
volatile int bit = 0;
void sighandler(int sign) {
   // static int i = 0;
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

       // if (c == '\0')
         //   write(1,"\n",1);
   //     if(c == ' ')
 //        write(1," ",1);

        i = 0;
        bit = 0;
    }
}

int main() {
    print_banner(getpid());

    signal(SIGUSR1, sighandler);
    signal(SIGUSR2, sighandler);

    while (1) {
        pause();
    }

    return 0;
}
