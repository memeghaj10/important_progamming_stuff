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
    
    int getDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }        
        return max(getDepth(root->left),getDepth(root->right))+1;
    }
    
    int getsum(TreeNode* root,int h,int curr_h) {
        if(!root) {
            return 0;
        }
        if(curr_h==h-1) {
            return root->val;
        }
        
        return getsum(root->left,h,curr_h+1)+getsum(root->right,h,curr_h+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h=getDepth(root);
        
        return getsum(root,h,0);
    }
};