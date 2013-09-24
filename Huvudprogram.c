/* Template for program that creates (forks off) three other processes */
/* Per Strömgren 2003-02-11 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include "common.c"

/* redefine the program names if you want */
#define PRG_A "./PRG_A"
#define PRG_B "./PRG_B"
#define PRG_C "./PRG_C"

const int FALSE=0;
const int TRUE=1;


/* Clean-up function */
/* Pre: True
   Post: all signalling files removed, all daughter processes killed */
void cleanup(){
        /* Some code is needed here */
}


int main(int argc, char* argv[])
{
	int processid;
	p("a.lock");
	p("b.lock");
	p("c.lock");
	
	/* Set up reception of CTRL-C or other */

	/* create the A, B and C processes */
	
	if ((processid=fork()) == 0)
	{
		execlp(PRG_A,PRG_A,NULL);
		/* If we return from execlp, it failed */
		printf("\n\"%s\" couldn't be executed. Check that it exists\n",PRG_A);
		exit(-1);
	}
	if ((processid=fork()) == 0)
	{
		execlp(PRG_B,PRG_B,NULL);
		/* If we return from execlp, it failed */
		printf("\n\"%s\" couldn't be executed. Check that it exists\n",PRG_B);
		exit(-1);
	}
	if ((processid=fork()) == 0)
	{
		execlp(PRG_C,PRG_C,NULL);
		/* If we return from execlp, it failed */
		printf("\n\"%s\" couldn't be executed. Check that it exists\n",PRG_C);
		exit(-1);
	}
	printf("\nProcesses started if no error messages displayed, use \"ps\" command to check.\n ");
	/* wait here for a CTRL-C */
	
	while(1)
	;
	//interupt ctrl-c;
	
	int i;
	for(i=0;i<3;i++)
	{
		wait(NULL);
	}
	printf("All processes terminated\n");
	
	return 0;
}
