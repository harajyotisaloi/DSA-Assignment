// stack using array

#include <stdio.h>

#define size 10
#define true 1
#define false 0

void push();
void pop();
void display();
int isfull();
int isempty();

int top = -1;
int arr[size];

int isfull()
{
    if (top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isempty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push()
{
    int x;
    if (isfull())
    {
        printf("\n Stack Overflow");
    }
    else
    {
        printf("\nEnter item: ");
        scanf("%d", &x);

        top++;
        arr[top] = x;
        printf("\nItem Pushed Successfully");
    }
}

void pop()
{
    if (isempty())
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nDeleted item is = %d", arr[top]);
        top--;
    }
}

void display()
{
    if (isempty())
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack is: ");
        for (int i = top; i >= 0; i--)
        {
            printf("\n%d", arr[i]);
        }
    }
}

int main()
{
    int choice;
    printf("\n   MENU   ");
    printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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