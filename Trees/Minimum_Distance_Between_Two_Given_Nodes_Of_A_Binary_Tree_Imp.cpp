/*

Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 105

*/

  
 Node* LCA(Node* root, int a,int b) {
     
     if(root==NULL) {
         return root;
     }
     
     if(root->data==a||root->data==b) {
         return root;
     }
     
     Node* left=LCA(root->left,a,b);
     Node* right=LCA(root->right,a,b);
     
     if(left!=NULL&&right!=NULL) {
         return root;
     }
     
     if(left==NULL&&right==NULL) {
         return NULL;
     }
     
     if(left) {
         return LCA(root->left,a,b);
     }
     return LCA(root->right,a,b);
     
 }
 
 int find_level(Node* n,int x,int d) {
     if(n==NULL) {
         return -1;
     }
     if(n->data==x) {
         return d;
     }
     
     int l=find_level(n->left,x,d+1);
     
     if(l==-1) {
         return find_level(n->right,x,d+1);
     }
     
     return l;
 }
   
int findDist(Node* root, int a, int b) {
    
    Node* lca=LCA(root,a,b);
    
    int d1=find_level(lca,a,0);
    int d2=find_level(lca,b,0);
    
    return d1+d2;
    
}