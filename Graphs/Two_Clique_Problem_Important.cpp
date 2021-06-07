/*

A Clique is a subgraph of graph such that all vertcies in subgraph are completely connected with each other. Given a Graph, find if it can be divided into two Cliques.

Examples:

Input : G[][] =   {{0, 1, 1, 0, 0},
                  {1, 0, 1, 1, 0},
                  {1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {0, 0, 0, 1, 0}};
Output : Yes


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

    const int V=5;

    bool isbipartite_util(int G[][V],int src,vector<int>& colorArr) {

        colorArr[src]=1;

        queue<int> q;
        q.push(src);

        while(!q.empty()) {

            int u=q.front();
            q.pop();

            for(int v=0;v<V;v++) {
                if(G[u][v]&&colorArr[v]==-1) {
                    colorArr[v]=1-colorArr[u];
                    q.push(v);
                }
                else if(G[u][v]&&colorArr[v]==colorArr[u]) {
                    return false;
                }
            }

        }

        return true;


    }

    bool isbipartite(int GC[][V]) {

        vector<int> colorArr(V,-1);

        for(int i=0;i<V;i++) {
            if(colorArr[i]==-1) {
                if(isbipartite_util(GC,i,colorArr)==false) {
                    return false;
                }
            }
        }

        return true;

    }


    bool can_be_clique(int G[][V]) {

        int GC[V][V];

        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                GC[i][j]=(i!=j)?!G[i][j]:0;
            }
        }

        return isbipartite(GC);

    }


    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

       int G[5][5];

        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                cin>>G[i][j];
            }
        }

        if(can_be_clique(G)) {
            cout<<"YES";
        }

        else {
            cout<<"NO";
        }


    }