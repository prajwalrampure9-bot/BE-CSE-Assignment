#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[30];
    char author[30];
    int available;   // 1 = Available, 0 = Issued
};

int main() {
    struct Book book[50], temp;
    int n = 0, choice, i, j, searchId;

    do {
        printf("\n--- LIBRARY RECORD SYSTEM ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &book[n].id);

                printf("Enter Book Name: ");
                scanf(" %[^\n]", book[n].name);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", book[n].author);

                book[n].available = 1;
                n++;
                printf("Book added successfully.\n");
                break;

            case 2:
                /* Nested loop to sort books by ID */
                for (i = 0; i < n - 1; i++) {
                    for (j = i + 1; j < n; j++) {
                        if (book[i].id > book[j].id) {
                            temp = book[i];
                            book[i] = book[j];
                            book[j] = temp;
                        }
                    }
                }

                printf("\nID\tBook Name\tAuthor\t\tStatus\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t%s\t%s\t%s\n",
                           book[i].id,
                           book[i].name,
                           book[i].author,
                           book[i].available ? "Available" : "Issued");
                }
                break;

            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);

                for (i = 0; i < n; i++) {
                    if (book[i].id == searchId) {
                        printf("Book Found: %s by %s\n",
                               book[i].name, book[i].author);
                        break;
                    }
                }

                if (i == n)
                    printf("Book not found.\n");
                break;

            case 4:
                printf("Enter Book ID to issue: ");
                scanf("%d", &searchId);

                for (i = 0; i < n; i++) {
                    if (book[i].id == searchId) {
                        if (book[i].available == 1) {
                            book[i].available = 0;
                            printf("Book issued successfully.\n");
                        } else {
                            printf("Book is already issued.\n");
                        }
                        break;
                    }
                }
                break;

            case 5:
                printf("Enter Book ID to return: ");
                scanf("%d", &searchId);

                for (i = 0; i < n; i++) {
                    if (book[i].id == searchId) {
                        book[i].available = 1;
                        printf("Book returned successfully.\n");
                        break;
                    }
                }
                break;

            case 6:
                printf("Thank you.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}