/*******************************************************************/
/* Program to dynamically allocate a 2-D array using arr of ptr    */
/******************** AUTHOR : ANAND MOHAN TIWARI ******************/
/*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int *p[3], i, j, col;
	printf("Enter number of columns:\n");
		scanf("%d", &col);
	for(i=0; i<3; i++)
		p[i] = (int *)malloc(col*sizeof(int));
	printf("Enter elements : \n");
		for(i=0; i<3; i++)
			for(j=0; j<col; j++)
				scanf("%d", &col);
	printf("You enetered : \n");
		for(i=0; i<3; i++){
			for(j=0; j<col; j++)
				printf("%d\t", p[i][j]);
			printf("\n");
		}
	for(i=0; i<3; i++)	
		free(p[i]);

return 0;
}
