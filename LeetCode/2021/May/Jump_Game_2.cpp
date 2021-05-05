class Solution {
public: 
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1) {
            return 0;
        }
        
        int interval=0;
        int max_reached=0;
        int ans=0;
        
        for(int i=0;i<n-1;i++) {
            max_reached=max(nums[i]+i,max_reached);
            
            if(i==interval) {
                ans++;
                interval=max_reached;
            }
        }
        
        return ans;
        
    }
};