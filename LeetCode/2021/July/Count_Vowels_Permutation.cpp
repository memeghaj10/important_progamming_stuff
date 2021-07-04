class Solution {
public:
    int countVowelPermutation(int n) {
        
        int mod=1000000007;
        long long int dp[n+1][5];
        
        for(int i=0;i<5;i++) {
            dp[1][i]=1;
        }
        
        int a=0,e=1,i1=2,o=3,u=4;
        
        for(int i=2;i<n+1;i++) {
            dp[i][a]=dp[i-1][e]%mod;
            dp[i][e]=(dp[i-1][a]%mod+dp[i-1][i1]%mod)%mod;
            dp[i][i1]=(dp[i-1][a]%mod+dp[i-1][e]%mod+dp[i-1][o]%mod+dp[i-1][u]%mod)%mod;
            dp[i][o]=(dp[i-1][i1]%mod+dp[i-1][u]%mod)%mod;
            dp[i][u]=(dp[i-1][a])%mod;
        }
        
        return (dp[n][a]%mod+dp[n][e]%mod+dp[n][i1]%mod+dp[n][o]%mod+dp[n][u]%mod)%mod;
        
    }
};