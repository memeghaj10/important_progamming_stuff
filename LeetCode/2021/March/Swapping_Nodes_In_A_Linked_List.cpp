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
    ListNode* swapNodes(ListNode* head, int k) {
        
        vector<int> v;
        
        while(head!=NULL) {
            v.push_back(head->val);
            head=head->next;
        }
        
        int m1,m2;
        int p=k;
        
        for(int i=0;i<v.size();i++) {
            if(k>0) {
                m1=i;
                k--;
            }
        }
        
        for(int i=v.size()-1;i>=0;i--) {
            if(p>0) {
                m2=i;
                p--;
            }
        }
        
        swap(v[m1],v[m2]);
        
        ListNode* n=new ListNode(v[0]);
        ListNode* p1=n;
        
        for(int i=1;i<v.size();i++) {
            ListNode *r=new ListNode(v[i]);
            n->next=r;
            n=n->next;
        }
        
        return p1;
        
    }
};