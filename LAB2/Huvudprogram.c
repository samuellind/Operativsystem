/* Template for program that creates (forks off) three other processes */
/* Per Strömgren 2003-02-11 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "common.h"


/* redefine the program names if you want */
#define PRG_A "./PRG_A"
#define PRG_B "./PRG_B"
#define PRG_C "./PRG_C"

const int FALSE=0;
const int TRUE=1;

int processid1,processid2,processid3;

/* Clean-up function */
/* Pre: True
   Post: all signalling files removed, all daughter processes killed */
void cleanup(){
        
        kill(processid1, SIGTERM);
        kill(processid2, SIGTERM);
        kill(processid3, SIGTERM);
        
        p("a.lock");
        p("b.lock");
        p("c.lock");
        
        exit(0);
}


int main(int argc, char* argv[])
{
	
	v("a.lock");
	v("b.lock");
	v("c.lock");
	
	/* Set up reception of CTRL-C or other */
	signal(SIGINT, cleanup);
	

	/* create the A, B and C processes */
	
	if ((processid1=fork()) == 0)
	{
		execlp(PRG_A,PRG_A,NULL);
		/* If we return from execlp, it failed */
		printf("\n\"%s\" couldn't be executed. Check that it exists\n",PRG_A);
		exit(-1);
	}

	if ((processid2=fork()) == 0)
	{
		execlp(PRG_B,PRG_B,NULL);
		/* If we return from execlp, it failed */
		printf("\n\"%s\" couldn't be executed. Check that it exists\n",PRG_B);
		exit(-1);
	}

	if ((processid3=fork()) == 0)
	{
		execlp(PRG_C,PRG_C,NULL);
		/* If we return from execlp, it failed */
		printf("\n\"%s\" couldn't be executed. Check that it exists\n",PRG_C);
		exit(-1);
	}

	while(1);

	
	return 0;
}
