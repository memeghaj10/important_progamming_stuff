class Solution {
public:
    
    void dfs(int i,int j,int n,int m,vector<vector<int>>& vis,vector<vector<int>>& grid,int& temp) {
        
        temp++;
        
        vis[i][j]=1;
        
        if(i-1>=0&&!vis[i-1][j]&&grid[i-1][j]) {
            dfs(i-1,j,n,m,vis,grid,temp);
        }
        
        if(i+1<n&&!vis[i+1][j]&&grid[i+1][j]) {
            dfs(i+1,j,n,m,vis,grid,temp);
        }
        
        if(j-1>=0&&!vis[i][j-1]&&grid[i][j-1]) {
            dfs(i,j-1,n,m,vis,grid,temp);
        }
        
        if(j+1<m&&!vis[i][j+1]&&grid[i][j+1]) {
            dfs(i,j+1,n,m,vis,grid,temp);
        }
        
        return;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans=0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                
                if(!vis[i][j]&&grid[i][j]) {
                    int temp=0;
                    dfs(i,j,n,m,vis,grid,temp);
                    ans=max(ans,temp);
                    //cout<<temp<<endl;
                }
            }
        }
        
        return ans;
        
    }
};