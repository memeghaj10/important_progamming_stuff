/*

Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.

Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

A binary matrix is a matrix with all cells equal to 0 or 1 only.

A zero matrix is a matrix with all cells equal to 0.

 

Example 1:


Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
Example 2:

Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We don't need to change it.
Example 3:

Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
Output: 6
Example 4:

Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix can't be a zero matrix
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 3
mat[i][j] is either 0 or 1.



*/








class Solution {
public:
    
    vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
    map<vector<vector<int>>,int> visited;
  
    
    bool all_zero(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]) {
                    return 0;
                }
            }
        }
      
        return 1;
        
    }
    
    void flip(int i,int j, vector<vector<int>>& mat) {
        
        mat[i][j]=!mat[i][j];
        
        for(int k=0;k<4;k++) {
            int x1=i+dirs[k].first;
            int y1=j+dirs[k].second;
            
            if(x1<0||x1>=mat.size()||y1<0||y1>=mat[0].size()) {
                continue;
            }
            
            mat[x1][y1]=!mat[x1][y1];
            
        }
        
    }
    
    
    int solve(vector<vector<int>>& mat) {
        
        if(all_zero(mat)) {
            return 0;
        }
        
        if(visited[mat]==-1) {
            return 9999;
        }
        
        if(visited[mat]) {
            return visited[mat];
        }
        
        visited[mat]=-1;
        
        int res=9999;
        
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[i].size();j++) {
                flip(i,j,mat);
               res=min(res,solve(mat));
                flip(i,j,mat);
            }
        }
            
        
        visited[mat]=1+res;
        
        return visited[mat];
        
    }
    
    
    
    int minFlips(vector<vector<int>>& mat) {
        
        int res=solve(mat);
        
        if(res==10000) {
            return -1;
        }
        
        return res;        
    }
};