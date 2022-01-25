#include <stdio.h>
#include <stdlib.h>
struct node {
        struct node *nxt;
        int item;
    };

void printList(struct node* head) {
  while (head != NULL) {
    printf("%d -> ", head->item);
    head = head->nxt;
  }
  printf("NULL\n");
}

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
    struct node *head = (*ptrtohead);
    struct node* temp = malloc(sizeof(struct node));
    temp->item = item;
    if (position < 0 ) return;

    if (position == 0 ) {
        temp->nxt = head;
        *ptrtohead = temp;
    } else {
        for ( i=1 ; i<position;i++) {
            head = head->nxt;
        }
        temp->nxt = head->nxt;
        head->nxt = temp;
    }
}

int main()
{
    // Create Linked list
    struct node *current = NULL, *temp;
    int n ;
    int i ;
    int item;
    struct node* ptrtohead; /* declare a canvas of art that is blank(null) */

    scanf("%d", &n);
    getchar();
    for ( i=0; i<n; i++) {
	/* C is a sequential language, so we scan user input first
	 *  before deciding what to do with the values
	 */
        scanf("%d", &item);
        getchar();

        if (i==0) {
            current = malloc(sizeof(struct node));
	    current->item = item;
	    ptrtohead = current;
        } else {
            temp = malloc(sizeof(struct node));
	    temp->item = item;
            current->nxt= temp;
            current = temp;
        }
    }
    //Print link list
    printList(ptrtohead);
    //Add a node
    insertNode(0, 99, &ptrtohead);
    //Print changed linked list
    printList(ptrtohead);

}


