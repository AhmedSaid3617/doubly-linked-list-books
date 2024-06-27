#include "main.h"

book_t input_book;
node_t *head;

char password[MAX_NAME_LENGTH];
char password[MAX_NAME_LENGTH];
char triedPassword[MAX_NAME_LENGTH]; // Input password to compare every time.

int main()
{
    head = list_init();
    char choice;

    printf("----------------------------------------------------- Welcome to your library -----------------------------------------------------\n\n\n");

    setPassword();

    while (1)
    {
        printf("Choose (1) to add a book.\n");
        printf("Choose (2) to delete a book.\n");
        printf("Choose (3) to view books in the system.\n");
        printf("Choose (4) to close the program.\n");
        printf("Your choice is: ");
        scanf("%d", &choice);
        if (checkPassword() == PASSWORD_INCORRECT)
        {
            continue;
        }
        
        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            deleteBook();
            break;

        case 3:
            viewBooks();
            break;

        case 4:
            return 0;

        default:
            printf("Enter a Valid choice!\n\n");
        }
    }

    return 0;
}

void addBook()
{
    printf("************************\n");
    printf("Enter book name: ");
    getchar();
    gets(&input_book.title);

    printf("Enter author name: ");
    gets(&input_book.author);

    printf("Enter book id: ");
    scanf("%d", &input_book.id);

    while (list_search(head, input_book.id) != NULL || input_book.id == 0)
    {
        if (list_search(head, input_book.id) != NULL)
        {
            printf("ID already exists, please enter another one.\n");
        }
        else if (input_book.id == 0)
        {
            printf("ID cannot be 0, please enter another one.\n");
        }

        printf("Enter book id: ");
        scanf("%d", &input_book.id);
    }

    printf("Enter book price: ");
    scanf("%f", &input_book.price);
    printf("\n");

    list_add_item(&head, &input_book);
    printf("************************\n");
}

void viewBooks()
{
    printf("************************\n");
    if (list_display_all(head) == LIST_EMPTY)
    {
        printf("The list is empty.\n");
    }
    printf("************************\n");
}

void deleteBook()
{
    int bookId;
    ListStatus status;

    printf("************************\n");
    printf("Enter book id to delete: ");
    scanf("%d", &bookId);
    status = list_delete_item(&head, bookId);
    if (status == LIST_ITEM_NOT_FOUND)
    {
        printf("No book with this id.\n");
    }
    else if (status == LIST_EMPTY)
    {
        printf("The list is empty.\n");
    }
    else
    {
        printf("Deleted successfully.\n");
    }
    printf("************************\n");
}

void setPassword()
{
    printf("Create your password:\n");
    scanf("%s", password);
    printf("Your password is %s\n", password);
}

// Checks if input password is the same as the one in password.
PasswordStatus checkPassword()
{
    printf("Enter password: \n");
    scanf("%s", triedPassword);
    if (strcmp(triedPassword, password))
    {
        printf("Wrong password.\n");
        return PASSWORD_INCORRECT;
    }

    /* for (int i = 0; i < MAX_NAME_LENGTH; i++)
    {
        if (triedPassword[i] != password[i])
        {
            printf("Wrong password.\n");
            return PASSWORD_INCORRECT;
        }
    } */
    return PASSWORD_CORRECT;
}