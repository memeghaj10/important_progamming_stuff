    
 void BFS(vector<int> adj[],int N,int src) {

        int dist[N];

        for(int i=0;i<N;i++) {
            dis[i]=INT_MAX;
        }

        queue<int> q;
        q.push(src);

        dist[src]=0;

        while(!q.empty()) {

            int node=q.front();
            q.pop();

            for(auto x:adj[node]) {
                if(dist[node]+1<dist[x]) {
                    dist[x]=dist[node]+1;
                    q.push(x);
                }
            }

        }
        

        for(int i:dist) {
            cout<<i<<" ";
        }


 }