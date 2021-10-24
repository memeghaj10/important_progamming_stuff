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
    int countNodes(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        
        int ans=0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            ans+=q.size();
            int n=q.size();
            
            while(n--) {
                
                TreeNode* r=q.front();
                q.pop();
                
                if(r->left!=NULL) {
                    q.push(r->left);
                }
                
                if((r->right!=NULL)) {
                    q.push(r->right);
                }
                
            }
            
        }
        
        return ans;
    }
};