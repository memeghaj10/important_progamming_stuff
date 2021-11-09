class Solution {
public:
    int numTrees(int n) {
        
        if(n==1) {
            return 1;
        }
        
        else if(n==2) {
            return 2;
        }
        
        vector<int> dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++) {
            
            int curr=0;
            curr+=dp[i-1];
            
            for(int j=i-1;j>=1;j--) {
                curr+=(dp[i-j]*dp[j-1]);
            }
            
            dp[i]=curr;
            
        }
        
        return dp[n];
    }
};