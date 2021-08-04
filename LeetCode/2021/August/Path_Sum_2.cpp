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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        queue<pair<TreeNode*,vector<int>>> q;
        
        if(!root) {
            return {};
        }
        
        vector<int> v;
        v.push_back(root->val);
        
        q.push({root,v});
        
        
        vector<vector<int>> ans;
        
        while(!q.empty()) {
            
            auto x=q.front();
            q.pop();
            
            vector<int> r=x.second;
            TreeNode* t=x.first;
            
            if(t->left==NULL&&t->right==NULL) {
                int sum=accumulate(r.begin(),r.end(),0);
                if(sum==targetSum) {
                    ans.push_back(r);
                    continue;
                }
            }
            
            if(t->left!=NULL) {
                r.push_back(t->left->val);
                q.push({t->left,r});
                r.pop_back();
            }
            
            if(t->right!=NULL) {
                r.push_back(t->right->val);
                q.push({t->right,r});
            }            
            
        }
        
        return ans;
        
    }
};