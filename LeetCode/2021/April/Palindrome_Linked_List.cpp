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
    bool isPalindrome(ListNode* head) {
        
        stack<int> st;
        
        ListNode *r=head;
        
        if(r->next==NULL) {
            return 1;
        }
        
        vector<int> v;
        
        while(r!=NULL) {
            v.push_back(r->val);
            r=r->next;
        }
        
        vector<int> t=v;
        reverse(t.begin(),t.end());
        
        return t==v;
        
    }
};