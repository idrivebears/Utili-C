/*
 * Node.h
 *
 *  Created on: Oct 20, 2014
 *      Author: Cam
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct node0 Node;

struct node0{
	char dataType[10];
	void* data;
	Node* aNode;
	Node* bNode;
};

Node* newNode();
int nLink(Node* root, Node* aNode, Node* bNode);
int nSetType(Node* node, char* args);
int nSetData(Node* node, void* data, char* dataType);

#endif /* NODE_H_ */
