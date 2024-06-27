#include "doubly_linked_list.h"

/**
 * @brief - Allocate memory for the first node in a doubly-linked list and return its address.
 */
node_t *list_init()
{
    return (node_t *)malloc(sizeof(node_t));
}

list_status list_add_item(node_t **node, book_t *book)
{
    node_t *prev_node = NULL;
    node_t *next_node = NULL;

    if ((*node)->book.id == 0)
    {
        (*node)->book = (*book);
        return LIST_SUCCESS;
    }

    while (1)
    {
        // Insert in the middle
        if ((*node)->book.id >= book->id)
        {

            prev_node = (*node)->prev;
            next_node = (*node);

            (*node) = (node_t *)malloc(sizeof(node_t)); // Set node to the new node.

            (*node)->prev = prev_node;
            if (prev_node != NULL)
            {
                prev_node->next = (*node);
            }

            (*node)->next = next_node;
            next_node->prev = (*node);

            (*node)->book = (*book);
            return LIST_SUCCESS;
        }
        // Insert at the end.
        else if ((*node)->next == NULL)
        {
            (*node)->next = (node_t *)malloc(sizeof(node_t));
            (*node)->next->prev = (*node);
            (*node)->next->book = (*book);
            return LIST_SUCCESS;
        }
        (*node) = (*node)->next;
    }
}

list_status list_display_all(node_t *node)
{

    if (node->book.id == 0)
    {
        return LIST_EMPTY;
    }

    while (1)
    {
        printf("==================\n");
        printf("Name: %s\n", node->book.title);
        printf("Author: %s\n", node->book.author);
        printf("Id: %d\n", node->book.id);
        printf("Price: %f\n", node->book.price);
        if (node->next != NULL)
        {
            node = node->next;
        }
        else
        {
            break;
        }
    }

    return LIST_SUCCESS;
}
