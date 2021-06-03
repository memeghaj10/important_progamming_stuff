    /*
        
        Given a directed graph and a source node and destination node, we need to find how many edges we need to reverse in order to make at least 1 path from source node to destination node.

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

    vector<int> solve(int src,vector<pair<int,int>> adj[],int V) {

        vector<int> dist(V+1,INT_MAX);

        set<pair<int,int>> st;

        st.insert(make_pair(0,src));

        dist[src]=0;

        while(!st.empty()) {

            pair<int,int> p=*(st.begin());
            st.erase(st.begin());

            int u=p.second;

            for(auto x:adj[u]) {

                int v=x.first;
                int w=x.second;

                if(dist[v]>dist[u]+w) {
                    if(dist[v]!=INF) {
                        st.erase(st.find(make_pair(dist[v],v)));
                    }
                    dist[v]=dist[u]+w;
                    st.insert(make_pair(dist[v],v));
                }

            }

        }

        return dist;


    }

    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


    int V,E;
    cin>>V>>E;

    int src,dest;

    cin>>src>>dest;


    vector<pair<int,int>> adj[V+1];

    for(int i=0;i<E;i++) {

        int u,v;
        cin>>u>>v;

        adj[u].push_back(make_pair(v,0));
        adj[v].push_back(make_pair(u,1));

    }

    vector<int> dist;

    dist=solve(src,adj,V);

    if(dist[dest]==INT_MAX) {
        cout<<-1;
    }

    else {
        cout<<dist[dest];
    }


        return 0;
    }