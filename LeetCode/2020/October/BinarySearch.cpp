class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int y = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        if(nums[y]==target) {
            return y;
        }
        
        else {
            return -1;
        }
        
    }
};