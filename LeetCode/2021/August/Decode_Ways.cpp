class Solution {
public:
    int numDecodings(string s) {
     
        int n=s.size();       
     
        int dp[n+1];
        
        memset(dp,0,sizeof(dp));
         dp[0]=1;
        
        
        if(s[0]=='0') {
            return 0;
        }
        
        for(int i=1;i<=n;i++) {
            
            if(s[i-1]>'0') {
                dp[i]=dp[i-1];
            }
            
            if(i>=2&&(s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<'7'))) {
                dp[i]+=dp[i-2];
            }
            
        }
        
        return dp[n];
        
        
    }
};