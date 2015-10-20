#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
node *creatingList();
display_rec(node *);
node_add(node **);
node_remove(node **);
int main()
{
    node *head;
    head = creatingList();
    display(head);
    node_add(&head);
    display(head);
    node_remove(&head);
    display(head);
    node_remove(&head);
    display(head);
    node_remove(&head);
    display(head);
    node_remove(&head);
    display(head);
}
node *creatingList()
{
    int e,i=0;
    node *head, *p;
    printf("How many elements to be entered?\n");
    scanf("%d",&e);

    for(i=0; i<e; i++)
    {
        if(i==0)
        {
            head = (node *)malloc(sizeof(node));
            p = head;
            p -> prev = NULL;
            p -> next = NULL;
        }
        else
        {
            p -> next = (node *)malloc(sizeof(node));
            (p -> next) -> prev = p;
            p = p -> next;
        }
        printf("%d. Element\n",i+1);
        printf("id: ");
        scanf("%d", &p->id);
    }
    p -> next = NULL;
    return head;
}
display(node *head)
{
    int i=1;
    node *p = head;
    if(p == NULL){

        printf("List is Empty\n");
    }
    else{
        printf("\nPrinted Data.....\n");
        while(p != NULL){

            printf("\n%d. Element\n",i);
            printf("\nid: %d", p->id);
            p = p->next;
            i++;
        }
    }
}
node_add(node **head){

    int no;
    node *p, *newnode;
    p = *head;
    printf("\nWhich id will be added from before?\n");
    printf("To add the final --000(Zero)--\n");
    scanf("%d",&no);
    newnode = (node *)malloc(sizeof(node *));
    printf("Enter the added data\n");
    printf("id: ");
    scanf("%d", &newnode->id);

    if(p -> id == no)
    {
        newnode -> next = p;
        p -> prev = newnode;
        *head = newnode;
    }
    else
    {
        while((p -> id != no) && (p -> next != NULL))
        {
            p = p -> next;
        }
        if(p -> id == no)
        {
            (p -> next) -> prev = newnode;
            newnode -> next = p -> next;
            p -> next = newnode;
            newnode -> prev = p;

        }
        else if(p -> next == NULL)
        {
            p -> next = newnode;
            newnode -> prev = p;
            newnode -> next = NULL;
        }
    }
}
node_remove(node **head){

    int no;
    node *p;
    p = *head;
    printf("\nWhich node will be deleted?\n");
    printf("\nPlease enter id: \n\n");
    scanf("%d",&no);

    if(p -> id == no)
    {
        (*head) = (*head) -> next;
        (*head) -> prev = NULL;
        free(p);
    }
    else
    {
        while((p -> id != no) && (p -> next != NULL))
        {
            p = p -> next;
        }
        if((p -> next == NULL) && (p -> id == no))
            {
                (p -> prev) -> next = NULL;
                free(p);
            }
        else if(p -> id == no){

            (p -> prev) -> next = p -> next;
             p -> prev = (p -> next) -> prev;
            free(p);
        }
        while(p != NULL)
        {
            p = p -> next;
        }
        if(p == NULL)
        {
            printf("\nNo data will be deleted!\n");
        }
    }
}
