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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
           
           
            int u=0;
            
            int x=l1->val;
            int y=l2->val;
            int rem = (x+y+u)%10;
            u=(x+y+u)/10;
        
            ListNode *q = new ListNode(rem);        
            ListNode *p=q;            
            
            if(l1->next==NULL&&l2->next==NULL) {                
                     if(u!=0) {            
                                ListNode *t = new ListNode(u);
                                p->next=t;
                                p=p->next;
                            }                
                return q;
            }
        
        
      while(l1->next!=NULL||l2->next!=NULL) {                   
          
                    if(l1->next!=NULL&&l2->next!=NULL) {
                        
                        l1=l1->next;
                        l2=l2->next;
                        int x=l1->val;
                        int y=l2->val;
                        rem=(x+y+u)%10;
                        u=(x+y+u)/10;
                        
                        ListNode *t=new ListNode(rem);
                        p->next=t;
                        p=p->next;
                       
                    }
                
                    else if(l1->next!=NULL&&l2->next==NULL) {
                        l1=l1->next;
                        int x=l1->val;
                        rem=(x+u)%10;
                        u=(x+u)/10;
                        
                        ListNode *t=new ListNode(rem);
                        p->next=t;
                        p=p->next;                        
                        
                    }
                
                
                    else if(l1->next==NULL&&l2->next!=NULL) {
                        l2=l2->next;                       
                        int y=l2->val;
                        rem=(u+y)%10;
                        u=(y+u)/10;
                        
                        ListNode *t=new ListNode(rem);
                        p->next=t;
                        p=p->next;                        
                    }
                
            }
        
        
        if(u!=0) {            
            ListNode *t = new ListNode(u);
            p->next=t;
            p=p->next;
        }
        
        return q;
                
    }
};