/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        
        queue<Node*> q;
        vector<int> v;
        
        if(!root) {
            return ans;
        }
        
        
        q.push(root);
        
        while(!q.empty()) {
            
            int n=q.size();
            
            while(n--) {
                
                Node* r=q.front();
                q.pop();
                
                v.push_back(r->val);
                
                for(auto x:r->children) {
                    q.push(x);
                }
            }
            
            ans.push_back(v);
            v.clear();
            
        }
        
        return ans;
        
    }
};