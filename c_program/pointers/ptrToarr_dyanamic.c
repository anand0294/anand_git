/*******************************************************************/
/* This progran shows to dynamically allocate a 2-D array using    */
/* pointer to an array.                                            */
/************** AUTHOR : ANAND MOHAN TIWARI       ******************/
/*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int (*ptr)[4], i, j, row;
	printf("Enter number of rows :\n ");
	scanf("%d", &row);
		ptr = (int (*)[4])malloc(row*4*sizeof(int) );
	printf("Enter elements of 2-D array : \n");
	for(i=0; i<row; i++)
		for(j=0; j<4; j++)
			scanf("%d", &ptr[i][j]);

	printf("You Entered : \n");
		for(i=0; i<row; i++){
			for(j=0; j<4; j++)
				printf("%d\t", ptr[i][j]);
		
		printf("\n");
		}
		free(ptr);
return 0;
}
