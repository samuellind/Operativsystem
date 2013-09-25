#include <stdio.h>
#include "common.h"

int main(){

	printf("A");
	fflush(stdout);
	p("b.lock");
	
	

		while(1){
		
			v("a.lock");
			printf("A");
			fflush(stdout);
			p("b.lock");
	
			v("a.lock");
			printf("A");
			fflush(stdout);
			p("c.lock");
		}
	
	return 0;
}