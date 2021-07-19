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
    
    pair<ListNode*,ListNode*> reverseK(ListNode* head, int k) {
        ListNode *curr=head,*prev=NULL,*next;
        for(int i=0;i<k;i++) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return {prev,next};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode dummy(0,head),*x=head,*tmp;
        
        int len=0;
        
        for(;x!=NULL;x=x->next) {
            len++;
        }
        
        int m=len/k;
        
        x=&dummy;
        
        pair<ListNode*,ListNode*> p;
        
        for(int i=0;i<m;i++) {
            tmp=x->next;
            p=reverseK(tmp,k);
            x->next=p.first;
            x=tmp;
            x->next=p.second;
        }
    
        return dummy.next;
        
    }
};