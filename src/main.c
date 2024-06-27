#include <stdio.h>
#include <string.h>

#include "doubly_linked_list.h"

book_t book1;

int main(){
    strcpy(book1.author, "George Orwell");
    strcpy(book1.title, "1984");
    book1.id = 3;
    book1.price = 40.0;

    node_t* head = list_init();
    list_add_item(&head, &book1);

    book1.id = 1;
    list_add_item(&head, &book1);

    book1.id = 2;
    list_add_item(&head, &book1);

    list_delete_item(&head, 10);

    list_display_all(head);
    printf("///////////////////////////////////////////\n");

    return 0;
}