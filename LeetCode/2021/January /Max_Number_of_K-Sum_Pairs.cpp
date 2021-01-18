class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
            map<int,int> mp;
        
            mp[nums[0]]++;
        
            int n=nums.size();        
            int c=0;
        
            for(int i=1;i<n;i++) {                
                    if(mp[k-nums[i]]>=1) {
                        c++;
                        mp[k-nums[i]]--;
                    }
                
                    else {
                        mp[nums[i]]++;
                    }                
            }
        
            return c;
        
    }
};