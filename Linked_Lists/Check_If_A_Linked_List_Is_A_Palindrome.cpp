/*

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105

*/


class Solution{
  public:
  
    Node* reverse(Node* head) {
        
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr!=NULL) {
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
        
    }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        
        Node* slow=head;
        Node* fast=head;
        
        if(!head) {
            return 1;
        }
        
        if(head->next==NULL) {
            return 1;
        }
        
        if(head->next->next==NULL) {
            return head->data==head->next->data;
        }
        
        Node* p=head;
        int c=0;
        
        while(p) {
            c++;
            p=p->next;
        }
        c/=2;
        
        while(slow&&fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        
        
        Node* t=slow;
       // slow->next=NULL;
        t=reverse(t);
        
        if(c&1) {
            
            Node* u=head;
            
            while(u&&t&&c--) {
                if(u->data!=t->data) {
                    return 0;
                }
                u=u->next;
                t=t->next;
            }
            
        }
        
        else {
            
            
            Node* u=head;
            
            while(u&&t&&c--) {
                 if(u->data!=t->data) {
                    return 0;
                }
                u=u->next;
                t=t->next;
            }
            
        }
        
        return 1;
        
    }
};
