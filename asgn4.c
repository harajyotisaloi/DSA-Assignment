// Write a program to create a singly linked list and delete an element from any position of the linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create();
void deleteAtEnd();
void deleteAtBeginning();
void display();

void create()
{
    int n, x, i = 0;
    struct node *newNode, *temp;
    printf("\nHow many nodes: ");
    scanf("%d", &n);

    while (i < n)
    {
        printf("\nEnter data to insert: \n");
        scanf("%d", &x);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        i++;
    }
}

void deleteAtEnd()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head;
        if (temp->next == NULL)
        {
            printf("\nDeleted data is = %d\n", temp->data);
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            printf("\nDeleted data is = %d\n", temp->next->data);
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        printf("\nDeleted data is = %d\n", temp->data);
        free(temp);
    }
}

void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nList elements: \n");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf(" Null\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("Menu: \n");
        printf("1. Create\n");
        // printf("2. Insert at Beginning\n");
        // printf("3. Insert at End\n");
        printf("2. Delete at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nEnter Choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        // case 2:
        //     insertAtBeginning();
        //     break;
        // case 3:
        //     insertAtEnd();
        //     break;
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
            printf("\nExiting...");

        default:
            printf("\nInvalid Choice");
        }

    } while (choice != 5);

    return 0;
}