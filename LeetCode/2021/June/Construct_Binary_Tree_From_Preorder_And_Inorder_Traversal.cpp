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
    
    TreeNode* solve(vector<int>& pre,unordered_map<int,int>& m,int& index,int start,int end) {
        
        TreeNode *node=new TreeNode(pre[index]);
        int mid=m[pre[index]];
        
        if(mid>start) {
            node->left=solve(pre,m,index+=1,start,mid-1);
        }
        if(end>mid) {
            node->right=solve(pre,m,index+=1,mid+1,end);
        }
        
        return node;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++) {
            m[inorder[i]]=i;
        }
        
        int x=0;
        
        return solve(preorder,m,x,0,n-1);
        
    }
};