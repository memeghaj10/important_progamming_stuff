/*

Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.

Your Task: 
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^3

*/



class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        queue<Node*> q;
        q.push(root);
        
        int c=0;
        
        while(!q.empty()) {
            
            int n=q.size();
            int t=0;
            
            while(n--) {
                
                Node *r=q.front();
                q.pop();
                
                if(r->left==NULL&&r->right==NULL) {
                    t++;
                }
                
                if(r->left) {
                    q.push(r->left);
                }
                if(r->right) {
                    q.push(r->right);
                }
                
            }
            
            if(t) {
                c++;
            }
            
        }
        
        
        if(c>1) {
            return 0;
        }
        
        return 1;
    }
};