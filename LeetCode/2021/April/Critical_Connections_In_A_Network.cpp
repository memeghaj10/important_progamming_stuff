class Solution {
public:
    
    using Graph=std::vector<vector<int>>;
    
    Graph toGraph(int n,const vector<vector<int>>& connections) {
        
        Graph res(n);
        
        for(const auto& v:connections) {
            res[v[0]].push_back(v[1]);
            res[v[1]].push_back(v[0]);
        }
        
        return res;
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        const auto g=toGraph(n,connections);
        vector<vector<int>> res;
        vector<bool> visited(n);
        vector<int> tin(n);
        vector<int> tup(n);
        int t=0;
        
        function<void(int,int)> dfs;
        dfs=[&](int v,int p) {
            visited[v]=true;
            tin[v]=tup[v]=t++;
            
            for(const auto to:g[v]) {
                if(to==p) {
                    continue;
                }
                if(visited[to]) {
                    tup[v]=min(tup[v],tin[to]);
                }
                else {
                    dfs(to,v);
                    tup[v]=min(tup[v],tup[to]);
                }
                if(tin[v]<tup[to]) {
                    res.push_back({v,to});
                }
            }
        };
          
        
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i,-1);
            }
        }
        
        return res;
        
    }
};