class Solution {
    int total;
    int target;
    vector<bool> used;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        total = accumulate(nums.begin(), nums.end(), 0);
        
        if (total % k != 0) {
            return false;
        }
        
        target = total / k;
        
        sort(nums.rbegin(), nums.rend());
        
        used.resize(nums.size(), false);
        
        return dfs(nums, 0, k, 0);
    }
    
    bool dfs(vector<int>& nums, int cur, int k, int sum) {
        if (k == 0) {
            return true;
        }
        
        if (sum > target) {
            return false;
        } else if (sum == target) {
            --k;
            return dfs(nums, 0, k, 0);
        }
        
        for (int i = cur; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                if (dfs(nums, i + 1, k, sum + nums[i])) {
                    return true;
                }
                used[i] = false;
            }
        }
        
        return false;
    }
};