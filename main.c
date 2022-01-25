#include <stdio.h>
#include <stdlib.h>
struct node {
        struct node *nxt;
        int item;
    };

void printNode(struct node *head)
{
    while(head!= NULL)
    {
        printf("%d \n",head->item);
        head = head->nxt;
    }

}
void insertNode (int position ,int item, struct node **ptrtohead)
{
    int i;
    struct node *head = (*ptrtohead), *temp ;
    temp = malloc(sizeof(struct node));
    temp->item = item;
    if (position < 0 ) return;
    if (position == 0 )
    {
        temp->nxt = head;
        *ptrtohead = temp;
    }
    else
    {
        for ( i=1 ; i<position;i++)
        {
            head = head->nxt;
        }
        temp->nxt = head->nxt;
        head->nxt = temp;
    }
}

int main()
{

    struct node *head= NULL, *temp, *constanthead;
    int n ;
    int i ;
    int item;
    struct node **ptrtohead = &head;
    scanf("%d", &n);
    getchar();
    for ( i=0; i<n; i++)
    {

        if (i==0){
            head = malloc(sizeof(struct node));
            constanthead = head;
        }
        else{
            temp = malloc(sizeof(struct node));
            head->nxt= temp;
            head = temp;
        }
        scanf("%d",&item);
        getchar();
        head->item = item;
        head->nxt = NULL;
    }
    printNode(constanthead);
    insertNode(0,10,ptrtohead);
    printNode(constanthead);

}


