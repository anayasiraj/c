#include<stdio.h>
#include<stdlib.h>
#include "./strlib.h"
/**
 * Test client
 * @brief This code is meant for the autograder. Do not touch this
 * @param argc, number of arguments
 * @param argv[0], string a
 * @param argv[1], string b
 * @param argv[2], String we're trying to find the length of
 * @param argv[4], for testing strdup
 * 
 * @details to compile: make testclient
 */
int main(int argc, char** argv)
{
    char* a = argv[1];
    char* b = argv[2];
    if(str_cmp(a,b) == 1){
        printf("a > b\n");
    } else if(str_cmp(a,b) == -1){
        printf("a < b\n");
    } else{
        printf("a == b\n");
    }
    //getting length of argument one!
    printf("%d\n",str_len(argv[3]));
    char* bing = strdup(argv[4]);
    printf("%s\n",bing);
    free(bing);
    return 0;
}
