#include <stdio.h>
#include "common.h"
#include "common.c"

int main(){
	v("a.lock");
	printf("B0");
	fflush(NULL);
	p("b.lock");
	
	v("c.lock");
	
	while(1==1){
	v("a.lock");
	printf("B1");
	fflush(NULL);
	p("b.lock");
	}
	return 0;
}
