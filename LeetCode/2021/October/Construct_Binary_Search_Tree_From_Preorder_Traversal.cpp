class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode();
        
        root->val=preorder[0];
        
        for(int i=1;i<preorder.size();i++){
            my_push_back(root, preorder[i]);
        }
        
        return root;
    }
    
    void my_push_back(TreeNode* root, int val_to_insert){
        if(val_to_insert>root->val){
            if(root->right==NULL){
                root->right=new TreeNode(val_to_insert);
            }
            else{
                my_push_back(root->right, val_to_insert);
            }
        }
        else if(val_to_insert<root->val){
            if(root->left==NULL){
                root->left=new TreeNode(val_to_insert);
            }
            else{
                my_push_back(root->left, val_to_insert);
            }
        }
    }
};