/*

Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
Example 2:

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= size of linked lists <= 106
0 <= numbers in list <= 104

*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     
     if(!head) {
         return head;
     }
     
     map<int,int> mp;
     
     Node* t=head;
     Node* r=head;
     //Node x=&t;
     r=r->next;
     mp[t->data]++;
     t->next=NULL;
     
     while(r!=NULL) {
         if(mp[r->data]==0) {
             t->next=new Node(r->data);
             t=t->next;
             mp[t->data]++;
         }
        
         r=r->next;
     }
     
     
     return head;
        
    }
};
