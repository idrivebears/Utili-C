/*
 * List.h
 *
 *  Created on: Oct 20, 2014
 *      Author: Cam
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct list0 List;
typedef struct node0 Node; //the default Node of Node.h

char* lType(List* list);
int lSize(List* list);
int lContains(List* list, Node* node);
int lAdd(List* list, Node* node);
int lSet(List* list, Node* node);
int lIndexOf(List* list, Node* node);
Node* lRemove(List* list, Node* node);
Node* lGet(List* list, Node* node);
List* newList(char* dataType);
List* lDestroy(List* list);
List* lClone(List* list);
List* lCloneTo(List* list, int limit);
List* lCloneToFrom(List* list, int start, int end);
List* lReverse(List* list);
List* lConcat(List* a, List*b);

#endif /* LIST_H_ */
