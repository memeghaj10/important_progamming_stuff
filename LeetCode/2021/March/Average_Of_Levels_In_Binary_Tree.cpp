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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        
        map<int,long> mp;
        map<int,int> count;
        
        solve(mp,count,root,0);
        
        for(auto x:mp) {
            ans.push_back(((double)mp[x.first]/count[x.first]));
        }
                        
         return ans;
        
    }
    
    void solve(map<int,long>& mp,map<int,int>& count,TreeNode* root,int level) {
            
        if(root==NULL) {
            return;
        }
        
        mp[level]+=root->val;
        count[level]++;
        
        solve(mp,count,root->left,level+1);
        solve(mp,count,root->right,level+1);
        
    }
    
};