/*

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000

*/


class Solution
{
    public:
    
    Node* reverse(Node* root) {
        
        Node* prev=NULL;
        Node* curr=root;
        
        while(curr!=NULL) {
            Node* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        
        return prev;
        
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        
        Node* dum=new Node(-1);
        Node* y=dum;
        
        int c=0;
        
        while(first&&second) {
            int sum=0;
            sum+=first->data;
            sum+=second->data;
            
            first=first->next;
            second=second->next;
            
            sum+=c;
            
            Node* t=new Node((sum)%10);
            dum->next=t;
            dum=dum->next;
            
            c=sum/10;
        }
        
        while(first) {
            int sum=c+first->data;
            Node* t=new Node(sum%10);
            dum->next=t;
            dum=dum->next;
            first=first->next;
            
            c=sum/10;
        }
        
         while(second) {
            int sum=c+second->data;
            Node* t=new Node(sum%10);
            dum->next=t;
            dum=dum->next;
            second=second->next;
            
            c=sum/10;
        }
        
        if(c) {
            Node* t=new Node(c);
            dum->next=t;
            dum=dum->next;
        }
        
        dum=reverse(y->next);
        
        return dum;
        
        
    }
};