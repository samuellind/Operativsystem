#include <stdio.h>
#include <unistd.h>
#include "common.h"

int main(){
	
	
	v("c.lock");
	printf("C ");
	fflush(NULL);
	sleep(2);
	
	p("a.lock");

	while(1){
			
		v("c.lock");
		printf("C ");
		fflush(stdout);
		sleep(2);
		p("a.lock");
	}

	
	return 0;
}
