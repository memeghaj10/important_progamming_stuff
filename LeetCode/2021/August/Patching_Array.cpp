class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long patches = 0, count = 1, i = 0, sz = nums.size();
        while (count <= n) {
            
            if (i < sz && nums[i] <= count) count += nums[i++];
            
            else {
                count *= 2;
                patches++;
            }
        }
        
        return patches;
    }
};