// Write a program to implement a circular queue using array

#include <stdio.h>

#define SIZE 10

int overflow();
int underflow();
void enqueue();
void dequeue();
void display();

int arr[SIZE], front = -1, rear = -1;

int overflow() {
    if((front == 0 && rear == SIZE -1) || (front == rear + 1))
        return 1;
    else 
        return 0;
}

int underflow() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueue() {
    int x;
    if(overflow()) {
        printf("\nQueue Overflow");
    }
    else {
        printf("Enter item to enqueue: ");
        scanf("%d", &x);
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = x;
        printf("\nItem inserted succesfully");
    }
}

void dequeue() {
    if (underflow()) {
        printf("\nQueue underflow");
    }
    else {
        printf("\nDeleted item = %d", arr[front]);

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    int i;
    if (underflow()) {
        printf("\nQueue is empty");
    }
    else {
        printf("\nThe Queue is: ");
        if(front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", arr[i]);
            }
        }
        else {
            for (i = front; i <= SIZE; i++) {
                printf("%d ", arr[i]);
            }
        }
    }
}

int main() {
    int choice;
    printf("Menu\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n");
    printf("4. Exit\n");

    do {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("\nExiting...");
                    break;
            default: printf("\nInvalid Choice");
        }
    } while (choice != 4);
    return 0;
}