/*
 * Node.c
 *
 *  Created on: Oct 20, 2014
 *      Author: Cam
 */
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node* newNode(){
	Node* n = (Node*)(malloc(sizeof(Node)));
	strcpy(n->dataType, "unassigned");
	n->aNode = NULL;
	n->bNode = NULL;
	n->data = NULL;
	return n;
}
int nLink(Node* root, Node* aNode, Node* bNode){
	if(!root)return -1;
	root->aNode = aNode;
	root->bNode = bNode;
	return 0;
}
int nSetType(Node* node, char* args){
	if(strlen(args) < strlen(node->dataType)){
		strcpy(node->dataType, args);
		return 0;
	}
	return -1;
}
int nSetData(Node* node, void* data, char* dataType){
	if(!data || !dataType)return -1;
	node->data = data;
	nSetType(node, dataType);
	return 0;
}


