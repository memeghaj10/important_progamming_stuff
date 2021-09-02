class Solution {
public:
    vector<TreeNode*> rec(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) return {NULL};
        
        if (start == end) return {new TreeNode(start)};
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = rec(start, i-1), right = rec(i+1, end);
            
            for (auto l : left)
                for (auto r : right)
                    res.push_back(new TreeNode(i, l, r));
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res = rec(1, n);
        return res;
    }
};