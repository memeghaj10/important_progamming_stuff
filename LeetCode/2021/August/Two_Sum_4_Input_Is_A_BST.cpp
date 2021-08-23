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
    
    void recur(TreeNode* root,vector<int>& v) {
        if(!root) {
            return;
        }
        recur(root->left,v);
        v.push_back(root->val);
        recur(root->right,v);
    }
    
    bool two_sum(vector<int>& v,int k) {
        
        map<int,int> mp;
        
        for(auto x:v) {
            mp[x]++;
        }
        
        for(auto x:v) {
            mp[x]--;
            if(mp[k-x]>=1) {
                return 1;
            }
            mp[x]++;
        }
        
        return 0;
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> v;
        
        recur(root,v);
        
        return two_sum(v,k);
        
    }
};