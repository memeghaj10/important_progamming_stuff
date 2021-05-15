#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int N, vector<int> adj[]) 
	{
	   vector<int> indegree(N,0);
	   
	   queue<int> q;
	   
	   for(int i=0;i<N;i++) {
	       for(auto x:adj[i]) {
	           indegree[x]++;
	       }
	   }
	   
	   for(int i=0;i<N;i++) {
	       if(indegree[i]==0) {
	           q.push(i);
	       }
	   }
	   
	  int c=0;
	  
	  while(!q.empty()) {
	      
	        int node=q.front();
	        q.pop();
	        c++;
	        
	        for(auto x:adj[node]) {
	            indegree[x]--;
	            if(indegree[x]==0) {
	                q.push(x);
	            }
	        }
	  }
	   
	   if(c==N) {
	       return false;
	   }
	   
	   return true;
	   
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends