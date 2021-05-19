class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
       sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        int y=nums[n/2];
        
        int sum=0;
        
        for(int i=0;i<n;i++) {
            sum+=abs(nums[i]-y);
        }
        
        return sum;
        
    }
};