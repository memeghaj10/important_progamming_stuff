class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        
        int dp[n][n];

        //dp[i][j]=max effective score, in the range(i,j) for the player.
        
        for(int i=n-1;i>=0;i--) {
            dp[i][i]=nums[i];
            for(int j=i+1;j<n;j++) {
                int a=nums[i]-dp[i+1][j];//picking first element in the range, leaving the (i+1,j) range for the next player
                int b=nums[j]-dp[i][j-1];//picking last element in the range , leaving the (i,j-1) range for the next player
                dp[i][j]=max(a,b);
            }
        }
        
        return dp[0][n-1]>=0;   //if the net total effective score difference between the first player to move and the second player is >=0,
                                // then the second player is effective.
        
    }
};