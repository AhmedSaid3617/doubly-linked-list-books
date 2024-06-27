#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include "doubly_linked_list.h"

#define MAX_NAME_LENGTH 100

typedef enum {
    PASSWORD_INCORRECT,
    PASSWORD_CORRECT
} PasswordStatus;

void addBook();
void viewBooks();
void deleteBook();

void setPassword();
PasswordStatus checkPassword();

#endif