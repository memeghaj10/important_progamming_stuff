/*

Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list.


Solution :-

Approach: Create a recursive function say reverse(head, k).
This function receives the head or the first node of each group of k nodes.
It reverses those group of k nodes by applying the approach discussed.
After reversing the group of k nodes the function checks whether next group of nodes exists in the list or not.
If group exists then it makes a recursive call to itself with the first node of the next group and makes the necessary adjustments with the next and previous links of that group.
Finally it returns the new head node of the reversed group. 



*/

// a node of the doubly linked list
struct Node {
    int data;
    Node *next, *prev;
};

//function to insert a node at the start of the Doubly Linked List

void push(Node** head_ref,Node* new_node) {

    new_node->prev=NULL;

    new_node->next=(*head_ref);

    if((*head_ref)!=NULL) {
        (*head_ref)->prev=new_node;
    }

    (*head_ref)=new_node;
}


Node* revListInGroupOfGivenSize(Node* head,int k) {

    Node* current=head;
    Node* next=NULL;
    Node* newHead=NULL;
    int count=0;

    while(current!=NULL&&count<k) {
        next=current->next;
        push(&newHead,current);
        current=next;
        count++;
    }

    if(next!=NULL) {
        head->next=revListInGroupOfGivenSize(next,k);
        head->next->prev=head;
    }

    return newHead;
}