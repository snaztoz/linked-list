#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "list.h"




static Node* create(void)
{
    Node *node = (Node *) malloc(sizeof(Node));
    return node;
}


/* get the length of a list. 
 */
int length_of(Node* list)
{
    Node* temp;
    int count;

    temp = list;
    count = 0;

    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    return count;
}

/* search an element from the list. Return 1 if true,
   0 if not exist
 */
int is_exist(Node* list, int value)
{
    Node* temp = list;

    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

/* push new element to the front of a list 
 */
void push(Node** head, int value)
{
    Node *new_node = create();

    if (*head == NULL) {
        *head = new_node;
        (*head)->data = value;
        (*head)->next = NULL;
        return;
    }

    new_node->data = value;
    new_node->next = (*head);

    (*head) = new_node;
}

/* get element from the list at given index. Return
   the element
 */
int get(Node* list, int index)
{
    if (index < 0) {
        printf("Illegal index\n");
        exit(-1);
    }

    Node* temp;
    int count;

    temp = list;
    count = 0;

    while (temp != NULL) {
        if (count == index) {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }

    exit(-1);	// I'm confused how to return the proper error value
}

/* get element from the list at given index counted
   from the last element
 */
int get_b(Node* list, int index_b)
{
    int real_index = length_of(list) - index_b - 1;
    return get(list, real_index);
}

/* get the middle element of a list
*/
int get_middle(Node* list)
{
	if (list == NULL) {
		printf("Empty list\n");
		exit(-1);
	}

    Node *slow, *fast;
    slow = fast = list;

    while (fast != NULL) {
        if (fast->next != NULL) {
            fast = fast->next->next;
        }
        else {
            fast = fast->next;
            break;
        }
        slow = slow->next;
    }

    return slow->data;
}

/* free the allocated memories of a list 
 */
void destroy(Node* list)
{
    Node *target, *temp;
    
    target = list;

    while (target != NULL) {
        temp = target->next;
        free(target);
        target = temp;
    }
}

/* print all elements of a list 
 */
void show(Node* list)
{
    Node *temp;
    temp = list;

    printf("[");
    while (temp != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\b\b]\n");
}

/* delete node at given index. Return -1 if failed
 */
int delete_at(Node* list, int index)
{
    Node *temp, *target;
    int count;
    int data_buff;    // only used if the index is 0

    temp = list;
    count = 0;

    /* special case */
    if (index == 0) {
		// if the list is empty
		if (temp == NULL) {
			return -1;
		}
        // if the list contains only single element
        else if (temp->next == NULL) {
            free(temp);
        } 
        else {
            target = temp->next;

            // swapping the values of 0 and 1 index
            data_buff = target->data;
            target->data = temp->data;
            temp->data = data_buff;

            temp->next = target->next;
            free(target);
        }

        return 0;
    }

    while (count != index) {
		// index out of bound
        if (temp->next == NULL) {
            return -1;
        }

        /* temp will be the target element's previous node */
        count++;
        if (count == index)
            break;
        temp = temp->next;
    }

    target = temp->next;
    temp->next = target->next;
    free(target);

    return 0;
}

/* delete nodes after the first occurence of given key.
   Return -1 if error occured.
 */
int 
delete_after(Node* list, int key)
{
    Node *temp, *target;

    temp = list;

    while (temp->data != key) {
        if (temp->next == NULL) {
            return -1;
        }
        temp = temp->next;
    }

    target = temp->next;

    if (target == NULL) {
        return -1;
    }
    temp->next = target->next;
    free(target);

    return 0;
}
