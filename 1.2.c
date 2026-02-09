#include <stdio.h>
#include <string.h>

#define MAX 50

struct Book
{
    int id;
    char title[50];
    char author[50];
    int copies;
};

struct Book library[MAX];
int count = 0;

void addBook();
void issueBook();
void returnBook();
void displayBooks();

int main()
{
    int choice;

    do {
        printf("\n--- Library Management System (C) ---\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: displayBooks(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}

void addBook()
{
    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Title: ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", library[count].author);

    printf("Enter Copies: ");
    scanf("%d", &library[count].copies);

    count++;
    printf("Book added successfully!\n");
}

void issueBook()
{
    int id, i;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(library[i].id == id)
         {
            if(library[i].copies > 0)
            {
                library[i].copies--;
                printf("Book issued successfully!\n");
            } else
            {
                printf("No copies available!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}

void returnBook()
{
    int id, i;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(library[i].id == id)
        {
            library[i].copies++;
            printf("Book returned successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void displayBooks()
{
    int i;
    printf("\nID\tTitle\tAuthor\tCopies\n");
    for(i = 0; i < count; i++)
    {
        printf("%d\t%s\t%s\t%d\n",
            library[i].id,
            library[i].title,
            library[i].author,
            library[i].copies);
    }
}
