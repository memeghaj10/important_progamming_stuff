class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        
        if(temp1==NULL) {
            return temp2;
        }
        
        if(temp2==NULL) {
            return temp1;
        }
        
        if(temp1->val>=temp2->val) {
            temp2->next=mergeTwoLists(temp1,temp2->next);
        }
        
        else {
            temp1->next=mergeTwoLists(temp1->next,temp2);
            temp2=temp1;
        }
        
        
        return temp2;
        
        
    }
};