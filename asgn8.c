// Write a program to create a doubly linked list and insert an element at any position. 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

void create();
void insertAtBeginning();
void insertAtEnd();
void display();

void create()
{
    int n, x, i = 0;
    struct node *new, *temp;
    printf("\nHow many nodes?\n");
    scanf("%d", &n);

    while (i < n)
    {
        printf("\nEnter data to insert: ");
        scanf("%d", &x);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = x;
        new->prev = NULL;
        new->next = NULL;

        if (head == NULL)
        {
            head = new;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            new->prev = temp;
        }
        i++;
    }
}

void insertAtBeginning()
{
    struct node *temp;
    int x;
    printf("\nEnter item to insert at beginning: ");
    scanf("%d", &x);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;

    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtEnd()
{
    int x;
    struct node *new, *temp;
    printf("\nEnter item to insert at end: ");
    scanf("%d", &x);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;

    if (head == NULL)
    {
        new->prev = NULL;
        head = new;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nList elements: ");
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}