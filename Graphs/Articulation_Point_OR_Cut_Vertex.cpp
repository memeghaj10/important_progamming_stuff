 
    #include <bits/stdc++.h>

    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;

    void dfs(int node,int parent,int vector<int>& vis,vector<int>& tin,vector<int>& low,int &timer,vector<int> adj[],vector<int>& isArticulation) {

        vis[node]=1;
        tin[node]=low[node]=timer++;
        int child=0;

        for(auto it:adj[node]) {

            if(it==parent) {
                continue;
            }

            if(!vis[it]) {

                dfs(it,node,vis,tin,low,timer,adj);
                low[node]=min(low[node],low[it]);

                if(low[it]<tin[node]) {
                    cout<<node<<" "<<it<<endl;
                }
                child++;

            }

            else {
                low[node]=min(low[node],tin[it]);
            }

        }


        if(parent==-1&&child>1) {
            isArticulation[node]=1;
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

        vector<int> adj[v];

        for(int i=0;i<e;i++) {
            int u,v;
            cin>>u>>v;
            adj[u].eb(v);
            adj[v].eb(u);
        }

        vector<int> tin(v,-1);
        vector<int> low(v,-1);
        vector<int> vis(v,0);
        vector<int> isArticulation(v,0);

        int timer=0;

        for(int i=0;i<v;i++) {
            if(!vis[i]) {
                dfs(i,-1,vis,tin,low,timer,adj,isArticulation);
            }
        }

        for(int i=0;i<v;i++) {
            if(isArticulation[i]==1) {
                cout<<i<<endl;
            }
        }


        return 0;
    }