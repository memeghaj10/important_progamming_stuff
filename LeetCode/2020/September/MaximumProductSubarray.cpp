class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int minprd=nums[0];
        int maxprd=nums[0];
        int ret=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]<0) {swap(minprd,maxprd);}
            
            minprd=min(minprd*nums[i],nums[i]);
            maxprd=max(maxprd*nums[i],nums[i]);
            
            ret=max(maxprd,ret);
        }
        
        
        return ret;
        
    }
};