// Write a program to implement a queue using array. 

#include <stdio.h>

#define size 10
#define true 1
#define false 0

void enqueue();
void dequeue();
void display();
int overflow();
int underflow();

int front = -1;
int rear = -1;
int arr[size];

int overflow()
{
    if (rear == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int underflow()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue()
{
    int x;
    if (overflow())
    {
        printf("\nQueue Overflow");
    }
    else
    {
        printf("\nEnter item to Enqueue: ");
        scanf("%d", &x);
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
        printf("\nEnqueue is successful\n");
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nDequeued item: %d", arr[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        printf("\nDequeue is successful\n");
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nCurrent elements in the queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int choice;
    printf("\nMenu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit");
    
    do
    {
        printf("\nEnter Choice: ");
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