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
    
    vector<int> v;
    
    void printPostorder(struct TreeNode* node) 
        { 
            if (node == NULL) 
                return; 
 
           printPostorder(node->left); 
  
     
           printPostorder(node->right); 
  
     
          v.push_back(node->val);
        } 
  
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        
      
        
        
        
        
        
        printPostorder(root1);
        
        printPostorder(root2);
        
        
        sort(v.begin(),v.end());
        
        
        return v;       
            
        
    }
};