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
    void pathsumutil(TreeNode* root,vector<int>& v,int sum ,int &count){
    if(root==NULL) return;
    v.push_back(root->val);
    pathsumutil(root->left,v,sum,count);
    pathsumutil(root->right,v,sum,count);
    
    int reqsum=0;
    for(int j=v.size()-1;j>=0;j--){
        reqsum+=v[j];
        if(reqsum==sum) count++;
    }
    v.pop_back();
}

int pathSum(TreeNode* root, int sum) {
    vector<int> vec;
    int count = 0;
    pathsumutil(root,vec,sum,count);
    return count;
}

};