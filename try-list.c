#include <stdio.h>
#include <stdint.h>
#include "list.h"



int main()
{
    Node *list = NULL;

    push(&list, 10);
    push(&list, 13);
    push(&list, 53);
    push(&list, 32);
    push(&list, 14);
    push(&list, 20);
    show(list);

    printf("%d\n", get_middle(list));
    

    destroy(list);
    return 0;
}
