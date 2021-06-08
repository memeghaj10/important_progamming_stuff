    /*

    A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) of the graph, either ‘u’ or ‘v’ is in the vertex cover.
    Although the name is Vertex Cover, the set covers all edges of the given graph.
    Given an undirected graph, the vertex cover problem is to find minimum size vertex cover. 

    */


    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;

    void printVertexCover(int V,vector<int> adj[]) {

        bool vis[V];
        memset(vis,0,sizeof(vis));

        for(int u=0;u<V;u++) {

            if(vis[u]==false) {

                for(auto x:adj[u]) {

                    if(vis[u]==false) {

                        vis[v]=true;
                        vis[u]=true;

                        break;
                    }

                }

            }

        }

        for(int i=0;i<V;i++) {
            if(vis[i]) {
                cout<<i<<" ";
            }
        }


    }


    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        int V;
        cin>>V;

        int E;
        cin>>E;

        vector<int> adj[V];

        for(int i=0;i<E;i++) {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        printVertexCover(V,adj);



        return 0;
    }