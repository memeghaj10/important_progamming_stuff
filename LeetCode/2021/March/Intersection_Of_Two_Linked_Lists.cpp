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
    
    int len(ListNode *C) {
        
        int ans=0;
        while(C!=NULL) {
            C=C->next;
            ans++;
        }
        
        return ans;
        
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
            int n=len(headA);
            int m=len(headB);
        
            int diff=abs(n-m);
        
            if(n>m) {
                while(diff--) {
                    headA=headA->next;
                }
            }
        
            if(m>n) {
                while(diff--) {
                    headB=headB->next;
                }
            }
        
            while(headA) {
                
                    if(headA==headB) {
                        return headA;
                    }
                
                    headA=headA->next;
                    headB=headB->next;
                
            }
        
        return NULL;
        
        
    }
};