   
    
    #include <bits/stdc++.h>
  
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;
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
            cin>>a>>b;

            adj[a].eb(b);
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>()> pq;

        vector<int> dis(ev,INT_MAX);

        dis[0]=0;
        pq.push_back(make_pair(0,0));

        while(!pq.empty()) {

            int dist=pq.top().first;
            int node=pq.top().second;

            pq.pop();

            for(auto x:adj[node]) {

                int child=x.f;
                int child_dist=x.s;

                if(dis[child]>dis[node]+child_dist) {
                    dis[child]=dis[node]+child_dist;
                    pq.push(make_pair(dis[child],child));
                }

            }


        }


        for(int i:dis) {
            cout<<i<<" ";
        }

      
        return 0;
    }