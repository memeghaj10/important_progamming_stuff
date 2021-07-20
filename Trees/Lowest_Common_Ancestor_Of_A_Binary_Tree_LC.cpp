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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans=root;
        
        int x=p->val;
        int y=q->val;
        
        while(ans!=NULL) {
            
            if(x<ans->val&&y<ans->val) {
                ans=ans->left;
            }
            
            else if(x>ans->val&&y>ans->val) {
                ans=ans->right;
            }
            
            else {
                return ans;
            }
            
        }
        
        return root;
        
    }
};