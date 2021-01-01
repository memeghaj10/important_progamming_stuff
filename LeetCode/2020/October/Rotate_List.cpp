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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==nullptr||head->next==nullptr) return head;
        
        int l=1;
        
        ListNode* tail = head;
        
        while(tail->next!=nullptr) {
            tail = tail->next;
            l++;
        }
        
        k=k%l;
        
        if(k==0) {
            return head;
        }
        
        ListNode* newHead = head;
        ListNode* newTail = head;
        
        while(l>k) {
            newTail= newHead;
            newHead = newHead->next;
            l--;
        }
        
        newTail->next = nullptr;
        tail->next = head;
        return newHead;
        
    }
};