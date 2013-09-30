#define oneMeg 1024L*1024L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>

#define INCREMENT 50
char *array;

/* returnera tidskillnaden mellan tv0 och tv1 i ms */
int difftod(struct timeval * tv0, struct timeval * tv1){
	return ((tv1->tv_sec - tv0->tv_sec)*1000 + (tv1->tv_usec- tv0->tv_usec)/1000);
}

/* Pre: true
   Post: objekt skapad med storlek enligt parameter, objektets alla element
	(eller intelligent urval) satta till något värde, och objektet makulerat igen.
	Inget nyttigt har utförts förutom att skapa objektet för att kunna
	ta tid på den. 0 har returnerats om allt gick bra, -1 annars.
*/
int createbigthing(long int storlek){
	
        /* Skapa ett stort objekt med någon metod, till exemepel malloc. */
      
       char *array =  malloc(storlek*oneMeg);
	if(array == NULL)
		{
		printf("out of memory\n");
		return -1;
		}
	else 
	return 0;
	int i;
       for(i= 0; i < 160*storlek; i+= 16*storlek){
       
       free(array);
       array = NULL;
       }
}



int main(){
	long int i;
	int rtn;
	struct timeval tv0, tv1;
	struct timezone tzp;

        /*  Skapa objekt med olika storlekar (i MB) och ta tid*/
	for(i=INCREMENT;i<=400;i=i+INCREMENT){
        	rtn = gettimeofday(&tv0, &tzp); /* set timer T0 */
        	createbigthing(i);
		rtn = gettimeofday(&tv1, &tzp); /* read time T1 */
		printf("%d msek\n",difftod(&tv0,&tv1));
		}
	return 0;
}

