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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if(d==1) {
            TreeNode *n=new TreeNode(v);
            n->left=root;
            return n;
        }
        
        insert(v,root,1,d);
    
        return root;
        
    }
    
    void insert(int val,TreeNode* node, int d,int n) {
        if(node==NULL) {
            return ;
        }
        
        if(d==n-1) {
            
            TreeNode *t=node->left;
            node->left=new TreeNode(val);
            node->left->left=t;
            t=node->right;
            node->right=new TreeNode(val);
            node->right->right=t;
        }
        
        else {
            insert(val,node->left,d+1,n);
            insert(val,node->right,d+1,n);
        }
        
    }
    
    
};