class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        vector<vector<int>> dp;
        dp=triangle;
        
        int n=dp.size();
            
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<dp[i].size();j++) {
                dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
        
    }
};