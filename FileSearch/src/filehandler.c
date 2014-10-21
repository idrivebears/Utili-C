/*
 * FileHandler.c
 *
 *  Created on: 20 Oct 2014
 *      Author: awalls
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 64

typedef int boolean;
#define true 1
#define false 0


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
	char *invalidCharacters = "()\n.,:;[]/!?\"'/-@";
	int i;
	for(i = 0; i < strlen(invalidCharacters); i++){
		if(c == invalidCharacters[i]){
			return true;
		}
	}
	return false;
}

/*Converts a normal text file into a list of words separated by '\n' characters 'word-per-line' format */
/*Needs tuning for some special cases*/
void convertFile(char *fileName){
	char ch;
	char fullFileName[64];
	//We make a new file name with new_xxxx.ext for the reorganized file
	strcpy(fullFileName, "new_");
	strcat(fullFileName, fileName);

	FILE *inputFile;
	FILE *outputFile;

	if(!(outputFile = fopen(fullFileName, "w"))){
		printf("Error converting file: output file could not be opened.\n");
	}

	else if(!(inputFile = fopen(fileName, "r+"))){
		printf("Error converting file: input file could not be opened.\n");
	}
	else{
		do{
			ch = fgetc(inputFile);
			if(ch == ' '){ //if its a space, print newline instead
				fputc('\n', outputFile);
			}
			else if(!ignorableCharacter(ch)){//if its not an ignorable character we write it to the files
				//write char to file
				fputc(ch, outputFile);
			}

		} while(ch != EOF);
	}

	fclose(inputFile);
	fclose(outputFile);
}
/*This function is just for testing purposes, will take a word-per-line formatted txt file and convert it to space-separated words txt file*/
void reverseConvertFile(char *fileName){
	char ch;
	char fullFileName[64];
	//We make a new file name with reversed_xxxx.ext for the reorganized file
	strcpy(fullFileName, "reversed_");
	strcat(fullFileName, fileName);

	FILE *inputFile;
	FILE *outputFile;

	if(!(outputFile = fopen(fullFileName, "w"))){
		printf("Error converting file: output file could not be opened.\n");
	}

	else if(!(inputFile = fopen(fileName, "r+"))){
		printf("Error converting file: input file could not be opened.\n");
	}
	else{
		do{
			ch = fgetc(inputFile);
			if(ch == '\n'){ //if its a space, print newline instead
				fputc(' ', outputFile);
			}
			else if(!ignorableCharacter(ch)){//if its not an ignorable character we write it to the files
				//write char to file
				fputc(ch, outputFile);
			}

		} while(ch != EOF);
	}

	fclose(inputFile);
	fclose(outputFile);
}

