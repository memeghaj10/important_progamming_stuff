    
   
    #include <bits/stdc++.h>

    #define f first
    #define s second
    
    using namespace std;

    void toposort(int node,int& vis[],stack<int>& st,vector<pair<int,int>> adj[]) {

        vis[node]=1;

        for(auto x:adj[node]) {
            if(!vis[x.f]) {
                toposort(x.f,vis,st,adj);
            }
        }

        st.push(node);

    }

    void shortest_path(int src,int n,vector<pair<int,int>> adj) {

        int vis[n]={0;
        stack<int> st;

        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                toposort(i,vis,st,adj);
            }
        }

        int dist[n];
        for(int i=0;i<n;i++) {
            dist[i]=INT_MAX;
        }

        while(!st.empty()) {

            int node=st.top();
            st.pop();

            if(dist[node]!=INT_MAX) {

                for(auto x:adj[node]) {
                    if(dist[node]+x.s<dist[x.f]) {
                        dist[x.f]=dist[node]+x.s;
                    }
                }

            }

        }

      for(int i=0;i<n;i++) {
        if(dist[i]==1e9) {
            cout<<"INT_MAX"<<" ";
        }
        else {
            cout<<dist[i]<<" ";
        }
      }

    }


    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        int v,e;

        cin>>v>>e;

        vector<pair<int,int>> adj[v];

        for(int i=0;i<e;i++) {
            int a,b,d;
            cin>>a>>b>>d;

            adj[a].push_back(make_pair(b,d));
        }

        shortest_path(0,v,adj);


        return 0;
    }