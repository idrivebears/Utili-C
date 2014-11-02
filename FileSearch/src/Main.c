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
#include "trees.h"

#define true 1
#define false 0

typedef int boolean;

int main(){

	struct Node *wordTree = NULL;

	int i;
	srand(time(NULL));
	for(i = 0; i < 2000000; i++){
		insert(rand()%30000000, &wordTree);
	}

	printf("Size of tree: %d\n", size(wordTree));
	//print_tree(wordTree);
	//Quick testing interface for searching the tree
	
	int in = 0;
	while(in != -1){
		printf("\nSearch: ");
		scanf("%d", &in);
		search_tree(in, wordTree);
	}

	return 0;
}


