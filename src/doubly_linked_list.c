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
    node_t *traversing_node = NULL;
    node_t *next_node = NULL;

    // In case of empty list.
    if ((*node)->book.id == 0)
    {
        (*node)->book = (*book);
        return LIST_SUCCESS;
    }
    // Insert at the top.
    else if ((*node)->book.id >= book->id)
    {
        next_node = (*node);
        (*node) = (node_t*)calloc(1, sizeof(node_t));
        (*node)->book = (*book);
        (*node)->next = next_node;

        next_node->prev = (*node);

        return LIST_SUCCESS;
    }
    
    traversing_node = (*node); // Start at the second node.
    while (1)
    {
        // If you're in the middle.
        if (traversing_node->book.id >= book->id)
        {
            next_node = traversing_node;       // Save this node
            prev_node = traversing_node->prev; // and the previous one.
            traversing_node = (node_t*)calloc(1, sizeof(node_t));
            traversing_node->book = *book;

            // Tie the new node with the previous one.
            traversing_node->prev = prev_node;
            prev_node->next = traversing_node;

            // Tie the new node with the next one.
            traversing_node->next = next_node;
            next_node->prev = traversing_node;

            return LIST_SUCCESS;
        }
        // If you've reached the end;
        else if (traversing_node->next == NULL)
        {
            prev_node = traversing_node;
            traversing_node = (node_t*)calloc(1, sizeof(node_t));
            traversing_node->book = *book;

            // Tie the new node with the previous one.
            traversing_node->prev = prev_node;
            prev_node->next = traversing_node;
            return LIST_SUCCESS;
        }
        

        traversing_node = traversing_node->next;  // Move to next node.
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
