/*

Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40
Your Task:
The task is to complete the function intersection() which should find the intersection of two linked list and add all the elements in intersection to the third linked list and return the head of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n,m are the size of the linked lists.

Constraints:
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 1000

*/



Node* findIntersection(Node* head1, Node* head2)
{
    vector<int> v;
    
    set<int> st1;
    set<int> st2;
    
    while(head1!=NULL) {
        st1.insert(head1->data);
        head1=head1->next;
    }
    
    while(head2!=NULL) {
        if(st1.find(head2->data)!=st1.end()&&st2.find(head2->data)==st2.end()) {
            v.push_back(head2->data);
            st2.insert(head2->data);
        }
        head2=head2->next;
    }
    
    if(v.size()==0) {
        return NULL;
    }
    
    Node* r=new Node(v[0]);
    Node* q=r;

    
    for(int i=1;i<v.size();i++) {
        Node* t=new Node(v[i]);
        r->next=t;
        r=r->next;
    }
    
    return q;
    
}