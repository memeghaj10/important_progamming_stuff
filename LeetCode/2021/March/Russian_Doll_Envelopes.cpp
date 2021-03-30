class Solution {
public:
    
    static bool comp(vector<int> a,vector<int> b) {
        
            if(a[1]==b[1]) {
                return a[0]<b[0];
            }
        
        return a[1]<b[1];
        
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n=envelopes.size();
        
        sort(envelopes.begin(),envelopes.end(),comp);
        
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1]) {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};