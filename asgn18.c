// Write a program to implement a circular queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int underflow()
{
    return (front == NULL);
}

void enqueue()
{
    int x;
    printf("Enter item to enqueue: ");
    scanf("%d", &x);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("\nMemory allocation failure");
        return;
    }

    newNode->data = x;
    if (front == NULL)
    {
        front = rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("\nItem enqueued successfully\n");
}

void dequeue()
{
    if (underflow())
    {
        printf("\nQueue underflow");
    }
    else
    {
        struct node *temp = front;

        printf("\nDeleted item = %d\n", front->data);
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
        free(temp);
    }
}

void display()
{
    if (underflow())
    {
        printf("\nQueue is empty");
    }
    else
    {
        struct node *temp = front;

        printf("\nThe Queue is: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
    }
}

int main()
{
    int choice;
    printf("Menu\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n");
    printf("4. Exit\n");

    do
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (choice != 4);

    return 0;
}