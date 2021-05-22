#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the number of islands.
    
    void bfs(int x,int y,vector<vector<int>>& vis,vector<vector<char>>& grid) {
        
        if(grid[x][y]!='1') {
            return;
        }
        
        vis[x][y]=1;
        grid[x][y]='*';
        
        int dx[]={1,0,0,-1,-1,1,1,-1};
        int dy[]={0,1,-1,0,-1,1,-1,1};
        
        for(int i=0;i<8;i++) {
          
                int vx=dx[i]+x;
                int vy=dy[i]+y;
                
                if(vx>=0&&vx<grid.size()&&vy>=0&&vy<grid[0].size()) {
                    bfs(vx,vy,vis,grid);
                }
                
            
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int c=0;
        
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j]&&grid[i][j]=='1') {
                    c++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        
        return c;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends