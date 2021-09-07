/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* rec_reverse(ListNode* n,ListNode* rev_head) {
        if(n==NULL) {
            return rev_head;
        }
        else {
            ListNode* next=n->next;
            n->next=rev_head;
            return rec_reverse(next,n);
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        
        return rec_reverse(head,nullptr);
        
    }
};