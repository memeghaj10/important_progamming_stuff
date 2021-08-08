/*

Given a doubly linked list, rotate the linked list counter-clockwise by N nodes. Here N is a given positive integer and is smaller than the count of nodes in linked list. 
 
 Input : a  b  c  d  e   N = 2
Output : c  d  e  a  b 

Input : a  b  c  d  e  f  g  h   N = 4
Output : e  f  g  h  a  b  c  d 

*/

/* Link list node */
struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};
 

void rotate(Node** head,int n) {

    if(n==0) {
        return;
    }

    Node* current=*head;

    int count=1;

    while(count<N&&current!=NULL) {
        current=current->next;
        count++;
    } 

    if(current==NULL) {
        return ;
    }

    Node* NthNode=current;

    while(current->next!=NULL) {
        current=current->next;
    }

    current->next=*head;

    (*head)->prev=current;
    *head=NthNode->next;


    *head->prev=NULL;
    NthNode->next=NULL;

}
