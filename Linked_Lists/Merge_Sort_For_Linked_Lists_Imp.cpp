/*

Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105

*/



class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    void Split(Node* head,Node** a,Node** b) {
        
        Node* fast=head->next;
        Node* slow=head;
        
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        *a=head;
        *b=slow->next;
        
        slow->next=NULL;
        
    }
    
    Node* SortedMerge(Node* a,Node* b) {
        
        if(!a) {
            return b;
        } 
        
        if(!b) {
            return a;
        }
        
        Node* head=NULL,*tail=NULL;
        
        if(a->data<b->data) {
            head=tail=a;
            a=a->next;
        }
        
        else {
            head=tail=b;
            b=b->next;
        }
        
        while(a&&b) {
            if(a->data<b->data) {
                tail->next=a;
                tail=a;
                a=a->next;
            }
            
            else {
                tail->next=b;
                tail=b;
                b=b->next;
            }
        }
        
        if(!a) {
            tail->next=b;
        }
        
        else {
            tail->next=a;
        }
        
        return head;
            
        
    }
    
    void MergeSort(Node **headRef) {
        
        Node* head=*headRef;
        
        if(head==NULL||(head->next==NULL)) {
            return;
        }
        
        Node* a,*b;
        Split(head,&a,&b);
        
        MergeSort(&a);
        MergeSort(&b);
        
        *headRef=SortedMerge(a,b);
        
    }
    
    Node* mergeSort(Node* head) {
        MergeSort(&head);
        
        return head;
    }
};
