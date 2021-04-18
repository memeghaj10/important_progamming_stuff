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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *f=head;
        ListNode *s=head;
        ListNode *d=new ListNode;
        d->next=head;
        f=d;
        s=d;
        
        
        int u=n+1;
        
        while(u--) {
            f=f->next;
        }
        
       while(f!=NULL) {
           f=f->next;
           s=s->next;
       } 
        
        ListNode *r=s->next->next;
        s->next=r;
        
        return d->next;
        
    }
};