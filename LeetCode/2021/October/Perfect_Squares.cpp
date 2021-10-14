class Solution {
public:
    int numSquares(int n) {
        
        vector<int> v;
        
        for(int i=1;i<=sqrt(n);i++) {
            v.push_back(i*i);
        }
        
        int p=v.size();
        
       int  dp[n+1];
        
        dp[0]=0;
        
        for(int i=1;i<=n;i++) {
            dp[i]=INT_MAX;
            for(int j=0;j<p;j++) {
                
                if(v[j]<=i) {
                     dp[i]=min(dp[i],dp[i-v[j]]+1);
                }
            }
        }
        
        return dp[n];
        
    }
};