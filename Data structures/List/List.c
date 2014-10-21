/*
 * List.c
 *
 *  Created on: Oct 20, 2014
 *      Author: Cam
 */

#include <List.h>
#include <Node.h>
#include <stdlib.h>
#include <string.h>

struct list0{
	int elements;
	char dataType[10];
	Node* head;
};

char* lType(List* list){
	return list->dataType;
}
int lSize(List* list){
	return list->elements;
}
int lContains(List* list, Node* node){
	return 0;
}
int lAdd(List* list, Node* node){
	return 0;
}
int lSet(List* list, Node* node){
	return 0;
}
int lIndexOf(List* list, Node* node){
	return 0;
}
Node* lRemove(List* list, Node* node){
	return NULL;
}
Node* lGet(List* list, Node* node){
	return NULL;
}
List* newList(char* dataType){
	List* l = (List*)(malloc(sizeof(List)));
	if(strlen(dataType)>= 10)return NULL; //list could not be initiated
	strcpy(l->dataType, dataType);
	l->elements = 0;
	l->head = NULL;
	return l;
}
List* lDestroy(List* list){
	return NULL;
}
List* lClone(List* list){
	return NULL;
}
List* lCloneTo(List* list, int limit){
	return NULL;
}
List* lCloneToFrom(List* list, int start, int end){
	return NULL;
}
List* lReverse(List* list){
	return NULL;
}
List* lConcat(List* a, List*b){
	return NULL;
}
