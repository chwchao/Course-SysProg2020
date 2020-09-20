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

    //assert(new_node);
    while (*indirect) {
        indirect = &(*indirect)->next;
    }
    *indirect = new_node;
}

node_t *rev_recursive_part(node_t *head)
{
    if(!head || !head->next) {
        return head;
    }
    node_t *new_head = rev_recursive_part(head->next);
    if(head->next) {
        head->next->next = head;
    }
    head->next = NULL;
    return new_head;
}

void rev_recursive(node_t **head)
{
    *head = rev_recursive_part(*head);
}

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

    rev_recursive(&head);

    printf("Reversed list:\n");
    print_list(head);

    return 0;
}
