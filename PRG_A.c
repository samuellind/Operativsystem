#include <stdio.h>
#include "common.h"
#include "common.c"

int main(){
	printf("\nA0");
	fflush(NULL);
	p("a.lock");
	
	while(1==1){
	v("c.lock");
	sleep(2);
	printf(" A1");
	fflush(NULL);
	p("a.lock");
	
	v("b.lock");
	sleep(2);
	printf(" A2");
	fflush(NULL);
	p("b.lock");
	}
	
	return 0;
}
