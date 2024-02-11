// count and search the number present in singly linked 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create();
void display();
int countElements();
int searchElement(int key);

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

int countElements()
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int searchElement(int key)
{
    int position = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        position++;
        if (temp->data == key)
        {
            return position;
        }
        temp = temp->next;
    }
    return -1;
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
    int choice, key, position;
    printf("Menu: \n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Count the number of elements\n");
    printf("4. Search for an element\n");
    printf("5. Exit\n");
    do
    {
        printf("\nEnter Choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nNumber of elements: %d\n", countElements());
            break;
        case 4:
            // int key, position;
            printf("\nEnter element to search: ");
            scanf("%d", &key);
            position = searchElement(key);
            if (position != -1)
                printf("\nElement found at position: %d\n", position);
            else
                printf("\nElement not found\n");
            break;
        case 5:
            printf("\nExiting...");
        default:
            printf("\nInvalid Choice");
        }

    } while (choice != 5);

    return 0;
}