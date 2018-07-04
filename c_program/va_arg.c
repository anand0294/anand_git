#include<stdarg.h>
#include<stdio.h>

int sum(int arg, ...){
	int i, answer=0;
	va_list ap;
	va_start(ap, arg);
	for(i=1; i<arg; i++){
		answer+=va_arg(ap, int);
	}
	va_end(ap);
return answer;
}

int main(){
	int d, count = 11 ;
	d = sum(count, 4, 5, 6, 7, 8, 9, 1, 2, 3, 10);
	/*First variable is the number of arguments*/
	printf("Sum is %d\n", d);
return 0;
}
