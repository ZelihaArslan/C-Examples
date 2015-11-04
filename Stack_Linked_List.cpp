#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 10000
typedef enum { false ,true} boolean;

typedef struct
{
    char d;
    struct node *next;
}node;

typedef struct
{
    int cnt;
    node *top;
}stack;

boolean empty(const stack *stk);
boolean full(const stack *stk);
void initialize(stack *stk);
void push(char d, stack *stk);
char pop(stack *stk);
char top(stack *stk);
int main()
{
    char str[] = "Ebru Gulec";
    int i;
    stack s;
    initialize(&s);
    for(i=0; str[i] != '\0'; i++)
    {
        if(!full(&s))
        push(str[i], &s);
        }
        printf("String in the stack: \n");
        while(!empty(&s))
        {
            printf("%c",pop(&s));
        }

   return 0;
}
boolean empty(const stack *stk)
{
    return (stk -> cnt == EMPTY);
}
boolean full(const stack *stk)
{
    return (stk -> cnt == FULL);
}
void initialize(stack *stk)
{
    stk -> cnt = 0;
    stk -> top = NULL;
}
char top(stack *stk)
{
    return (stk -> top -> d);
}
void push(char d, stack *stk)
{
    node *p;
    p = malloc(sizeof(node));
    p -> d = d;
    p -> next = stk -> top;
    stk -> top = p;
    stk->cnt++;
}
char pop(stack *stk)
{
    char x;
    node *p;
    x = stk -> top -> d;
    p = stk -> top;
    stk -> top = stk -> top -> next;
    stk -> cnt--;
    free(p);
    return x;
}
