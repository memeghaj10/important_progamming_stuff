#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
         int parent[V+1]; 
          
        int key[V+1]; 
          
        bool mstSet[V+1]; 
      
        for (int i = 0; i <= V; i++) 
            key[i] = INT_MAX, mstSet[i] = false; 
        
         priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        
        key[0]=0;
        parent[0]=-1;
        pq.push({0,0});
        
        while(!pq.empty()) {
            
                int u=pq.top().second;
                pq.pop();
                mstSet[u]=1;
                
                for(auto x:adj[u]) {
                    int v=x[0];
                    int wt=x[1];
                    
                    if(mstSet[v]==false&&wt<key[v]) {
                        parent[v]=u;
                        key[v]=wt;
                        pq.push({key[v],v});
                    }
                    
                }
            
        }
    
    
    int sum=0;
    
    for(int i=1;i<=V;i++) {
        if(key[i]!=INT_MAX) {
            sum+=key[i];
        }
    }
    
    return sum;
    
        
    }
    
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends