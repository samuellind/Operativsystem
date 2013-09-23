/* Template for process A, B and C */
/* Per Strömgren 2003-02-11 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

const int FALSE=0;
const int TRUE=1;

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
	fd =open(signalname,O_CREAT|O_EXCL|O_WRONLY,S_IWUSR);
	while(fd!=-1);
	/* Set the signal, i.e. create the file */
	/* If the file can't be reated, do an "exit(-1)" */
	return 0;
}

/*int main(){
        Some printfs, signals and/or waits here  
        char *name;
        int perms;
	while(TRUE){
		// Some printfs, signals and/or waits here 	
	}
	return 0;
}*/
