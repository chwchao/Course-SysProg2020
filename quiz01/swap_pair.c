#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    // assert(new_node);
    while (*indirect) {
        indirect = &(*indirect)->next;
    }
    *indirect = new_node;
}

/* NEW VERSION OF SWAP_PAIR */
void swap_pair(node_t **head)
{
    for(node_t **node = head; *node && (*node)->next; node = &(*node)->next->next) {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
    return;
}

/* ORDINARY VERSION OF SWAP_PAIR */
/*
node_t *swap_pair(node_t *head)
{
    for (node_t **node = &head; *node && (*node)->next; node = &(*node)->next->next) {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
    return head;
}
*/

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next) {
        printf("%d ", current->value);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    node_t *head = NULL;

    add_entry(&head, 72);
    add_entry(&head, 101);
    add_entry(&head, 108);
    add_entry(&head, 109);
    add_entry(&head, 110);
    add_entry(&head, 111);

    printf("Original list:\n");
    print_list(head);

    swap_pair(&head);

    printf("Swapped list:\n");
    print_list(head);

    return 0;
}
