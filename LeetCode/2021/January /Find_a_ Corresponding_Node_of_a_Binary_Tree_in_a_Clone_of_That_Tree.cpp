/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode *ans;
public:
    
    void dfs(TreeNode *root,int k) {
        if(!root) {
            return;
        } 
        
        if(root->val==k) {
            ans=root;
        }
        
        dfs(root->left,k);
        dfs(root->right,k);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned,target->val);
        
        return ans;
    }
};