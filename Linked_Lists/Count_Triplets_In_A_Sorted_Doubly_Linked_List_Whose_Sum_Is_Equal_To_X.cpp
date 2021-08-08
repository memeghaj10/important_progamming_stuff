/*

Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.

*/

// structure of node of doubly linked list
struct Node {
    int data;
    struct Node* next, *prev;
};
 

int countPairs(Node* first,Node* second,int value) {

    int count=0;

    while(first!=NULL&&second!=NULL&&first!=second&&second->next!=first) {

        if((first->data+second->data)==value) {
            count++;
            first=first->next;
            second=second->prev;
        }

        else if((first->data+second->data)>value) {
            second=second->prev;
        }

        else {
            first=first->next;
        }

    }

    return count;

}

int countTriplets(Node* head,int x) {

    if(!head) {
        return 0;
    }

    int count=0;

    Node* current,first,last;
    last=head;

    while(last->next!=NULL) {
        last=last->next;
    }

    for(current=head;current!=NULL;current=current->next) {
        first=current->next;
        count+=countPairs(first,last,x-current->data);
    }

    return count;
}

/*

Time Complexity: O(n2) 
Auxiliary Space: O(1)

*/