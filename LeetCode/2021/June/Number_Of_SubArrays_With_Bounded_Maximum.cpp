class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       
        int n=nums.size();
        
        vector<int> v(n);
        
        for(int i=0;i<n;i++) {
            if(nums[i]>=left&&nums[i]<=right) {
                v[i]=1;
            }
            else if(nums[i]<left) {
                v[i]=0;
            }
            else {
                v[i]=-1;
            }
        }
        
        int ans=0;
        int i=0;
        int j=0;
        
        int l=-1;
        
        while(j<n) {
            
            if(v[j]==-1) {
                i=j+1;
            }
            else if(v[j]==1) {
                l=j;
                ans+=(l-i+1);
            } 
            else {
                ans+=max(0,l-i+1);
            }
            j++;
        }
        
        return ans;
        
    }
};