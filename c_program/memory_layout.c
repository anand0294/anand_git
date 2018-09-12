/* low address : 1.text segment( code segment or simply text) contains executable code
 * 2. initialized data ( Data segment ) it is of two types read-only, read-write. eg.
 * char s[]="hello world"; int debug =1; initialized in global space is read-write
 * and const char s[] ="hello world"; is read-only. 3. BSS(block start by symbol or
 * unitialized data ). data in this segment is initialized to zero by kernel 4.heap
 * segment High address 5. Stack segment
 * Author : ANAND MOHAN TIWARI
 */
#include<stdio.h>

//step 2 global variable
// int global; /* Uninitialized variable stored in bss*/
//step 5
 int global =10; /* initialized global variable stored in DS*/

int main(){

//step 3 static variable
// static int i; /* Uninitialized static variable stored in bss */

//step 4
 static int i=100; /* Initialized static variable stored in DS*/

//step1: compile step by step and check bss value
return 0;
}

// use size ./a.out or ./(any name specified to executable program)

