#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int totalCopies;
    int availableCopies;
};

int main() {
    struct Book books[100];
    int n = 0, choice, id, i, found;

    do {
        printf("\n--- Library Book Management ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Book ID: ");
            scanf("%d", &books[n].id);

            printf("Enter Title: ");
            scanf(" %[^\n]", books[n].title);

            printf("Enter Author: ");
            scanf(" %[^\n]", books[n].author);

            printf("Enter Total Copies: ");
            scanf("%d", &books[n].totalCopies);

            books[n].availableCopies = books[n].totalCopies;

            n++;

            printf("Book added successfully.\n");
        }

        else if (choice == 2) {
            printf("Enter Book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++) {
                if (books[i].id == id) {
                    printf("\nBook Found!\n");
                    printf("ID: %d\n", books[i].id);
                    printf("Title: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);
                    printf("Total Copies: %d\n", books[i].totalCopies);
                    printf("Available Copies: %d\n", books[i].availableCopies);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
        }

        else if (choice == 3) {
            printf("Enter Book ID to issue: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++) {
                if (books[i].id == id) {
                    found = 1;

                    if (books[i].availableCopies > 0) {
                        books[i].availableCopies--;
                        printf("Book issued successfully.\n");
                    } else {
                        printf("Book is currently unavailable.\n");
                    }

                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
        }

        else if (choice == 4) {
            printf("Enter Book ID to return: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++) {
                if (books[i].id == id) {
                    found = 1;

                    if (books[i].availableCopies < books[i].totalCopies) {
                        books[i].availableCopies++;
                        printf("Book returned successfully.\n");
                    } else {
                        printf("All copies are already available.\n");
                    }

                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
        }

        else if (choice == 5) {
            printf("\n--- Currently Unavailable Books ---\n");

            found = 0;

            for (i = 0; i < n; i++) {
                if (books[i].availableCopies == 0) {
                    printf("ID: %d | Title: %s | Author: %s\n",
                           books[i].id, books[i].title, books[i].author);
                    found = 1;
                }
            }

            if (!found)
                printf("No books are currently unavailable.\n");
        }

        else if (choice == 6) {
            printf("Exiting program...\n");
        }

        else {
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
