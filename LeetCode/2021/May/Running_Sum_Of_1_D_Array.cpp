class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int pre=0;
        
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++) {
            pre+=nums[i];
            ans.push_back(pre);
        }
        
        return ans;
        
    }
};