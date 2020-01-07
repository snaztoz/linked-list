#ifndef LINKED_LIST_H
#define LINKED_LIST_H



typedef struct Node {
    int data;
    struct Node* next;
} Node;


int length_of(Node*);
int is_exist(Node*, int);
void push(Node**, int);
int get(Node*, int);
int get_b(Node*, int);
int get_middle(Node*);
void destroy(Node*);
int delete_at(Node*, int);
int delete_after(Node*, int);
void show(Node*);

#endif
