    /*

     
Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph.
The longest path problem for a general graph is not as easy as the shortest path problem because the longest path problem doesn’t have optimal substructure property. In fact, the Longest Path problem is NP-Hard for a general graph. However, the longest path problem has a linear time solution for directed acyclic graphs. The idea is similar to linear time solution for shortest path in a directed acyclic graph., we use Topological Sorting. 
We initialize distances to all vertices as minus infinite and distance to source as 0, then we find a topological sorting of the graph. Topological Sorting of a graph represents a linear ordering of the graph (See below, figure (b) is a linear representation of figure (a) ). Once we have topological order (or linear representation), we one by one process all vertices in topological order. For every vertex being processed, we update distances of its adjacent using distance of current vertex.
Following figure shows step by step process of finding longest paths.

Following is complete algorithm for finding longest distances. 
1) Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source vertex. Here NINF means negative infinite. 
2) Create a toplogical order of all vertices. 
3) Do following for every vertex u in topological order. 
………..Do following for every adjacent vertex v of u 
………………if (dist[v] < dist[u] + weight(u, v)) 
………………………dist[v] = dist[u] + weight(u, v) 


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

    void topo_sort(int v,vector<int>& vis,stack<int>& st) {

        vis[v]=1;

        for(auto x:adj[v]) {
            if(!vis[x.f]) {
                topo_sort(x.f,vis,st);
            }
        }

        st.push(v);

    }

    void longest_path(int v,stack<int>& st,vector<int>& vis,vector<pair<int,int>> adj[]) {

        for(int i=1;i<v+1;i++) {
            if(!vis[i]) {
                topo_sort(i,vis,st);
            }
        }

        int dist[v+1];

        for(int i=0;i<v+1;i++) {
            dist[i]=NINF;
        }

        dist[src]=0;

        while(!st.empty()) {

            int u=st.top();
            st.pop();

            if(dist[u]!=NINF){

                for(auto x:adj[u]) {

                    if(dist[x.f]<dist[u]+x.s) {
                        dist[x.f]=dist[u]+x.s;
                    }

                }

            }

        }

        for(int i=1;i<=v;i++) {
            if(dist[i]!=NINF) {
                cout<<dist[i]<<" ";
            }
            else {
                cout<<"INF ";
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

       int src;
       cin>>src;

       vector<pair<int,int>> adj[v+1];

       for(int i=0;i<e;i++) {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].eb(mp(v,w));
       }

       stack<int> st;

       vector<int> vis(0,V+1);

       longest_path(src,st,vis,adj);


        return 0;
    }