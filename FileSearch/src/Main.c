/*
 * Main.c
 *
 *  Created on: Oct 20, 2014
 *      Author: awalls
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandler.h"

#define MAX_WORD_SIZE 64

#define true 1
#define false 0

typedef int boolean;

struct Node{
	char word[MAX_WORD_SIZE];
	struct Node *nextNode;
	struct Node *priorNode;
};

struct Container{
	struct Node *firstElement;
	struct Node *lastElement;
};

int main(){

	struct Container hashTable[getNumberOfLinesInFile("words.txt")];
	printf("%d", getNumberOfLinesInFile("wordsEn.txt"));


	reverseConvertFile("wordsEn.txt");
	return 0;
}


