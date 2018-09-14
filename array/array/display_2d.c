/*******************************************************************/
/*** This program explain to Input and display 2D array/matrics ****/
/****************** AUTHOR : ANAND MOHAN TIWARI ********************/
/*******************************************************************/

#include<stdio.h>

#define ROW 3
#define COL 3

int main(void){
	int i, j, mat[ROW][COL];
	printf("Enter the two dimensional array : \n");
	for(i=0; i<ROW; i++)
		for(j=0; j<COL; j++){
			scanf("%d", &mat[i][j]);
		}
	printf("Entered two dimensional arrays is: \n");
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
