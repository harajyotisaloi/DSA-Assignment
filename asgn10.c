// Write a program to create a circular linked list and insert / delete an element at any position. 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create();
void insertAtBeginning();
void insertAtEnd();
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
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        i++;
    }
}

void insertAtBeginning()
{
    int x;
    struct node *newNode, *temp;
    printf("\nEnter item to insert at beginning:\n");
    scanf("%d", &x);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = newNode;
    }
}

void insertAtEnd()
{
    int x;
    struct node *newNode;
    printf("\nEnter item to insert at end: \n");
    scanf("%d", &x);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = head;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        struct node *temp = head, *prevNode = NULL;
        while (temp->next != head)
        {
            prevNode = temp;
            temp = temp->next;
        }

        if (prevNode == NULL)
        {
            printf("\nDeleted data is = %d\n", temp->data);
            head = NULL;
            free(temp);
        }
        else
        {
            printf("\nDeleted data is = %d\n", temp->data);
            prevNode->next = head;
            free(temp);
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
        while (temp->next != head)
        {
            temp = temp->next;
        }

        if (head == temp)
        {
            printf("\nDeleted data is = %d\n", temp->data);
            head = NULL;
            free(temp);
        }
        else
        {
            temp->next = head->next;
            printf("\nDeleted data is = %d\n", head->data);
            free(head);
            head = temp->next;
        }
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
        printf("\nCircular List elements: \n");
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("Head\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("Menu: \n");
        printf("1. Create Circular List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("\nEnter Choice\n");
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
            deleteAtEnd();
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            display();
            break;
        case 7:
            printf("\nExiting...");

        default:
            printf("\nInvalid Choice");
        }

    } while (choice != 7);

    return 0;
}