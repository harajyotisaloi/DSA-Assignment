// Write a program to evaluate a postfix expression using stack. 


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 100

int stack[SIZE], top = -1;

void push(int x)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int item = stack[top];
        top--;
        return item;
    }
}

int Evaluation(char Pe[])
{
    int i = 0, l, Operand1, Operand2, result;
    l = strlen(Pe) - 1;

    while (i <= l)
    {
        if (Pe[i] >= '0' && Pe[i] <= '9')
        {
            push(Pe[i] - '0');
        }
        else
        {
            Operand2 = pop();
            Operand1 = pop();

            switch (Pe[i])
            {
            case '+':
                result = Operand1 + Operand2;
                break;
            case '*':
                result = Operand1 * Operand2;
                break;
            case '/':
                result = Operand1 / Operand2;
                break;
            case '^':
                result = (int)pow(Operand1, Operand2);
                break;
            default:
                printf("Invalid Symbol\n");
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main()
{
    char Pe[SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", Pe);
    int result = Evaluation(Pe);
    printf("Result: %d\n", result);
    return 0;
}