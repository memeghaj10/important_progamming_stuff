class Solution {
public:
    vector <int> ans ;
        
    void rec(TreeNode * root , int d ){
        if(root == NULL) return ;
        if(ans.size()>d){
            ans[d] = root->val ;
        }else{
            ans.push_back(root->val);
        }
        rec(root->left , d+1);
        
        rec(root->right , d+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        rec(root , 0) ;
        return ans;
    }
    
};