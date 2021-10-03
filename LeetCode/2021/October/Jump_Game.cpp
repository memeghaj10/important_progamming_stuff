class Solution {
public:
    bool canJump(vector<int>& nums) {
        
      int j=nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--) {
            if(i+nums[i]>=j) {
                j=i;
            }
        }
        
        return j==0;
    }
};