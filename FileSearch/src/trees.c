#include "trees.h"
#include <stdio.h>
#include <stdlib.h>


#define true 1
#define false 0
#define TREE_SIZE 100000

typedef int boolean;

void destroy_tree(struct Node *node){
	if (node != NULL){
		destroy_tree(node->right);
		destroy_tree(node->left);
		free(node);
	}
}

void print_tree(struct Node *tree){
	if (tree != NULL){
		printf("%d, ", tree->key);
		print_tree(tree->left);
		print_tree(tree->right);
	}
}

int size(struct Node *tree){
	if (tree != NULL){
		return (size(tree->left) + 1 + size(tree->right));
	}
	else return 0;
}


void search_tree(int search_item, struct Node *tree){
	if (tree != NULL){
		printf("Searching...\n");
		if (search_item == tree->key){
			printf("Item found.\n");
		}
		else if (search_item < tree->key){
			search_tree(search_item, tree->left);
		}
		else {
			search_tree(search_item, tree->right);
		}
	}
	else printf("Item not found.\n");
}

void insert(int key, struct Node **tree){

	if (*tree == NULL){
		*tree = (struct Node *)malloc(sizeof(struct Node));
		(*tree)->key = key;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else if (key < (*tree)->key){
		insert(key, &(*tree)->left);
	}
	else if (key > (*tree)->key){
		insert(key, &(*tree)->right);
	}
	
}