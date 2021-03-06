#ifndef TREES_H_
#define TREES_H_

struct Node{
	//char word[50];
	int key;
	struct Node *right;
	struct Node *left;
};

void delete_tree(struct Node *node);
void print_tree(struct Node *tree);
int size(struct Node *tree);
void search_tree(int search_item, struct Node *tree);
void insert(int key, struct Node **tree);

#endif /* TREES_H_ */