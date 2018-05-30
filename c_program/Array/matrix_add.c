/*******************************************************************/
/** This program clearly explain the addition of two matrix       **/
/******************* AUTHOR : ANAND MOHAN TIWARI *******************/
/*******************************************************************/


#include<stdio.h>

/**you can either manually enter the number of rows and column and check **/
/*** if rows and column of matrix1 is equal to matrix2, if equals perform **/
/*** addition else exit or define it. Here i'm entering it manually ********/

int main(){
	int row, col, row1, col1;
	
	printf("Enter number of rows and column respectively of mat1: \n");
	scanf("%d%d", &row, &col);
	printf("Enter number of rows and column respectively of mat2: \n");
	scanf("%d%d", &row1, &col1);

	int i, j,mat[row][col],mat1[row][col], mat2[row1][col1];

	if((row==row1) && (col==col1)){
		printf("Enter elements of matrix1 :\n ");
		for(i=0; i<row; i++){
			for(j=0; j<col; j++)
				scanf("%d", &mat1[i][j]);
		}	
		printf("Enter elements of matrix2 :\n ");
		for(i=0; i<row1; i++){
			for(j=0; j<col1; j++)
				scanf("%d", &mat2[i][j]);
		}	
		for(i=0; i<row; i++){
			for(j=0; j<col; j++)
				mat[i][j]= mat1[i][j] + mat2[i][j];
		}	
		printf("Addition of both matrix is : \n ");
		for(i=0; i<row; i++){
			for(j=0; j<col; j++)
				printf("%d ", mat[i][j]);
				printf("\n");
		}	

	}
	else
		printf(" Matrix addition cannot be performed\n");
	return 0;
}
