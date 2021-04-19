class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       
        vector<long long int> dp(10006,0);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++) {
            dp[nums[i]]=1;
        }
        
        for(int i=0;i<10006;i++) {
            int c=0;
            for(int j=0;j<nums.size();j++) {
                if(i>=nums[j]) {
                    c+=dp[i-nums[j]];
                }
            }
            dp[i]+=c;
        }
        
        
        return dp[target];
    }
};