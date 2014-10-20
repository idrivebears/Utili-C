/*
 * Vector.h
 *
 *  Created on: Oct 20, 2014
 *      Author: Cam
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#define INITIAL_VECTOR_SIZE 10
#define GROWTH_MOD 2

typedef struct vector0 Vector;
struct vector0{
	int usedSize;
	int maxSize;
	int* data;
};

int vAdd(Vector* vector, int newElement);
int vEdit(Vector* vector, int index, int newValue);
int vSizeof(Vector* vector);
int* vMax(Vector* vector);
int* vMin(Vector* vector);
Vector* newVector();
Vector* vClone(Vector* vector);
Vector* vCloneTo(Vector* vector, int limit);
Vector* vCloneToFrom(Vector* vector, int start, int end);
Vector* vReverse(Vector* vector);
Vector* vConcat(Vector* a, Vector* b);
Vector* vDestroy(Vector* vector);
void vDisplay(Vector* vector);

#endif /* VECTOR_H_ */
