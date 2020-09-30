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
    int sum(TreeNode *root,int curr_val) {
                        if(root==NULL) {
                              return 0;
                        }

                        if(root->left==NULL && root->right==NULL) {
                              return curr_val*2+root->val;
                        }
                        return sum(root->left,curr_val*2+root->val)+sum(root->right,curr_val*2+root->val);
                  }

                  

                  int sumRootToLeaf(TreeNode* root) {
                        int curr_val=0;
                        return sum(root,curr_val);
                  }
};