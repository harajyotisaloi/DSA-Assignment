// Write a program to implement a queue using linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int);
void dequeue();
void display();

void enqueue(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        temp = front;
        front = front->next;
        printf("\nDequeued data is = %d\n", temp->data);
        free(temp);

        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

void display()
{
    struct node *temp = front;
    if (temp == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue elements: \n");
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
    int choice, value;

    printf("Menu: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    do
    {
        printf("\nEnter Choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting...");
        default:
            printf("\nInvalid Choice");
        }
    } while (choice != 4);

    return 0;
}