#include <stdio.h>
#include <stdlib.h>
#include "./strlib.h"

/**
 * @brief Main function to test string manipulation functions implemented in strlib.h.
 * 
 * This includes:
 * - Comparing strings using strcmp
 * - Calculating the length of a string with str_len
 * - Copying strings with str_cpy
 * - Duplicating strings using strdup
 *
 * @note To compile the program, use: make customtestclient
 * @note Run the executable to see the results of the tests.
 // run = ./customtestclient
 // run other one = ./testclient args args args args
 * 
 * The expected outcomes for the test cases are noted in the output.
 */
 
 // ./testclient arg1 arg2 arg3 arg4

int main(int argc, char **argv)
{
    printf("Comparing 'CS211' and 'CS206': %d\n", str_cmp("CS211", "CS206")); 
    printf("length of jimin: %d\n", str_len("jimin"));
	char name[] = "theodore";
	char newName[10];  // do i need cases for error if too small???
	str_cpy(newName, name);
	printf("the name is: %s\n", newName);

    return 0;
}
