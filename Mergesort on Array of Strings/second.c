#include "../first/strlib.h"
#include <stdio.h>
#include <stdlib.h>
int height; //a global variable which will help us determine the height.

char issorted(char** array, int size){
    for(int i = 1; i < size; i++){
        if(str_cmp(array[i-1], array[i]) == 1){
            return 0;
        }
    }
    return 1;
}


/**
 * merge
 * We merge the two subarray to the main array, this is the 
 * sorting process
 * @param array, array we're merging to.
 * @param larray, the left subarray.
 * @param rarray, the right subarray.
 * @param a, length of array.
 * @param b, length of larray.
 * @param c, length of rarray.
 */

void merge(char** array, char** larray, char** rarray, int a, int b, int c){
	int i = 0; // left index
	int j = 0; // right index
	int k = 0; // new array index
	
	while (i < b && j < c) { // while left and right arrays have not BOTH been fully looked through
	
		if (str_cmp(larray[i], rarray[j]) <= 0) { // if left array i is less than OR equal to right array j:
			array[k] = larray[i];   // put that in new array first
 			i++;
		} else { // if right element less than left element: 
			array[k] = rarray[j]; // put that element in new array first
			j++;
		}
		k++;  // next new array element
	}

	// in case we didn't finish going through left array
	while (i < b) {
		array[k] = larray[i];
		i++;
		k++;
	}

	// in case we didn't finish going through left array
	while (j < c) {
		array[k] = rarray[j];
		j++;
		k++;
	}
}


/**
 * mergesort
 * 
 * This is our mergesort algorithm, which uses the divide
 * and conquer approach. We break the array into two halves.
 * 
 * @param array, our array of strings we want to sort.
 * @param size, the size of our array
 * @param heighta, helps us determine the maximum depth of the tree.
 */
void mergesort(char** array, int size, int curHeight, int *maxHeight){ 

	if (size < 2) return;  // if array has 1 item left, no need to continue breaking

	if (issorted(array, size) == 1) return;  // if array is sorted, no need to continue breaking

	// left and right array sizes
	int left = size/2;
	int right = size-left;

	// make space for left and right arrays
	char **leftArr = (char **)malloc(left * sizeof(char *));
	char **rightArr = (char **)malloc((right) * sizeof(char *));

	// fill left and right arrays with original array elements
	for (int i = 0; i < left; i++) {
		leftArr[i] = array[i];
	}
	for (int i = left; i < size; i++) {
		rightArr[i - left] = array[i];
	}
	
	// recursively break both sides and then merge back up 
	mergesort(leftArr, left, curHeight+1, maxHeight);    // height
	mergesort(rightArr, right, curHeight+1, maxHeight);
	
	merge(array, leftArr, rightArr, size, left, right);
	
	// keep track of how many times we break and merge to get height
	if (curHeight > *maxHeight){
		*maxHeight = curHeight;
	}

	// free arrays that have been merged
	free(leftArr);
	free(rightArr);
	
}

/**
 * This function will check if the array is sorted
 * @param array: The array of strings.
 * @param size: The size of the array.
 * @return 0 if array isn't sorted, 1 if sorted.
 */


/* These are corner cases you’re supposed to implement. What if you don’t add an argument to the program, What if you pass in an invalid file You’re responsible for error handling in this program.

For example, if the file you pass in is invalid, you should print out “Error: Failed to open %s” where %s is the file you tried to open
*/


int main(int argc, char**argv){

	// if no file given
	if (argc == 1) {
        	fprintf(stderr, "./second <filename>\n");
        	return 1;
        }
    
    	FILE *fp = fopen(argv[1], "r");
	
	// if file can't open
	if (fp == NULL) {
        	fprintf(stderr, "Error: Failed to open %s\n", argv[1]);
        	return 1;
    	}
    	
    	// length of array to sort
	int length;
	int c = fscanf(fp, "%d\n", &length);

	char **array = (char **)malloc(length * sizeof(char *)); // allocate space
	
	// put strings in file into array of strings
	for (int i = 0; i < length; i++){
		char word[50];
		c = fscanf(fp, "%s\n", word);
		array[i] = strdup(word);
	}
	
	c = 3; // ignore idk
	c=c+1;
	
	fclose(fp);
	
	int maxHeight = 0;
	
	mergesort(array, length, 0, &maxHeight);  // send with address to max height int

	// print sorted array + its height
	for (int j = 0; j < length; j++) {
		printf("%s\n", array[j]);
	}
	printf("height: %d\n", maxHeight+1);
	
	// free array
	for (int i = 0; i < length; i++) {
		free(array[i]); 
	}
	free(array);
    
    
	return EXIT_SUCCESS;
}






