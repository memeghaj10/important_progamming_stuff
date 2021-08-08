/*

Given a singly linked list, remove all the nodes which have a greater value on its following nodes.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ size of linked list ≤ 1000
1 ≤ element of linked list ≤ 1000
Note: Try to solve the problem without using any extra space.

*/


/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    Node* reverse(Node* head) {
        
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr) {
            
            Node* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
            
        }
        
        return prev;
        
    }
    
    Node *compute(Node *head)
    {
        Node* t=head;
        t=reverse(t);
        Node* r=t;
        
        int prev=t->data;
        
        Node* curr=t;
        
        curr=curr->next;
        
        while(curr) {
            
            if(curr->data<prev) {
                t->next=curr->next;
            }
            
            else {
                t=t->next;
                prev=max(prev,t->data);
            }
            
            curr=curr->next;
        }
        
        t=reverse(r);
        
        return t;
        
    }
    
};
   
