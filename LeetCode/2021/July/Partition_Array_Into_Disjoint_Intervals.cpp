class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> v(n);
        vector<int> v1(n);
        v[n-1]=nums[n-1];
        v1[0]=nums[0];
        
        for(int i=n-2;i>=0;i--) {
            
            v[i]=min(nums[i],v[i+1]);
            
        }
        
        for(int i=1;i<n;i++) {
            
            v1[i]=max(v1[i-1],nums[i]);
            
        }
        
        for(int i=0;i<n-1;i++) {
            if(v1[i]<=v[i+1]) {
                cout<<nums[i]<<" ";
                return i+1;
            }
        }
        
        return v[n-1];
    }
};