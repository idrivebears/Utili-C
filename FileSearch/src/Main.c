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
	struct Node *firstElement;
	struct Node *lastElement;
};
/*
int main(){

	//printf("Indexing: %s ...\n", fileName);
	convertFile("test.txt");
	return 0;
}*/


