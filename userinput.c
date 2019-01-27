#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//input shouldn't be longer than 1024 characters
#define MAX 1024

int main(){
	//Open file with strings
	FILE * letter;
	letter = fopen("letter.txt", "r");
	//declare and initialize n
	int n = 0;
	//prompts user for input
	printf("Enter a number for n: ");
	//read what the user types in: %i is an integer variable from an console 
	//also it reads it into a variable &n
	scanf("%i", &n);
	//declare a dynamically allocated array using malloc which
	//allocates the specific number of bytes
	//to store the strings
	//Allocate a memory of n bytes on the heap
	char * array = (char*)malloc(sizeof(char));	
	//array = (char*)malloc(n*sizeof(char));
	//reading in the file with fgets()
	//char *fgets(char *str, int n, FILE *stream) 
	//safe because it checks array bounds
	int i;
	fgets(array, n, letter);
	//gets rid of the \n fgets produces
	//size_t is an unsigned int type
	//find the last value and replaces it 
	size_t len = strlen(array)-1;
	if(array[len] == '\n')
		array[len] = '\0';
		
	//print the array
	for(i = 0; i < n; i++){
		printf("%s", &array[i]);	
	}
	return 0;
}
