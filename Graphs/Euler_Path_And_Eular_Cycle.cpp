
/*

There are n nodes and m bridges in between these nodes. Print the possible path through each node using each edges (if possible), traveling through each edges only once.
 

*/

#include<bits/stdc++.h>
using namespace std

 // } Driver Code Ends
class Solution {
public:

    void dfs(int v,bool visited[],vector<int> adj[]) {
        visited[v]=true;
        for(auto x:adj[v]) {
            if(!visited[x]) {
                dfs(x,visited,adj);
            }
        }
    }

    bool isConnected(int V,vector<int> adj[]) {
        
      bool visited[V];int i;
      
      for( i=0;i<V;i++) {
          visited[i]=false;
      }
      
      for(i=0;i<V;i++) {
          if(adj[i].size()!=0) {
              break;
          }
      }
      if(i==V) {
          return true; 
      }
      
        dfs(i,visited,adj);
          

      for(i=0;i<V;i++) {
          if(visited[i]==false&&adj[i].size()>0) {
              return false;
          }
      }
      
      return true;
        
    }

	int isEularCircuit(int V, vector<int>adj[]){
	   
	   if(isConnected(V,adj)==false) {
	       return 0;
	   }
	   
	   int odd=0;
	   
	   for(int i=0;i<V;i++) {
	       if(adj[i].size()&1) {
	           odd++;
	       }
	   }
	   
	   if(odd>2) {
	       return 0;
	   }
	   
	   return (odd)?1:2;
	   
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
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends