// Write a program to convert an infix expression into a postfix expression. 

#include <stdio.h>
#include <string.h>

#define size 10
#define true 1
#define false 0

int top = -1;
char stack[size];

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

void push(char x)
{
    if (!isfull())
    {
        top++;
        stack[top] = x;
    }
    else
    {
        printf("\nStack Overflow");
    }
}

char pop()
{
    if (!isempty())
    {
        return stack[top--];
    }
    else
    {
        printf("\nStack Underflow");
        return '\0';
    }
}

char peek()
{
    if (!isempty())
    {
        return stack[top];
    }
    else
    {
        return '\0';
    }
}

int Isalnum(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int IsOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (Isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (peek() != '(' && !isempty())
            {
                postfix[j++] = pop();
            }
            if (peek() == '(')
            {
                pop();
            }
            else
            {
                printf("\nMismatched parentheses");
                return;
            }
        }
        else if (IsOperator(c))
        {
            while (precedence(c) <= precedence(peek()) && !isempty())
            {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (!isempty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{
    char infixExp[] = "(2 + 3 * 5 + 10) * ((4 + 6) / 2)";
    char postfixExp[size];
    infixToPostfix(infixExp, postfixExp);
    if (postfixExp[0] != '\0')
    {
        printf("Postfix notation: %s\n", postfixExp);
    }
    return 0;
}