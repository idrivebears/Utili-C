/*
 * Vector.c
 *
 *  Created on: Oct 20, 2014
 *      Author: Cam
 */


#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

int vAdd(Vector* vector, int newElement){
	if(!(vector->data)){
		//the vector is empty, def init maxSize is 30
		vector->maxSize = INITIAL_VECTOR_SIZE;
		vector->data = (int*)(malloc(sizeof(int)*vector->maxSize));
		if(!vector->data)return -1; //memory could not be allocated properly
		*(vector->data) = newElement; //add new element
		vector->usedSize++; //ups the new element counter
		return 0;
	}
	if(vector->usedSize == vector->maxSize){
		//the vector ran out of space (dammit)
		vector->maxSize *= GROWTH_MOD; //size grow in a GROWTH manner
		vector->data = (int*)(realloc(vector->data, sizeof(int) * vector->maxSize)); //grow vector
		if(!vector->data)return -1; //memory could not be allocated properly
		*(vector->data+vector->usedSize) = newElement;
		vector->usedSize++;
		return 0;
	}
	//simple add
	*(vector->data+vector->usedSize) = newElement;
	vector->usedSize++;
	return 0;
}
int vEdit(Vector* vector, int index, int newValue){
	if(index < 0 || index >= vector->usedSize)return -1;
	*(vector->data+index) = newValue;
	return 0;
}
int vSizeof(Vector* vector){
	if(!vector)return -1;
	if(!vector->data) return sizeof(Vector);
	return sizeof(Vector) + sizeof(vector->data)*vector->maxSize;
}
int* vMax(Vector* v){
	if(!v)return NULL;
	if(!v->data) return NULL;
	int* max = (int*)(malloc(sizeof(int)));
	*max = *(v->data);
	int i;
	for(i = 0; i<v->usedSize;i++){
		if(*max < *(v->data+i))
			*max = *(v->data+i);
	}
	return max;
}
int* vMin(Vector* v){
	if(!v)return NULL;
	if(!v->data) return NULL;
	int* min = (int*)(malloc(sizeof(int)));
	*min = *(v->data);
	int i;
	for(i = 0; i<v->usedSize;i++){
		if(*min > *(v->data+i))
			*min = *(v->data+i);
	}
	return min;
}
Vector* newVector(){
	Vector* v = (Vector*)(malloc(sizeof(Vector)));
	v->data = NULL;
	v->usedSize = 0;
	v->maxSize = 0;
	return v;
}
Vector* vClone(Vector* vector){
	return vCloneToFrom(vector, 0, vector->usedSize-1);
}
Vector* vCloneTo(Vector* vector, int limit){
	return vCloneToFrom(vector, 0, limit);
}
Vector* vCloneToFrom(Vector* vector, int start, int end){
	if(!vector)return NULL;
	if(start<0 || start > vector->usedSize || end < start || end > vector->usedSize-1) return NULL;

	Vector* v = newVector();
	v->maxSize = (end-start)+1; //allocates at least one element
	v->usedSize = (end-start)+1; //uses at least one element
	v->data = (int*)(malloc(sizeof(int)*v->maxSize));
	int i, j;
	for(i=start, j=0; i<=end;i++, j++){
		*(v->data+j) = *(vector->data+i);
	}
	return v;
}
Vector* vReverse(Vector* vector){
	if(!vector)return NULL;
	if(!vector->data)return NULL;

	Vector* v = newVector();
	v->maxSize = vector->maxSize;
	v->usedSize = vector->usedSize;
	v->data = (int*)(malloc(sizeof(int)*v->maxSize));

	int i, j;
	for(i=0, j=v->usedSize-1; j >= 0; i++, j--){
		*(v->data+j) = *(vector->data+i);
	}
	return v;
}
Vector* vConcat(Vector* a, Vector* b){
	Vector* v = newVector();
	v->maxSize = (a->usedSize) + (b->usedSize);
	v->usedSize = v->maxSize;
	v->data = (int*)(malloc(sizeof(int)*v->maxSize));

	int i, j;
	for(i = 0; i<a->usedSize;i++){
		*(v->data+i) = *(a->data+i);
	}
	for(j=0; j<b->usedSize;j++, i++){
		*(v->data+i) = *(b->data+j);
	}
	return v;
}
Vector* vDestroy(Vector* vector){
	if(!vector)return NULL;
	vector->maxSize = 0;
	vector->usedSize = 0;
	free(vector->data); //free data
	vector->data = NULL;
	return NULL;
}
void vDisplay(Vector* vector){
	if(!vector)return;
	int i;
	printf("[");
	for(i = 0; i<vector->usedSize;i++){
		if(i+1 == vector->usedSize){
			printf("%d", *(vector->data+i)); //last element
		}else{
			printf("%d,", *(vector->data+i));
		}
	}
	printf("]\n");
}
