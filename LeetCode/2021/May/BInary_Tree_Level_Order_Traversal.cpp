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
class Solution  {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> v;
        
        queue<TreeNode*> q;
        queue<TreeNode*> q1;
        
        q.push(root);
        vector<int> dumm;
        
        if(root!=NULL) {
            dumm.push_back(root->val);
            v.push_back(dumm);
            dumm.clear();
        }
        
        if(root==NULL) {
            return v;
        }
        
        
        while(!q.empty()) {
            
            TreeNode *r=q.front();
            q.pop();
            
           if(r->left!=NULL) {
               q1.push(r->left);
           }
            if(r->right!=NULL) {
                q1.push(r->right);
            }
            
            if(q.empty()) {
                    
                while(!q1.empty()) {
                    dumm.push_back(q1.front()->val);
                    q.push(q1.front());
                    q1.pop();
                }
                
                if(dumm.size()>=1) {
                    v.push_back(dumm);
                }
                
                dumm.clear();
                //q1.clear();                
            }
            
        }
        
        return v;
        
    }
};