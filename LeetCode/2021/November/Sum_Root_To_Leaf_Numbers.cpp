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
    
    int ans;
    
    
    void solve(TreeNode* root,int x) {
        
       
        if(root->left==NULL&&root->right==NULL) {
            ans+=x*10+root->val;
            return;
        }
        
        x=x*10+root->val;
        
        if(root->left!=NULL) {
            solve(root->left,x);
        }
        
        if(root->right!=NULL) {
            solve(root->right,x);
        }
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        
        ans=0;
        
       solve(root,0);
        
        return ans;
        
    }
};