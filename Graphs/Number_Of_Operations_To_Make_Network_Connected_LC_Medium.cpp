class Solution {
public:
    
    int cables;
    
    void parent_dfs(int node,int parent,vector<int>& vis,vector<int> adj[]) {
        
        vis[node]=1;
        
        for(auto x:adj[node]) {
            if(!vis[x]) {
                parent_dfs(x,node,vis,adj);
            }
            else if(parent!=x&&parent!=-1) {
                cables++;
            }
        }
        
    }
    
    void dfs(int node,vector<int>& vis,vector<int> adj[]) {
        
        vis[node]=1;
        
        for(auto x:adj[node]) {
            if(!vis[x]) {
                dfs(x,vis,adj);
            }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        
        for(int i=0;i<connections.size();i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> vis(n,0);
        
        int components=0;
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                components++;
                dfs(i,vis,adj);
            }
        }
        
        int no_of_subnetworks_remaining=components-1;
        
     
        
        if(no_of_subnetworks_remaining==0) {
            return 0;
        }
        
        vis=vector<int>(n,0);
        
        cables=0;
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                parent_dfs(i,-1,vis,adj);
            }
        }
        
        
        if(cables>=no_of_subnetworks_remaining) {
            return no_of_subnetworks_remaining;
        }
        
        return -1;
        
    }
};