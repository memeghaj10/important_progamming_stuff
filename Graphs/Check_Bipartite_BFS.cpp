#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:


    bool check(int v,vector<int> adj[],vector<int>& color) {
        
        queue<int> q;
        q.push(v);
        color[v]=1;
        
        while(!q.empty()) {
            
                int node=q.front();
                q.pop();
                
                for(auto x:adj[node]) {
                    if(color[x]==-1) {
                        color[x]=1-color[node];
                        q.push(x);
                    }
                    else if(color[x]==color[node]) {
                        return false;
                    }
                }
            
        }
        
        return true;
        
    }

	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++) {
	        if(color[i]==-1) {
	            if(!check(i,adj,color)) {
	                return false;
	            }
	        }
	    }
	    
	    return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends