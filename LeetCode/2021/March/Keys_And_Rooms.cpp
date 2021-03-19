class Solution {
public:
    
    void dfs(int i,vector<vector<int>> rooms,vector<int>& vis) {
        
            vis[i]=1;
            
            for(int j:rooms[i]) {
                if(vis[j]==-1) {
                    dfs(j,rooms,vis);
                }
            }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int> vis(n,-1);
        
        dfs(0,rooms,vis);
        
        return count(vis.begin(),vis.end(),-1)==0;
        
    }
};