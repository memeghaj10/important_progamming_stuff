/*

Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

 

Example 1:

Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
 

Example 2:

Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

Your Task:
Your task is to complete the given function splitList(), which takes 3 input parameters: The address of the head of the linked list, addresses of the head of the first and second halved resultant lists and Set the head1_ref and head2_ref to the first resultant list and second resultant list respectively.


Expected Time Complexity: O(N)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 100


*/


//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
   
   Node* slow=head;
   Node* fast=head;
   
   while(fast->next!=head&&fast->next->next!=head) {
       slow=slow->next;
       fast=fast->next->next;
   }
   
   *head1_ref=head;
   *head2_ref=slow->next;
   
  // Node* temp=slow->next;
   slow->next=head;
   //temp=head;
   
   Node* curr=*head2_ref;
   
   while(curr->next!=head) {
       curr=curr->next;
   }
   
   curr->next=*head2_ref;
   
}