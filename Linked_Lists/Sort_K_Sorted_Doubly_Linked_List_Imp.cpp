/*

Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list. 
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.

*/

/*

Time Complexity: O(n*log k)
Auxiliary Space: O(k)

*/


// a node of the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
// 'compare' function used to build up the
// priority queue
struct compare {
    bool operator()(struct Node* p1, struct Node* p2)
    {
        return p1->data > p2->data;
    }
};

Node* sortAKSortedDLL(Node* head, int k) {

    if(!head) {
        return head;
    }

    priority_queue<Node*,vector<Node*>,compare> pq;

    Node* newHead=NULL;

    for(int i=0;head!=NULL&&i<=k;i++) {
        pq.push(head);
        head=head->next;
    }

    while(!pq.empty()) {

        if(!newHead) {
            newHead=pq.top();
            newHead->prev=NULL;

            last=newHead;
        }

        else {
            last->next=pq.top();
            pq.top()->prev=last;
            last=pq.top();
        }

        pq.pop();

        if(head!=NULL) [
            pq.push(head);
            head=head->next;
        ]

    }


    last->next=NULL;

    return newHead;

}