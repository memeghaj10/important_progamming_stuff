/*

Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.


Example 4:

Input: grid = [[1,1],[1,1]]
Output: 4
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100 


*/






class Solution {
public:
    
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector< vector< vector<int> > > dp(n , vector< vector<int> > (m, vector<int> (m,-1) ) );

        
        return solve(0,0,m-1,grid,dp);
        
    }
    
    int solve(int row,int c1,int c2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp) {
        
            if(c1<0||c1>=grid[0].size()||c2<0||c2>=grid[0].size()) {
                return 0;
            }
        
            if(dp[row][c1][c2]!=-1) {
                return dp[row][c1][c2];
            }
        
            int result=0;
            
            result+=grid[row][c1];
            if(c1!=c2) {
                result+=grid[row][c2];
            }
        
            if(row!=grid.size()-1) {
                
                int mx=0;
                
                for(int new_col1=c1-1;new_col1<=c1+1;new_col1++) {
                    for(int new_col2=c2-1;new_col2<=c2+1;new_col2++) {
                        mx=max(mx,solve(row+1,new_col1,new_col2,grid,dp));
                    }
                }
                
                result+=mx;
                
            }
        
        return dp[row][c1][c2]=result;
        
    }
};