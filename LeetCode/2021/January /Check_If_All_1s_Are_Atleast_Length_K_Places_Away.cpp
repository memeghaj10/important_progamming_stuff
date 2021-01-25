class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int l=0;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1) {
                l=i;
                break;
            }
        }
        
        for(int i=l+1;i<nums.size();i++) {
                if(nums[i]==1) {
                    if(i-l-1>=k) {
                        l=i;
                        continue;
                    }
                    
                    else {
                        return false;
                    }
                }    
        }   
        
        return true;
        
    }
};