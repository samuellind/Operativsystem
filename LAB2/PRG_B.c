#include <stdio.h>
#include <unistd.h>
#include "common.h"

int main(){
	
	
	v("b.lock");
	printf("B");
	fflush(stdout);
	p("c.lock");
	

	while(1){
		v("b.lock");
		printf("B ");
		fflush(stdout);
		sleep(2);
		p("a.lock");
	}
	
	return 0;
}
