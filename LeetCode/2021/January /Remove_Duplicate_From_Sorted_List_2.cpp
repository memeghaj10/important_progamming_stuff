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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL) {
            return head;
        }
        
        ListNode *r=head;
          
         vector<int> v;
        
        map<int,int> mp;
        mp[r->val]++;
        while(r->next!=NULL) {
               r=r->next;
               mp[r->val]++;
        }
        
       
        
        for(auto x:mp) {
            if(x.second<=1) {
                v.push_back(x.first);
            }
        }
        
      
        ListNode *f=new ListNode();
        ListNode *u=f;
        for(int i=0;i<v.size();i++) {
           ListNode *p = new ListNode(v[i]);
                f->next=p;
                f=f->next;                
        }
        
        return u->next;
        
    }
};