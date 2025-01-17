#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char title[32];
    char author[32];
    int id;
    float price;
} book_t;

struct _node_s
{
    struct _node_s * prev;
    book_t book;
    struct _node_s * next;
};

typedef struct _node_s node_t;

typedef enum {
    LIST_SUCCESS,
    LIST_ID_EXISTS,
    LIST_EMPTY,
    LIST_ITEM_DELETED,
    LIST_ITEM_NOT_FOUND
} ListStatus;

node_t* list_init();
ListStatus list_add_item(node_t** node, book_t* book);
ListStatus list_display_all(node_t* node);
ListStatus list_delete_item(node_t** node, int id);
node_t* list_search(node_t* node, int id);

#endif