/*

Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104
1 <= k <= N

*/


class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
       
       node* next=NULL; 
       node* prev=NULL;
       node* curr=head;
       int count=0;
       
       while(curr!=NULL&&count<k) {  //first we will reverse the k-nodes or less in the series
           
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           
           count++;
           
       }
    
        if(next!=NULL) {    //after the nodes have been reversed, the netx pointer would point to the next node in the
                            //list that has not been reversed.
            node* res_head=reverse(next,k); //reversing all the nodes that will be starting from next;
            head->next=res_head;        //then, as the head of the previous node would point to the last element of the previous reversal, we would
                                        //add to that the head of the next reversal.
        }
        
        return prev;    //finally returning the previous of the first reversal.
           
    }
};