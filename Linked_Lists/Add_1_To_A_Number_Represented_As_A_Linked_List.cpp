/*

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000

*/


class Solution
{
    public:
    
    Node* reverse(Node* head) {
        
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr!=NULL) {
            Node *nex=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nex;
        }
        
        return prev;
    }
    
    
    Node* addOne(Node *head) 
    {
        
        head=reverse(head);
        
        Node* curr=head,*prev=head;
        
        int sum=(curr->data+1);
        curr->data=sum%10;
        int carry=sum/10;
        
        curr=curr->next;
        
        while(curr!=NULL) {
            sum=curr->data+carry;
            curr->data=sum%10;
            carry=sum/10;
            
            prev=curr;
            
            curr=curr->next;
        }
        
        if(carry) {
            prev->next=new Node(carry);
        }
        
        head=reverse(head);
        
        
        return head;
        
        
    }
};