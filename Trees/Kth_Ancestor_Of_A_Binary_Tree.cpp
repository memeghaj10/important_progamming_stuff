TreeNode* kthAncestor(TreeNode* root,TreeNode* node,int k) {

    if(!root) {
        return NULL;
    }

    if(root->val==node->val||(kthAncestorDFS(root->left,node,k)||(kthAncestor(root->right,node,k)))) {

        if(k>0) {
            k--;
        }

        else if(k==0) {

            cout<<"Kth_Ancestor is : "<<root->val;

            //to stop further backtracking, we return NULL
            return NULL;

        }

        //return current node to previous call.
        return root;

    }

}