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
    
    void recur(TreeNode* root, vector<int>& ans) {
        
        if(root->left!=NULL) {
            recur(root->left,ans);
        }
        ans.push_back(root->val);
        if(root->right!=NULL) {
            recur(root->right,ans);
        }
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) {
            return {};
        }
        
        vector<int> ans;
        
        recur(root,ans);
        
        return ans;
        
    }
};