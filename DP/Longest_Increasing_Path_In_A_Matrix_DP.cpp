/*

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).


Input: matrix = [[9,9,4],
                 [6,6,8],
                 [2,1,1]]

Output: 4

Explanation: The longest increasing path is [1, 2, 6, 9].

*/


class Solution {
public:
    
    int dp[201][201];
    
    int dfs(vector<vector<int>> &matrix,int i,int j,int pre) {
        
            if(i<0||j<0||i==matrix.size()||j==matrix[0].size()||pre>=matrix[i][j]) {
                return 0;
            }
        
            if(dp[i][j]) {
                return dp[i][j];
            }
        
            int p=matrix[i][j];
            matrix[i][j]=-1;
            int l=dfs(matrix,i-1,j,p);
            int r=dfs(matrix,i+1,j,p);
            int u=dfs(matrix,i,j-1,p);
            int d=dfs(matrix,i,j+1,p);
        
            matrix[i][j]=p;
        
            return dp[i][j]=max({l,r,u,d})+1;
                
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
            memset(dp,0,sizeof(dp));
        
            int n=matrix.size();
            int m=matrix[0].size();
        
            int ans=1;
        
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    ans=max(ans,dfs(matrix,i,j,-1));
                }
            }
        
        return ans;
        
    }
};