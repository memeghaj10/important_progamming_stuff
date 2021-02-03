/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         
        ListNode *p,*q;
        
        p=q=head;
        
        if(q==NULL||q->next==NULL) {
            return 0;
        }
        
        do{
            
          
            p=p->next;
            if(q->next==NULL) {
                return 0;
            }
            q=q->next;
            if(q->next==NULL) {
                return 0;
            }
            
            q=q->next;
          
        }
        
        while(p!=q&&p&&q);
            
            
        if(p==q) {
            return 1;
        }
        
        return 0;
        
    }
};