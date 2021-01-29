/**

This is not my solution... shame and only shame on me.

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
    void findminmax(TreeNode* node , int & mn , int& mx , int distN){
    if(node == nullptr) return;
    
    if(mn  > distN){
        mn = distN;
    }
    if(mx < distN){
        mx = distN;
    }
    
    findminmax(node -> left , mn , mx , distN - 1);
    findminmax(node -> right , mn , mx , distN + 1);
    
}
void verticalValueXX(vector<pair<int,int> > &elem , int line , TreeNode* node , int distN,int depth){
    
    if(node == nullptr) return ;
    if(distN == line){
        elem.push_back(make_pair(depth , node->val));
    }
    verticalValueXX(elem , line , node->left, distN -1,depth+1);
    verticalValueXX(elem , line , node->right, distN +1 , depth+1);
}

 vector<pair<int ,int > > verticalValue(int line , TreeNode* node , int distN){
     int depth = 0;
     vector<pair<int,int > >elem;
     if(node == nullptr) return elem;
     verticalValueXX(elem , line , node , distN,depth);
     return elem;
 }

vector<vector<int>> verticalTraversal(TreeNode* root) {
   // vector<vector<int> > vv;
    int mn = 0,mx =0;
    findminmax( root , mn, mx ,0);
    vector<vector<int> > vv((abs(mn)+abs(mx)+1));

    for(int i = mn;i <= mx;i++){
        if(root == nullptr) continue;
       vector<pair<int,int> >ans = verticalValue(i , root , 0);
        sort(ans.begin() , ans.end());
        for(int j = 0;j<ans.size();j++){
            vv[i+ abs(mn)].push_back(ans[j].second);
        }
    
       //if(ans.size()>=1) vv.emplace_back(ans);
    }
    return vv;
}
};