// Implement binary search and linear search algorithms on arrays. 
#include <stdio.h>

#define SIZE 10

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key)
{
    int beg, mid, end;

    beg = 0;
    end = size - 1;
    mid = (beg + end) / 2;

    while (beg <= end && arr[mid] != key)
    {
        if (key < arr[mid])
            end = mid - 1;
        if (key > arr[mid])
            beg = mid + 1;
        mid = (beg + end) / 2;
    }

    if (arr[mid] == key)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[SIZE], n, key, choice, result;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements for the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n1.Linear Search \n2.Binary Search \n3.Exit\n");

    do
    {
        printf("\nChoose the method for searching the element: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element to search: ");
            scanf("%d", &key);
            result = linearSearch(arr, n, key);
            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found in the array.\n");
            break;

        case 2:
            printf("\nEnter the element to search: ");
            scanf("%d", &key);
            result = binarySearch(arr, n, key);
            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found in the array.\n");
            break;
        case 3:
            printf("\nTerminating program...\n");
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    } while (choice != 3);

    return 0;
}