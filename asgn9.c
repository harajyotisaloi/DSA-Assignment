// Write a program to create a doubly linked list and delete an element from a given position

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

void deleteAtEnd();
void deleteAtBeginning();
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

void deleteAtEnd()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp = head;
        if (temp->next == NULL)
        {
            printf("\nDeleted Data is = %d", temp->data);
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            printf("\nDeleted Data = %d", temp->next->data);
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        printf("\nDeleted Data = %d", temp->data);
        free(temp);
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
        printf("2. Delete at End\n");
        printf("3. Delete at Beginning\n");
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
            deleteAtEnd();
            break;
        case 3:
            deleteAtBeginning();
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