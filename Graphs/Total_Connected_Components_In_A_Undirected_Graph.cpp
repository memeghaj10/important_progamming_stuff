    /*
    
        This is a C++ Program to find the number of connected compnents  of a graph, using DFS.

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

    void dfs(int i,vector<int> adj[],int vis[]) {

        vis[i]=1;

        for(auto x:adj[i]) {
            if(vis[x]==0) {
                dfs(x,adj,vis);
            }
        }

    }


    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        int V,E;

        cin>>V>>E;

        vector<int> adj[V+1];

        for(int i=0;i<E;i++) {
            int a,b;
            cin>>a>>b;
            //cout<<a<<b;
            adj[a].eb(b);
           //cout<<adj[a][0];
        }

        int c=0;

        int vis[V+1];
        memset(vis,0,sizeof(vis));

        for(int i=1;i<V+1;i++) {
            if(vis[i]!=1) {
                c++;
                dfs(i,adj,vis);
            }
        }

        cout<<c;


        return 0;
    }