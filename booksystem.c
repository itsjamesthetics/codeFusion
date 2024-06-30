/*	
	Developed by: James Ald Teves
    BS Computer Science

	Instructor: Assit. Prof. Melody Angelique Rivera
	Program started: 09-29-22
	Program finished: 09-29-22
	
	Description: This program enables you to record, update, search, and delete list of book using Linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

// Define a structure for a book
typedef struct Book {
    char title[SIZE];
    char author[SIZE];
    int yearPublished;
    int price;
    struct Book *next;
} Book;

// Function prototypes
void menu();
Book *addBook(Book *head);
void displayBooks(Book *head);
void updateBook(Book *head);
Book *deleteBook(Book *head);
void searchBooks(Book *head);
void freeBooks(Book *head);

// Main function
int main() {
    Book *head = NULL;
    menu(&head);
    freeBooks(head); // Free memory before exiting
    return 0;
}

// Display menu and handle user choices
void menu(Book **head) {
    int choice;
    do {
        printf("\n1. Add Book");
        printf("\n2. View Books");
        printf("\n3. Update Book");
        printf("\n4. Delete Book");
        printf("\n5. Search Books");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // To capture the newline after number input

        switch (choice) {
            case 1:
                *head = addBook(*head);
                break;
            case 2:
                displayBooks(*head);
                break;
            case 3:
                updateBook(*head);
                break;
            case 4:
                *head = deleteBook(*head);
                break;
            case 5:
                searchBooks(*head);
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 6);
}

// Create a new book and add it to the list
Book *addBook(Book *head) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (!newBook) {
        printf("\nMemory allocation failed!\n");
        return head;
    }

    printf("\nEnter title: ");
    fgets(newBook->title, SIZE, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = 0; // Remove newline

    printf("Enter author: ");
    fgets(newBook->author, SIZE, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0; // Remove newline

    printf("Enter year published: ");
    scanf("%d", &newBook->yearPublished);
    getchar(); // To capture the newline

    printf("Enter price: ");
    scanf("%d", &newBook->price);
    getchar(); // To capture the newline

    newBook->next = head;
    return newBook;
}

// Display all books in the list
void displayBooks(Book *head) {
    Book *current = head;
    if (current == NULL) {
        printf("\nNo books to display.\n");
        return;
    }

    printf("\nBooks:\n");
    while (current != NULL) {
        printf("Title: %s, Author: %s, Year: %d, Price: %d\n", 
               current->title, current->author, current->yearPublished, current->price);
        current = current->next;
    }
}

// Update a book's details
void updateBook(Book *head) {
    if (head == NULL) {
        printf("\nNo books available to update.\n");
        return;
    }

    char title[SIZE];
    printf("\nEnter the title of the book to update: ");
    fgets(title, SIZE, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    Book *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Enter new author: ");
            fgets(current->author, SIZE, stdin);
            current->author[strcspn(current->author, "\n")] = 0;

            printf("Enter new year published: ");
            scanf("%d", &current->yearPublished);
            getchar();

            printf("Enter new price: ");
            scanf("%d", &current->price);
            getchar();

            printf("\nBook updated successfully!\n");
            return;
        }
        current = current->next;
    }

    printf("\nBook not found!\n");
}

// Delete a book from the list
Book *deleteBook(Book *head) {
    if (head == NULL) {
        printf("\nNo books available to delete.\n");
        return head;
    }

    char title[SIZE];
    printf("\nEnter the title of the book to delete: ");
    fgets(title, SIZE, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    Book *current = head;
    Book *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("\nBook deleted successfully!\n");
            return head;
        }
        previous = current;
        current = current->next;
    }

    printf("\nBook not found!\n");
    return head;
}

// Search for books by title
void searchBooks(Book *head) {
    if (head == NULL) {
        printf("\nNo books available to search.\n");
        return;
    }

    char title[SIZE];
    printf("\nEnter the title of the book to search for: ");
    fgets(title, SIZE, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    Book *current = head;
    while (current != NULL) {
        if (strstr(current->title, title) != NULL) {
            printf("Found: Title: %s, Author: %s, Year: %d, Price: %d\n",
                   current->title, current->author, current->yearPublished, current->price);
            return;
        }
        current = current->next;
    }

    printf("\nBook not found!\n");
}

// Free memory allocated for the books
void freeBooks(Book *head) {
    Book *current = head;
    while (current != NULL) {
        Book *next = current->next;
        free(current);
        current = next;
    }
}