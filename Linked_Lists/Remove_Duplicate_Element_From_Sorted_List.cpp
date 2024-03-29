/*

Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Example 1:

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time.
Example 2:

Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list 
2 ->2 ->2 ->2 ->2, 2 is the only element
and is repeated 5 times.
Your Task:
The task is to complete the function removeDuplicates() which should remove the duplicates from linked list and return the head of the linkedlist.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= Number of nodes <= 104

*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 
    if(!head) {
        return head;
    }
 
    Node *trav=head;
    
    while(trav!=NULL&&trav->next) {
        while(trav&&trav->next&&trav->data==trav->next->data) {
            trav->next=trav->next->next;
        }
        if(trav) {
            trav=trav->next;
        }
    }
    
    return head;
 
}