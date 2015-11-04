#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5
typedef struct
{
    int data[STACK_SIZE];
    int top;
}stack;
void reset(stack *s);
void push(stack *, int);
int pop(stack *);
int main(){

    stack n;
    int x, a;
    reset(&n);
    printf("Eklenecek veriyi giriniz: \n");
    scanf("%d",&x);
    push(&n, x);
    printf("\nSilinecek Veri\n");
    a = pop(&n);
    printf("%d",a);

    return 0;
}
void reset(stack *s)
{
    s -> top = -1;
}
void push(stack *a, int x)
{
    if(a -> top == STACK_SIZE-1)
    {
        printf("Overflow\n");
    }
    else
    {
        a -> top++;
        a -> data[a -> top] = x;
    }
}
int pop(stack *a)
{
    if(a -> top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int x = a -> data[a -> top];
        a -> top--;
        return x;
    }
}




