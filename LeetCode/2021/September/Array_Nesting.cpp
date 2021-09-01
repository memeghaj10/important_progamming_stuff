class Solution {
public:
    int arrayNesting(vector<int>& nums) {
       
        int n=nums.size();
        
        vector<int> v(n,0);
        
        int ans=1;
        
        for(int i=0;i<n;i++) {
            if(v[i]==0) {
                
                set<int> st;
                v[i]=1;
                
                st.insert(nums[i]);
                int y=nums[i];
                
                while(st.find(nums[y])==st.end()) {
                    st.insert(nums[y]);
                    y=nums[y];
                    v[y]=1;
                }
                
                ans=max(ans,(int)st.size());
                
            }
        }
        
        return ans;
        
    }
};