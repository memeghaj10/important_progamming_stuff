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
        
        queue<pair<TreeNode*,vector<TreeNode*>>> qu;
        qu.push({root,{}});
        
        int k=2;
        
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        
        while(!qu.empty()) {
            
            auto x=qu.front();
            qu.pop();
            
            vector<TreeNode*> v=x.second;
            v.push_back(x.first);
            
            if(x.first->val==p->val) {
                k--;
                v1=v;
            }
            
            if(x.first->val==q->val) {
                k--;
                v2=v;
            }
            
            if(x.first->left&&k) {
                qu.push({x.first->left,v});
            }
            
            if(x.first->right&&k) {
                qu.push({x.first->right,v});
            }
            
            if(k==0) {
                break;
            }
            
        }
        
        for(int i=v2.size()-1;i>=0;i--) {
            for(int j=v1.size()-1;j>=0;j--) {
                if(v2[i]->val==v1[j]->val) {
                    return v2[i];
                }
            }
        }
        
        return NULL;
        
    }
};