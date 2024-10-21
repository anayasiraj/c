#include <stdio.h>
#include <stdlib.h>

void printArr(int rows, int**arr){
	for(int i = 0; i < rows; i++){ // rows
                for(int j = 0; j < rows; j++){ // columns
                        printf("%d\t", arr[i][j]);
                }
                printf("\n");
        }
}


void freeArr(int rows, int**arrToFree){

	for (int i = 0; i < rows; i++){
		free(arrToFree[i]);
	}
	free(arrToFree);
}

void add(int rows, int**arr1, int**arr2){

	//malloc 
	
	int **newArr = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++){
		newArr[i] = (int*)malloc(rows * sizeof(int));
	}
	
	for (int j = 0; j < rows; j++){
		for (int k = 0; k < rows; k++){
			newArr[j][k] = (arr1[j][k] + arr2[j][k]);
		}
	}
	
	printf("RESULT ADD\n");
	printArr(rows, newArr);
	
	freeArr(rows, newArr);
	
	
}


void sub(int rows, int**arr1, int**arr2){

	//malloc 
	
	int **newArr = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++){
		newArr[i] = (int*)malloc(rows * sizeof(int));
	}
	
	for (int j = 0; j < rows; j++){
		for (int k = 0; k < rows; k++){
			newArr[j][k] = (arr1[j][k] - arr2[j][k]);
		}
	}
	
	printf("RESULT SUB\n");
	printArr(rows, newArr);
	
	freeArr(rows, newArr);
	
}

void mult(int rows, int**arr1, int**arr2){

	//malloc 
	
	int **newArr = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++){
		newArr[i] = (int*)malloc(rows * sizeof(int));
	}
	
	for (int j = 0; j < rows; j++){
		for (int k = 0; k < rows; k++){
			newArr[j][k] = 0;
			
			for (int l = 0; l < rows; l++) {
				newArr[j][k] += (arr1[j][l] * arr2[l][k]);
			}
		}
	}
	
	printf("RESULT MULT\n");
	printArr(rows, newArr);
	
	freeArr(rows, newArr);
}


void chooseOp(int rows, char*op, int**arr1, int**arr2){
	if (op[0] == 'M') {
		mult(rows, arr1, arr2);
	} else if (op[0] == 'S'){
		sub(rows, arr1, arr2);
	} else if (op[0] == 'A'){
		add(rows, arr1, arr2);
	} else {
		printf("error");
	}
}



int main(int argc, char**argv){
	FILE *fp = fopen(argv[1], "r");
	
	//check
	if (fp == NULL) {
        	perror("Error opening file");
        	return 1;
    	}
    	
    	// get rows
	int rows; 
	fscanf(fp, "%d\n", &rows);
	
	//get ops in order
	char op1[20];
	char op2[20];
	char op3[20];

	fscanf(fp, "%s\n", op1);
	
	fscanf(fp, "%s\n", op2);
	
	fscanf(fp, "%s\n", op3);
	
	// malloc
	int **arr1 = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++){
		arr1[i] = (int*)malloc(rows * sizeof(int));
	}
	int **arr2 = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++){
		arr2[i] = (int*)malloc(rows * sizeof(int));
	}
	
	// put values into arrays
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < rows; j++){
			fscanf(fp, "%d\n", &arr1[i][j]);
		}
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < rows; j++){
			fscanf(fp, "%d\n", &arr2[i][j]);
		}
	}
	
	chooseOp(rows, op1, arr1, arr2);
	chooseOp(rows, op2, arr1, arr2);
	chooseOp(rows, op3, arr1, arr2);
	
	
	// free arr1
	for (int i = 0; i < rows; i++){
		free(arr1[i]);
	}
	free(arr1);
	
	// free ar2
	for (int i = 0; i < rows; i++){
		free(arr2[i]);
	}
	free(arr2);
	
	fclose(fp);

	return EXIT_SUCCESS;
}
