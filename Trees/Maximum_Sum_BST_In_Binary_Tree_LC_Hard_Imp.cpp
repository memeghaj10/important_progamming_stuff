/*

Given a binary tree root, the task is to return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
Example 4:

Input: root = [2,1,3]
Output: 6
Example 5:

Input: root = [5,4,8,3,null,6,3]
Output: 7
 

Constraints:

The given binary tree will have between 1 and 40000 nodes.
Each node's value is between [-4 * 10^4 , 4 * 10^4].

*/


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
    
    int ans;
    
    struct node {        
        int sum;
        bool IsBST;
        int maxleft;
        int maxright;
        
        node(int sum,bool IsBST,int maxleft,int maxright) {
            this->sum=sum;
            this->IsBST=IsBST;
            this->maxleft=maxleft;
            this->maxright=maxright;
        }       
    };
    
    
    node* recur(TreeNode* root)  {
        
        if(root==NULL) {
            return new node(0,1,INT_MAX,INT_MIN);
        }
        
        node* l=recur(root->left);
        node* r=recur(root->right);
        
        node* q;
        
        if(l->IsBST&&r->IsBST&&root->val>l->maxright&&root->val<r->maxleft) {
            q=new node(l->sum+r->sum+root->val,true,min(root->val,min(l->maxleft,r->maxleft)),max(root->val,max(l->maxright,r->maxright)));
        }
        
        else {
            q=new node(max(l->sum,r->sum),0,0,0);
        }
        
        ans=max(ans,q->sum);
        
        return q;
        
    }
    
    
    
    int maxSumBST(TreeNode* root) {
         ans=0;
         recur(root);
        
        return ans;         
    }
};



//Another better solution can be this also:-


//This is basically "Validate Binary Search Tree" LeetCode Ques, with extra step of calculating the sum of each valid subtree.

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        
        helper(root, ans);
        
        return ans;
    }
    
    tuple<int, int, int> helper(TreeNode* root, int& ans) { // min, max, sum
        if (not root) {
            // base case
            return {INT_MAX, INT_MIN, 0};
        }
        
        auto [leftMin, leftMax, leftSum] = helper(root->left, ans);
        auto [rightMin, rightMax, rightSum] = helper(root->right, ans);
        
        if (root->val > leftMax and root->val < rightMin) {
            // valid bst
            int sum = leftSum + root->val + rightSum;
            ans = max(ans, sum);

            return {min(root->val, leftMin), max(root->val, rightMax), sum};
        }
        
        // invalid bst
        return {INT_MIN, INT_MAX, 0};
    }
};
Time complexity - O(N).
Space complexity - O(H).