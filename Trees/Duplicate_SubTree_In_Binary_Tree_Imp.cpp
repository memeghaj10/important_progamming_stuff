/*

Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.


Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only arguement and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.
Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

*/


class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    map<string,int> mp;
    bool f;
    
    string find_dupl(Node* root,map<string,int>& mp) {
        
        if(root==NULL) {
            return "";
        }
        
        string s="";
        s+="$";
        s+=to_string(root->data);
        s+="$";
        s+=find_dupl(root->left,mp);
        s+="$";
        s+=find_dupl(root->right,mp);
        s+="$";
        
        if(mp.find(s)!=mp.end()&&s.size()>=7) {
            mp[s]++;
            f=1;
        }
        mp[s]++;
        
        return s;
    }
    
    int dupSub(Node *root) {
         f=0;
         find_dupl(root,mp);
         
         return f;
    }
};