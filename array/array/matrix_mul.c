/*******************************************************************/
/** This program clearly explain the multiplication of two matrix **/
/******************* AUTHOR : ANAND MOHAN TIWARI *******************/
/*******************************************************************/


#include<stdio.h>

#define row1 3
#define col1 4
#define row2 col1
#define  col2 2

int main(){
	int i, j, k,mat3[row1][col2],mat1[row1][col1], mat2[row2][col2];
		printf("Enter elements of matrix1 :\n ");
		for(i=0; i<row1; i++){
			for(j=0; j<col1; j++)
				scanf("%d", &mat1[i][j]);
		}	
		printf("Enter elements of matrix2 :\n ");
		for(i=0; i<row2; i++){
			for(j=0; j<col2; j++)
				scanf("%d", &mat2[i][j]);
		}	
		for(i=0; i<row1; i++){
			for(j=0; j<col2; j++){
				mat3[i][j]=0;
				for(k=0; k<col1; k++)
				mat3[i][j]+= mat1[i][k] * mat2[k][j];
			}
		}	
		printf("Multiplication of both matrix is : \n ");
		for(i=0; i<row1; i++){
			for(j=0; j<col2; j++)
				printf("%d ", mat3[i][j]);
				printf("\n");
		}	
	return 0;
}
