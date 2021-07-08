class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(nums1[i-1]==nums2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=0;
                }
            }
        }
        
        int mini=INT_MIN;
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                mini=max(mini,dp[i][j]);
            }
        }
        
        return mini;
        
    }
};