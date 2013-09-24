/* Template for process A, B and C */
/* Per Strömgren 2003-02-11 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "common.h"


int fd, ok;

/* The p() and v() procedures implement the Wait and Signal function respectively */

/*
        Function waits until file "signalname" exists and removes it.

        Pre: True
        Post: File "signalname" removed
*/
int p(char * signalname){
	ok = unlink(signalname);
	return 0;
}

/*
        Pre:   True
        Post:  File with "signalname" created or, if creation failed, problem text written and exited
*/
int v(char * signalname){
	int fd =-1;
	while(fd<0){
		fd = open(signalname,O_CREAT|O_EXCL|O_WRONLY,S_IWUSR);
		}
	//close(fd);
	return 0;
}
