// stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push();
void pop();
void display();

void push()
{
    int x;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("\nStack Overflow");
        return;
    }

    printf("\nEnter item: ");
    scanf("%d", &x);

    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("\nItem Pushed Successfully");
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow");
        return;
    }

    struct node *temp = top;
    printf("\nDeleted item is = %d", temp->data);
    top = top->next;
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    printf("\nStack is: ");
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
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