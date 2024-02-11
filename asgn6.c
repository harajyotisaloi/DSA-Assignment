// Write a function to concatenate two linked lists

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head1 = NULL, *head2 = NULL, *mergedHead = NULL;

void create(struct node **head);
void display(struct node *head);
void mergeLists(struct node *list1, struct node *list2);

void create(struct node **head)
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

        if (*head == NULL)
        {
            newNode->next = NULL;
            *head = newNode;
        }
        else
        {
            temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        i++;
    }
}

void display(struct node *head)
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

void mergeLists(struct node *list1, struct node *list2)
{
    struct node *temp1 = list1;
    struct node *temp2 = list2;
    mergedHead = NULL;
    struct node *tail = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->next = NULL;

        if (temp1->data <= temp2->data)
        {
            newNode->data = temp1->data;
            temp1 = temp1->next;
        }
        else
        {
            newNode->data = temp2->data;
            temp2 = temp2->next;
        }

        if (mergedHead == NULL)
        {
            mergedHead = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (temp1 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = temp1->data;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = temp2->data;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
        temp2 = temp2->next;
    }

    printf("\nLists merged successfully\n");
}

int main()
{
    int choice;
    printf("Menu: \n");
    printf("1. Create List 1\n2. Create List 2\n3. Merge Lists\n");
    printf("4. Display List 1\n5. Display List 2\n6. Display Merged List \n");
    printf("7. Exit");

    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create(&head1);
            break;
        case 2:
            create(&head2);
            break;
        case 3:
            mergeLists(head1, head2);
            break;
        case 4:
            display(head1);
            break;
        case 5:
            display(head2);
            break;
        case 6:
            display(mergedHead);
            break;
        case 7:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (choice != 7);

    return 0;
}