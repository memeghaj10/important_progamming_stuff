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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> nodes;
    
    TreeNode* createBST(int l,int r) {
        
        if(l==r) {
            return nodes[r];
        }
        
        if(r-l==1) {
            nodes[r]->left=nodes[l];
            return nodes[r];
        }
        
        int middle=l+((r-l)/2);
        TreeNode* head=nodes[middle];
        head->left=createBST(l,middle-1);
        head->right=createBST(middle+1,r);
        
        return nodes[middle];
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head) {
            return nullptr;
        }
        
        ListNode* tmp=head;
        
        while(tmp) {
            
            nodes.push_back(new TreeNode(tmp->val));
            tmp=tmp->next;
            
        }
        
        return createBST(0,nodes.size()-1);
        
    }
};