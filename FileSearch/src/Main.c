/*
 * Main.c
 *
 *  Created on: Oct 20, 2014
 *      Author: gwAwr
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 64

size_t getNumberOfLinesInFile(char *fileName);

struct Node{
	char word[MAX_WORD_SIZE];
	struct Node *nextNode;
	struct Node *priorNode;
};

struct Container{
	struct Node lastElement;
};

size_t getNumberOfLinesInFile(char *fileName){
	FILE *file = fopen(fileName, "r");
	size_t lines = 0;
	int ch = 0;

	do{
		ch = fgetc(file);
		if(ch == '\n'){
			lines++;
		}
	}while(ch != EOF);

	fclose(file);
	return lines;
}

void convertFile(char *fileName){
	FILE *inputFile = fopen(fileName, "r");
	FILE *outputFile = fopen(strcat("new_", fileName), "w");
	char *buffer;

	do{
		ch = fgetc(inputFile);
		if(ch == ' '){
			fwrite('\n', 1, outputFile);
		}

	}while(ch != EOF);

}





int main(){

	char *fileName = "words.txt";
	int lines;
	printf("Indexing: %s ...\n", fileName);
	scanf("%c");
	return 0;
}


