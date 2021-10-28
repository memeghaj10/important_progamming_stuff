class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>> ans;
        
        if(n<3) {
            return ans;
        }
        
        sort(nums.begin(),nums.end()); 
        
        map<vector<int>,int> mp;
        
        for(int i=0;i<n-2;i++) {
         
            int j=i+1;
            int k=n-1;
            
            while(j<k) {
                
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==0) {
                    mp[{nums[i],nums[j],nums[k]}]++;
                    j++;
                    k--;
                } 
                
                if(sum>0) {
                    k--;
                }
                
                if(sum<0) {
                    j++;
                }
                
            }
            
        }
        
        for(auto x:mp) {
            ans.push_back(x.first);
        }
        
        return ans;
    }
};