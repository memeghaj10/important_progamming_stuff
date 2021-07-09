/*

Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000

*/





class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int height(Node* root,int& ans) {
        
        if(!root) {
            return 0;
        }
        
        int l=height(root->left,ans);
        int r=height(root->right,ans);
        
        ans=max(ans,1+l+r);
        
        return 1+max(l,r);
        
    }
    
    int diameter(Node* root) {
        if(!root) {
            return 0;
        }
        
        int ans=INT_MIN;
        height(root,ans);
        
        return ans;
    }
};