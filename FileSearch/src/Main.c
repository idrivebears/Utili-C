/*
 * Main.c
 *
 *  Created on: Oct 20, 2014
 *      Author: awalls
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 64

typedef int boolean;
#define true 1;
#define false 0;

struct Node{
	char word[MAX_WORD_SIZE];
	struct Node *nextNode;
	struct Node *priorNode;
};

struct Container{
	struct Node lastElement;
};

/*Returns the number of lines in formatted file
 * This function is used to calculate the hashtable size
 * */
size_t getNumberOfLinesInFile(char *fileName){
	FILE *file = fopen(fileName, "r");
	size_t lines = 0;
	int ch = 0;

	do{
		ch = fgetc(file);
		if(ch == '\n'){
			lines++;
		}
	} while(ch != EOF);

	fclose(file);
	return lines;
}

/*Makes sure character isnt ( ) , . : ; " ', etc
 * Fix: find more elegant way of doing this
 * */
boolean ignorableCharacter(char c){
	if (c == '(' ||c == ')' ||c == '.' ||c == ',' ||c == ':' ||c == ';' ||c == '[' ||c == ']' ||c == '/' ||c == '!' ||c == '?' ||c == '\"' ||c == '\'' ||c == '/' ||c == '-' ||c == '@') return true;
	return false;
}

/*Converts a normal text file into a list of words separated by '\n' characters*/
void convertFile(char *fileName){
	char ch;
	char fullFileName[64];
	strcpy(fullFileName, "new_");
	strcat(fullFileName, fileName);

	FILE *inputFile;
	FILE *outputFile;

	if(!fopen(fullFileName, "w")){
		printf("Error converting file: output file could not be opened.\n");
		return;
	}

	if(!fopen(fileName, "r+")){
		printf("Error converting file: input file could not be opened.\n");
		return;
	}

	do{
		ch = fgetc(inputFile);
		if(ch == ' '){
			fputc('\n', outputFile);
		}
		else if(!ignorableCharacter(ch)){
			//write char to file
			fputc(ch, outputFile);
		}

	} while(ch != EOF);

	fclose(inputFile);
	fclose(outputFile);
}

int main(){

	//printf("Indexing: %s ...\n", fileName);
	convertFile("test.txt");
	return 0;
}


