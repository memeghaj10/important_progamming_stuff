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

#define ll long long int

class Solution {
public:
    
    int dfs(TreeNode* root,ll sum,ll &ans) {
        
        if(!root) {
            return 0;
        }
        
        ll curr=dfs(root->left,sum,ans)+dfs(root->right,sum,ans)+root->val;
        
        ans=max(ans,(sum-curr)*curr);
        
        return curr;
        
    }
    
    int maxProduct(TreeNode* root) {
    
        ll ans=0;
        ll sum=dfs(root,0,ans);
        sum=dfs(root,sum,ans);
        
        ans%=1000000007;
        
        return (int)ans;
        
    }
};