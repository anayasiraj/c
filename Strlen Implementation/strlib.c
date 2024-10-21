#include "./strlib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * tolowercase
 * Converts an uppercase character to its lowercase equivalent.
 * 
 * @param a The character to convert.
 * @return The lowercase version of the character if it is uppercase; 
 * Otherwise, returns the character unchanged.
 * 
 * Example: tolowercase('A') returns 'a', while tolowercase('1') returns '1'.
 */
static char tolowercase(char a)
{
    if (a >= 'A' && a <= 'Z') // if its a capital letter
    {
        char lowercase = a | 0x20; // 6th bit
        return lowercase;
    }
    return a;
}

/**
 * strcmp
 * Compares two strings lexicographically.
 *
 * @param a One string to compare.
 * @param b The other string to compare.
 * @return 1 if a > b, -1 if a < b, or 0 if a == b.
 * 
 * The comparison is based on the ASCII values of the characters.
 * The function processes each character until a difference is found
 * or the end of either string is reached.
 */
int str_cmp(const char *a, const char *b)
{

	// char array versions of a and b
	char newA[50];   
	str_cpy(newA, a);
	
	char newB[50];
	str_cpy(newB, b);
	
	// make first character lowercase
	newA[0] = tolowercase(newA[0]);
	newB[0] = tolowercase(newB[0]);
	
	
    	const unsigned char *ptrA = (const unsigned char *)newA; // ptr to char array a
    	const unsigned char *ptrB = (const unsigned char *)newB; // ptr to char array b

    	while (*ptrA && *ptrA == *ptrB){ 
    	// while they are equal and not done, go to the next element
    		++ptrA;
    		++ptrB;
    	}

	// return (boolean of A > B) minus (boolean of B > A)
	// if A>B, 1 - 0 = 1
	// if B>A, 0 - 1 = -1
	// if A=B, 0 - 0 = 0
    	return (*ptrA > *ptrB) - (*ptrB  > *ptrA); 
    	
}

/**
 * str_len
 * Calculates the length of a string.
 *
 * @param string The string whose length is to be determined.
 * @return The length of the string, excluding the null terminator.
 *
 * The function iterates through the string until it encounters the null terminator.
 */
int str_len(const char *string)
{
    int length = 0;
    
    for (int i = 0; *string != '\0'; i++) { // until ptr at empty (wont count \0)
        length++;  // add length
        string++;  // move ptr
    }
    
    return length;
}

/**
 * str_cpy
 * Copies a source string to a destination string.
 *
 * @param dest The destination string to which the source string will be copied.
 * @param src The source string to be copied.
 *
 * The function copies each character from the source string to the destination
 * string and appends a null terminator at the end.
 */
void str_cpy(char *dest, const char *src)
{
	while (*src != '\0') {  // while not at end
        	*dest = *src;  // copy char from src to dest
        	dest++;  // move pointers forward
        	src++;
    	}
    	*dest = '\0'; // add empty char at the end
}

/**
 * strdup
 * Duplicates a string by allocating memory and copying its content.
 *
 * @param input The string to be duplicated.
 * @return A pointer to the newly allocated duplicate string.
 *
 * The function first calculates the length of the input string, then allocates
 * memory for the new string (including space for the null terminator),
 * and finally copies the input string into the allocated memory.
 */
char *strdup(const char *input)
{
	 
	char *str; // --> new string
	char *pStr; // --> pointer to put stuff in new string w/o losing it
	int length = str_len(input);

	str = malloc(length + 1); // space for new string, +1 for the \0
	pStr = str; // pStr pointing to beginning of str
	
	while (*input){  // while string to copy is not at end
		*pStr = *input; // copy char in input to char in pStr
		// move pointers to next
		pStr++;
		input++;
	}
	*pStr = '\0'; // put \0 as the last char
	
	return str;
	
}
