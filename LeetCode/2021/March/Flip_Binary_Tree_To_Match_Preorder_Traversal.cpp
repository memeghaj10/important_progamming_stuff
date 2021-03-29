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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        int n=voyage.size();
        int pos=0;
        
        vector<int> flipped;
        if(!helper(root,voyage,pos,flipped)||pos!=n) {
            return vector<int>{-1};
        }
        
        return flipped;
        
    }
    
    bool helper(TreeNode* root,vector<int>& pre,int &pos,vector<int>& flipped) {
        
        if(!root) {
            return true;
        }
        
        if(root->val!=pre[pos++]) {
            return false;
        }
        
        TreeNode* child1=root->left,*child2=root->right;
        
        if(child1&&child2&&pre[pos]!=child1->val) {
            flipped.push_back(root->val);
            swap(child1,child2);
        }
        
        return helper(child1,pre,pos,flipped)&&helper(child2,pre,pos,flipped);
        
    }
    
};