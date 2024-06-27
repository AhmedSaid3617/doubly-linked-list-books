#include <stdio.h>
#include <string.h>

#include "doubly_linked_list.h"

book_t book1;

int main(){
    strcpy(book1.author, "George Orwell");
    strcpy(book1.title, "1984");
    book1.id = 10;
    book1.price = 40.0;

    node_t* head = list_init();
    list_add_item(&head, &book1);

    book1.id = 3;
    list_add_item(&head, &book1);

    book1.id = 5;
    list_add_item(&head, &book1);

    list_display_all(head);

    return 0;
}