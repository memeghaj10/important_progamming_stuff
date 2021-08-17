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
    
   void get(TreeNode* root,int &ans,int max_n) {
        
        if(root==NULL) {
            return ;
        }
        
        if(root->val>=max_n) {
            ans++;
        }
       
       get(root->left,ans,max(root->val,max_n));
       get(root->right,ans,max(root->val,max_n));
        
    }
    
    int goodNodes(TreeNode* root) {
        
        int n=root->val;
        
        int ans=1;
        
        get(root->left,ans,n);
        get(root->right,ans,n);
        
        return ans;
        
    }
};