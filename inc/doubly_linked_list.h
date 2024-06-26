#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct
{
    char title[16];
    char author[16];
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

#endif