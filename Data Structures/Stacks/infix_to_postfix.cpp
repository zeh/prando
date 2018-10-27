#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int top;
    int capacity;
    int *arr;
};
Stack* createStack(unsigned int capacity)
{
    Stack *stack = new Stack;
    if(!stack)
    return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = new int[stack->capacity];
    if(!stack->arr)
    return NULL;
    return stack;
}
int isEmpty(Stack* stack)
{
    return stack->top == -1;
}
char peek(Stack* stack)
{
    return stack->arr[stack->top];
}
char pop(Stack* stack)
{
    if(!isEmpty(stack))
    return stack->arr[stack->top--];
    return '$';
}
void push(Stack *stack, char op)
{
    stack->arr[++stack->top] = op;
}
int size(Stack* stack)
{
    return stack->top + 1;
}
int isOperand(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
int Prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return -1;
    }
}
string infixToPostfix(string exp)
{
    int i,k;
    Stack* stack = createStack(exp.length());
    if(!stack)
    return NULL;
    for(i=0,k=-1;exp[i];++i)
    {
        if(isOperand(exp[i]))
        exp[++k] = exp[i];
        else
        if(exp[i]=='(')
        push(stack,exp[i]);
        else
        if(exp[i]==')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL;         
            else
                pop(stack);
        }
        else
        {
            while(!isEmpty(stack) && Prec(exp[i] <= Prec(peek(stack))))
            exp[++k] = pop(stack);
            push(stack,exp[i]);
        }
    }
    while(!isEmpty(stack))
        exp[++k] = pop(stack);
    return exp;
}
int main()
{
    Stack* stack = createStack(10);
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(exp);
    return 0;
}