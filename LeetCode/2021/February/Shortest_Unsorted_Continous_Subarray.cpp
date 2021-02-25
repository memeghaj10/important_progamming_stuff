class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
            vector<int> v;
        
            int n=nums.size();
        
            v=nums;
        
            sort(v.begin(),v.end());
        
            int l=0;
            int r=0;
        
            for(int i=0;i<n;i++) {
                if(nums[i]!=v[i]) {
                    nums[i]=INT_MAX;
                }
            }
        
            for(int i=0;i<n;i++) {
                if(nums[i]==INT_MAX) {
                    l=i;
                    break;
                }
            }
        
            for(int i=n-1;i>=0;i--) {
                if(nums[i]==INT_MAX) {
                    r=i;
                    break;
                }
            }
        
            if(r==l) {
                return r-l;
            }
        
            return r-l+1;
        
    }
};