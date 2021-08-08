/*

Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space? 

Example:  

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
The expected time complexity is O(n) and auxiliary space is O(1).

*/

// structure of node of doubly linked list
struct Node
{
    int data;
    struct Node *next, *prev;
};


//solution functions
void pair_sum(Node* head,int x) {

    Node* first=head;
    Node* second=head;
    while(second->next) {
        second=second->next;
    }

    bool found=0;

    while(first!=second&&second->next==first) {

        if(first->data+second->data==x) {
            found=true;

            cout<<first->data<<" "<<second->data<<endl;

            first=first->next;
            second=second->prev;

        }

        else  {

                if(first->data+second->data<x) {
                    first=first->next;
                }

                else {
                    second=second->prev;
                }

        }


    }

    if(!found) {
        cout<<"No pair found";
    }

}