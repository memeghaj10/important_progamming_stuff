/*

Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list

Constraints
1 <= K <= 103

*/

/*
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

class Solution{
  public:
  
   Node* merge(Node* l1,Node* l2) {
        
            if(!l1) {
                return l2;
            }
        
            if(!l2) {
                return l1;
            }
        
        Node* head=l1->data<=l2->data?l1:l2;
        head->next=l1->data<=l2->data?merge(l1->next,l2):merge(l1,l2->next);
        
        return head;
        
    }
  
  
    Node * mergeKLists(Node *arr[], int K)
    {
        
        if(K==0) {
            return NULL;
        }
        
        Node *head=arr[0];
        
        for(int i=1;i<K;i++) {
            head=merge(head,arr[i]);
        }
        
        
        return head;
    }
};

