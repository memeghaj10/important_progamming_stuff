class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<int> dp(n);
        
        multiset<int> st;
        
        dp[0]=nums[0];
        st.insert(dp[0]);
        
        int j=0;
        
        for(int i=1;i<n;i++) {
            
            if(st.size()<k) {                
                dp[i]=nums[i]+*(st.rbegin());   
                st.insert(dp[i]);
            }
            
            else {                                
                dp[i]=nums[i]+*(st.rbegin());
                st.erase(st.lower_bound(dp[j]));
                j++;
                st.insert(dp[i]);   
            }
            
        }
        
        
        for(int i:dp) {
            cout<<i<<" ";
        }
        
        return dp[n-1];
        
    }
};