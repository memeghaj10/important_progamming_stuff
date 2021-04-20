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
    
    void rec(Node* root) {
        
        ans.push_back(root->val);
        
        for(auto i:root->children) {
            rec(i);
        }
        
    }
    
    
    vector<int> preorder(Node* root) {
        
        if(!root) {
            return ans;
        }
        
        rec(root);
        return ans;
    }
    
private:
    vector<int> ans;
};