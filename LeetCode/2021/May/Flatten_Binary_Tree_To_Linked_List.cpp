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
    void flatten(TreeNode* root) {
        
        if(nullptr==root) {
            return;
        }
        
        TreeNode *right_node=root->right;
        
        flatten(root->left);
        
        root->right=root->left;
        root->left=nullptr;
        
        while(root->right) {
            root=root->right;
        }
        
        flatten(right_node);
        
        root->right=right_node;
        
    }
};