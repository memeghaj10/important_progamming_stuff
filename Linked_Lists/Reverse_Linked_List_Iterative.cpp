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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* r=head;
        
        if(r==NULL) {
            return head;
        }
        
        
        ListNode* prev=NULL;
        
        while(r!=NULL) {
          ListNode* temp=r->next;
            r->next=prev;
            prev=r;
            r=temp;
        }
        
        return prev;
        
    }
};