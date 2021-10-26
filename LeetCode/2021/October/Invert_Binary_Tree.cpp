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
    TreeNode* invertTree(TreeNode* root) {
			if(root==NULL)
				return NULL;
			TreeNode* temp = new TreeNode(root->val);// create node with (NULL, val, NULL)

			if(root->right)//if root->right is Not NULL, it will assign it to temp->left : else let it be NULL 
				temp-> left = invertTree(root->right);

			if(root->left)// same as before
				temp-> right = invertTree(root->left); 

			return temp;//return temp node
		}
};