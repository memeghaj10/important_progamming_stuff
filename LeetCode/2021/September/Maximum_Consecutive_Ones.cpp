class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        vector<int> c;
        
        
        int f=0;
        
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1) {
                f++;
            }
            
            else {
                c.push_back(f);
                f=0;
            }
        }
        
        c.push_back(f);
        
        
        return *max_element(c.begin(),c.end());
        
    }
};