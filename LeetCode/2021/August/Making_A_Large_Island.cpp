class Solution {
public:
    
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis,int &c) {
        
        vis[i][j]=1;
        c++;
        
        if(i-1>=0&&grid[i-1][j]&&!vis[i-1][j]) {
            dfs(i-1,j,n,m,grid,vis,c);
        }
        
        if(i+1<n&&grid[i+1][j]&&!vis[i+1][j]) {
            dfs(i+1,j,n,m,grid,vis,c);
        }
        
        if(j-1>=0&&grid[i][j-1]&&!vis[i][j-1]) {
            dfs(i,j-1,n,m,grid,vis,c);
        }
        
        if(j+1<m&&grid[i][j+1]&&!vis[i][j+1]) {
            dfs(i,j+1,n,m,grid,vis,c);
        }
        return;
        
    }
    
    void rev_dfs(int i,int j,int n,int m,vector<vector<pair<int,int>>>& parent,vector<vector<int>>& grid,int px,int py,vector<vector<int>>& vis1) {
        
        parent[i][j]=make_pair(px,py);
        vis1[i][j]=1;
        
        //cout<<parent[i][j].first<<" "<<parent[i][j].second<<endl;
        
         if(i-1>=0&&grid[i-1][j]&&!vis1[i-1][j]) {
            rev_dfs(i-1,j,n,m,parent,grid,px,py,vis1);
        }
        
        if(i+1<n&&grid[i+1][j]&&!vis1[i+1][j]) {
            rev_dfs(i+1,j,n,m,parent,grid,px,py,vis1);
        }
        
        if(j-1>=0&&grid[i][j-1]&&!vis1[i][j-1]) {
            rev_dfs(i,j-1,n,m,parent,grid,px,py,vis1);
        }
        
        if(j+1<m&&grid[i][j+1]&&!vis1[i][j+1]) {
            rev_dfs(i,j+1,n,m,parent,grid,px,py,vis1);
        }
        return;
        
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> vis1(n,vector<int>(m,0));
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,make_pair(-1,-1)));
       
    
        map<pair<int,int>,int> mp;
        mp[make_pair(-1,-1)]=0;
        
        vector<int> temp;
        
       for(int i=0;i<n;i++) {
           for(int j=0;j<m;j++) {
                if(grid[i][j]==1&&vis[i][j]==0){
                    int c=0;
                    dfs(i,j,n,m,grid,vis,c);
                    temp.push_back(c);
                    mp[make_pair(i,j)]=c;
                   rev_dfs(i,j,n,m,parent,grid,i,j,vis1);
                }
            }
       }
   
        int ans=0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                
                if(vis[i][j]==0) {
                    
                    set<pair<int,int>> st;
                    
                    if(i-1>=0) {
                        st.insert(parent[i-1][j]);
                    }
                    if(i+1<n) {
                        st.insert(parent[i+1][j]);
                    }
                    if(j-1>=0) {
                        st.insert(parent[i][j-1]);
                    }
                    if(j+1<m) {
                        st.insert(parent[i][j+1]);
                    }
                    
                    int t=0;
                    
                    for(auto x:st) {
                        t+=mp[x];
                    }
                    
                    ans=max(ans,t+1);
                    
                }
                
            }
        }
        
        if(ans==0) {
            int mx=*max_element(temp.begin(),temp.end());
            if(mx==n*m) {
                return mx;
            }
            return mx+1;
        }
        
        return ans;
        
            
    }
};