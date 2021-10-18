class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, TreeNode*> parents; 
        unordered_map<int, int> depths; 
        
        function<void(TreeNode*, int, int, TreeNode*, int)> dfs = [&](TreeNode* root, int x, int y, 
                                                                      TreeNode* parent, int depth)
        {
            if (!root) { return; }
            else if (root->val == x) {
                parents[x] = parent;
                depths[x] = depth;
            } else if (root->val == y) {
                parents[y] = parent;
                depths[y] = depth;
            }
            
            if (parents.count(x) && parents.count(y)) { return ; }
            
            dfs(root->left, x, y, root, depth + 1); 
            dfs(root->right, x, y, root, depth + 1);
        };
        
        dfs(root, x, y, nullptr, 0);
        return depths[x] == depths[y] && parents[x] != parents[y];
    }
};