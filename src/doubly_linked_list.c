#include "doubly_linked_list.h"

/**
 * @brief - Allocate memory for the first node in a doubly-linked list and return its address.
 */
node_t *list_init()
{
    return (node_t *)calloc(1, sizeof(node_t));
}
/**
 * @brief - Add a book to the list and sort it based on its id.
 * @param node: The address to the pointer to the first node (head).
 * @param book: The address of the book_t object to add.
 */
ListStatus list_add_item(node_t **node, book_t *book)
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

/**
 * @brief - Display all the books in the list.
 */
ListStatus list_display_all(node_t *node)
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
    
    printf("==================\n");
    return LIST_SUCCESS;
}

/**
 * @brief - Delete a book from the list based on id.
 * @param node: The address to the pointer to the first node (head).
 * @param id: The id of the book to be deleted.
 */
ListStatus list_delete_item(node_t** node, int id){
    node_t* deleted_node = NULL;
    node_t *prev_node = NULL;
    node_t *traversing_node = NULL;
    node_t *next_node = NULL;

    if ((*node)->book.id == id)
    {
        deleted_node = *node;
        if (deleted_node->next != NULL)
        {
            (*node) = deleted_node->next;
            free(deleted_node);
        }
        else{
            deleted_node->book.id = 0;
        }
        
        return LIST_ITEM_DELETED;
    }
    
    traversing_node = *node;

    while (traversing_node != NULL)
    {
        if (traversing_node->book.id == id)
        {
            prev_node = traversing_node->prev;
            next_node = traversing_node->next;

            // Bypass the deleted node.
            prev_node->next = next_node;
            if (next_node != NULL)
            {
                next_node->prev = prev_node;
            }
            
            free(traversing_node);
            return LIST_ITEM_DELETED;
        }
        

        traversing_node = traversing_node->next;
    }
    
    return LIST_ITEM_NOT_FOUND;
}

node_t* list_search(node_t* node, int id){
    while (node != NULL)
    {
        if (node->book.id == id)
        {
            return node;
        }
        
        node = node->next;
    }
    return NULL;
}