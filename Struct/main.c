#include <stdio.h>
#include <stdlib.h>


int main(){

   struct basic
    {
        int data;
        struct basic *next;
    };

    struct basic *head;
    struct basic *newnode;

    head = (struct basic*)malloc(sizeof(struct basic));
    head->data = 0;
    head->next = NULL;

    newnode = (struct basic*)malloc(sizeof(struct basic));

    newnode->data = 10;
    newnode->next = head->next;
    head->next = newnode;

    newnode = (struct basic*)malloc(sizeof(struct basic));

    newnode->data = 20;
    newnode->next = head->next;
    head->next = newnode;

    while(head!=NULL)
    {
        printf("%d\n", head->data);
        head=head->next;
    }

    return 0;

}
