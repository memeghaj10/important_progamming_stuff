/*
There is an m by n grid with a ball.
Given the start coordinate (i,j) of the ball,
you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right).
However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
*/




class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
          
        int M=1e9+7;
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        dp[i][j]=1;
        
        int count=0;
        
        for(int moves=1;moves<=N;moves++) {
            
                vector<vector<int>> temp(m,vector<int>(n,0));
            
                for(int i=0;i<m;i++) {
                    for(int j=0;j<n;j++) {
                        if(i==0) {
                            count=(count+dp[i][j])%M;
                        }
                        if(i==m-1) {
                            count=(count+dp[i][j])%M;
                        }
                        
                        if(j==0) {
                            count=(count+dp[i][j])%M;
                        }
                        
                        if(j==n-1) {
                            count=(count+dp[i][j])%M;
                        }
                        
                        temp[i][j]=(
                            ((i>0?dp[i-1][j]:0)+(i<m-1?dp[i+1][j]:0))%M+
                            ((j>0?dp[i][j-1]:0)+(j<n-1?dp[i][j+1]:0))%M
                        )%M;
                        
                    }
                }
            dp=temp;
        }
        
        
        return count;
        
        
    }
};