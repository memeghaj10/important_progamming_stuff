class Solution {
public:
    /*
    BFS with coloring algorithm
    color: 0 is not visited;
    color: 1 is color ->1
    color: 2 is color ->2
    */
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        for(int i=0;i<graph.size();i++){
           
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        int color[graph.size()];
        memset(color,0,sizeof(color));
      
        for(int p=0;p<graph.size();p++){
       if(color[p]==0){
            queue <int> q;
        q.push(p);
            while(!q.empty()){
                int i=q.front();
                q.pop();
            if(color[i]==0){
                int c1=0,c2=0;
                for(int j=0;j<adj[i].size();j++){
                    if(color[adj[i][j]]==1)
                        c1=1;
                    else if(color[adj[i][j]]==2)
                        c2=1;
                }
                if(c1==1&&c2==1)
                    return false;
                if(c1==1){
                    color[i]=2;
                     for(int j=0;j<adj[i].size();j++){
                         if(color[adj[i][j]]==0)
                             q.push(adj[i][j]);
                         color[adj[i][j]]=1;
                     }
                }
               else if(c2==1){
                    color[i]=1;
                     for(int j=0;j<adj[i].size();j++){
                         if(color[adj[i][j]]==0)
                             q.push(adj[i][j]);
                         color[adj[i][j]]=2;
                     }
                }
                else {
                    color[i]=1;
                     for(int j=0;j<adj[i].size();j++){
                         if(color[adj[i][j]]==0)
                             q.push(adj[i][j]);
                         color[adj[i][j]]=2;
                     }
                }
                
            }
            else if(color[i]==1) {
                  for(int j=0;j<adj[i].size();j++){
                      if(color[adj[i][j]]==1)
                          return false;
                      if(color[adj[i][j]]==0)
                             q.push(adj[i][j]);
                         color[adj[i][j]]=2;
                     }
            }
            else {
                 for(int j=0;j<adj[i].size();j++){
                      if(color[adj[i][j]]==2)
                          return false;
                     if(color[adj[i][j]]==0)
                             q.push(adj[i][j]);
                         color[adj[i][j]]=1;
                     }
            }
            }
        }
        }
        return true;
    }
};