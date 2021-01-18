class Solution {
public:
    int countVowelStrings(int n) {
        
            vector<vector<int>> dp(5,vector<int>(n));
        
            for(int i=0;i<5;i++) {
                dp[i][0]=1;
            }
        
            for(int i=1;i<n;i++) {
                for(int j=0;j<5;j++) {
                    for(int k=0;k<=j;k++) {
                        dp[j][i]+=dp[k][i-1];
                    }
                }
            }           
        
            int ans=0;        
        
            for(int i=0;i<5;i++) {
                    ans+=dp[i][n-1];
            }
        
        
            return ans;
        
        
    }
};