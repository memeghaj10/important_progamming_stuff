/*

You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

ArbitLinked List1

Example 1:

Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
are 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbitrary pointer
set, rest two nodes have arbitrary pointer
as NULL. Second line tells us the value
of four nodes. The third line gives the
information about arbitrary pointers.
The first node arbitrary pointer is set to
node 2.  The second node arbitrary pointer
is set to node 4.
Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.

Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.

NOTE : 
1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
2. Your solution return an output 1 if your clone linked list is correct, else it returns 0.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

*/

class Solution
{
    public:
    Node *copyList(Node *start)
    {
        Node* curr=start,*temp;
        
        while(curr) {
            temp=curr->next;
            
            curr->next=new Node(curr->data);
            curr->next->next=temp;
            curr=temp;
        }
        
        curr=start;
        
        while(curr) {
                
                if(curr->next) {
                    curr->next->arb=curr->arb?curr->arb->next:curr->arb;
                }
            
                curr=curr->next?curr->next->next:curr->next;
        }
        
        Node* original = start, *copy=start->next;
        
        temp=copy;
        
        while(original&&copy) {
            
            original->next=original->next?original->next->next:original->next;
            
            copy->next=copy->next?copy->next->next:copy->next;
            
            original=original->next;
            copy=copy->next;
            
        }
        
        return temp;
    }

};