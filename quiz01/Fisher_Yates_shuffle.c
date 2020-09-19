#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}

// Move kth node to the end of the linked list
void move_entry(node_t **head, int k)
{
    node_t **indirect = head;
    node_t *target = NULL;

    // Find the target node, if found, store & remove the node
    while(*indirect)
    {        
        k--;
        if(k == 0)
        {
            target = *indirect;
            *indirect = (*indirect)->next;
            target->next = NULL;
        }
        if(*indirect) indirect = &(*indirect)->next;
    }
    
    // Add node to end of the list
    *indirect = target;
    return;
}

// Get length of a list
int get_length(node_t *head)
{
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

// Fisher-Yates shuffle
void Fisher_Yates_shuffle(node_t **head)
{
    srand(time(NULL));
    for(int left = get_length(*head); left > 0; left--)
        move_entry(head, rand() % left + 1);
    return;
}

int main(int argc, char const *argv[])
{
    node_t *head = NULL;

    add_entry(&head, 1);
    add_entry(&head, 2);
    add_entry(&head, 3);
    add_entry(&head, 4);
    add_entry(&head, 5);
    add_entry(&head, 6);
    add_entry(&head, 7);
    add_entry(&head, 8);
    add_entry(&head, 9);

    printf("Original list:\n");
    print_list(head);

    Fisher_Yates_shuffle(&head);

    printf("Shffled list:\n");
    print_list(head);

    return 0;
}
