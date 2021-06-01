        /*
    
        Problem
Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. The people of Byteland live happily along with the King.
The city has a unique architecture with total N houses. The King's Mansion is a very big and beautiful bungalow having address = 1. Rest of the houses in Byteland have some unique address, (say A), are connected by roads and there is always a unique path between any two houses in the city. Note that the King's Mansion is also included in these houses.

Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and Bob is supposed to find him.
Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.

Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, then he surely finds Oliver.

Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.

The queries can be of the following two types:
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion

INPUT :
The first line of the input contains a single integer N, total number of houses in the city. Next N-1 lines contain two space separated integers A and B denoting a road between the houses at address A and B.
Next line contains a single integer Q denoting the number of queries.
Following Q lines contain three space separated integers representing each query as explained above.

OUTPUT :
Print "YES" or "NO" for each query depending on the answer to that query.

CONSTRAINTS :
1 ≤ N ≤ 10^5
1 ≤ A,B ≤ N
1 ≤ Q ≤ 5*10^5
1 ≤ X,Y ≤ N

NOTE :
Large Input size. Use printf scanf or other fast I/O methods.

Sample Input
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1

Sample Output
YES
NO
NO
NO
YES


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

    int timer=0;
    vector<int> adj[1000001];

    vector<int> vis;
    vector<int> start_time;
    vector<int> end_time;

    void dfs(int node) {

        vis[node]=1;
        timer++;
        start_time[node]=timer;


        for(auto x:adj[node]) {
            if(!vis[x]) {
                dfs(x);
                timer++;
            }
        }

        timer++;
        end_time[node]=timer;

    }

    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        int n;
        cin>>n;


        for(int i=0;i<n-1;i++) {
            int u,v;
            cin>>u>>v;
            adj[u].eb(v);
            adj[v].eb(u);
        }

        vis=vector<int>(n+1,0);
        start_time=vector<int>(n+1,0);
        end_time=vector<int>(n+1,0);


        dfs(1);

        int q;
        cin>>q;

        while(q--) {

            int t,x,y;
            cin>>t>>x>>y;

            if(t==1) {
                swap(y,x);
            }
          

             if(start_time[x]<=start_time[y]&&end_time[x]>=end_time[y]) {
                    cout<<"YES"<<endl;
              }
              else {
                    cout<<"NO"<<endl;
              }
        }



        return 0;
    }