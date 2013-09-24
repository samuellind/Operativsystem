#include <stdio.h>
#include "common.h"
#include "common.c"

int main(){
	v("b.lock");
	printf("C0");
	fflush(NULL);
	p("c.lock");
	
	while(1==1){
	v("b.lock");
	printf("C1");
	fflush(NULL);
	p("c.lock");
	}
	
	return 0;
}
