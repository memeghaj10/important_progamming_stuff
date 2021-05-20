
 // } Driver Code Ends



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node, stack<int>& st,vector<int>& vis,vector<int> adj[]) {
	    
	       vis[node]=1;
	       
	        for(auto x:adj[node]) {
	            if(!vis[x]) {
	                dfs(x,st,vis,adj);
	            }
	        }
	        
	        st.push(node);
	    
	}
	
	
	void revDFS(int node,vector<int>& vis,vector<int> adj[]) {
	    
	    vis[node]=1;
	    for(auto x:adj[node]) {
	        if(!vis[x]) {
	            revDFS(x,vis,adj);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
       
       stack<int> st;
       vector<int> vis(V,0);
       
       for(int i=0;i<V;i++) {
           if(!vis[i]) {
               dfs(i,st,vis,adj);
           }
       }
       
       vector<int> transpose[V];
       
       for(int i=0;i<V;i++) {
           vis[i]=0;
           for(auto x:adj[i]) {
               transpose[x].push_back(i);
           }
       }
       
       int ans=0;
       
       while(!st.empty()) {
            
                int node=st.top();
                st.pop();
                
                if(!vis[node]) {
                    ans++;
                    revDFS(node,vis,transpose);
                }
       }
       
       return ans;
       
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends