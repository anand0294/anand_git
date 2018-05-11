/*******************************************************************/
/******* This program explains how to transpose the matrix *********/
/*******************************************************************/

#include<stdio.h>

#define ROW 3
#define COL 3

int main(){
	int i, j, mat1[ROW][COL], mat2[ROW][COL];
	printf("Enter the 3*3 matrix to transpose\n");
	for(i=0; i<ROW; i++)
		for(j=0; j<COL; j++)
			scanf("%d",&mat1[i][j]);
	//Transpose of the matrix
	for(j=0; j<COL; j++)
		for(i=0; i<ROW; i++)
			mat2[i][j] = mat1[j][i];
	//Displaying 
	printf("Transpose of above matrix is :\n");
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++)
			printf("%5d",mat2[i][j]);
			printf("\n");
		}
return 0;
}  
