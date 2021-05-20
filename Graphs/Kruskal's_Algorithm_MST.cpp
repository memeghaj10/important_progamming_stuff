  
    
    #include <bits/stdc++.h>

    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;



    struct edges {

        int u;
        int v;
        int wt;

        node(int f,int s,int w) {
            u=f;
            v=s;
            wt=w;
        } 

    };

    bool comp(node a,node b) {

            return a.w<b.w;
    }

    int findParent(int u,vector<int> &parent) {
        if(u==parent[u]) {
            return u;
        }

        return parent[u]=findParent(parent[u],parent);
    }

    void union (int u,int v,vector<int> &parent,vector<int> &size) {

        u=findParent(u,parent);
        v=findParent(v,parent);

        if(size[u]<size[v]) {
            parent[u]=v;
            size[v]+=size[v];
        }
        else {
            parent[v]=u;
            size[u]+=size[v];
        }

    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        int E,V;
        cin>>E>>V;

        vector<node> edges;

        for(int i=0;i<E;i++) {
            int u,v,wt,;
            cin>>u>>v>>wt;
            edges.eb(node(u,v,wt));
        }

        sort(edges.begin(),edges.end(),comp);

        vector<int> parent(V);
        for(int i=0;i<V;i++) {
            parent[i]=i;
        }

        vector<int> size(V,0);


        vector<pair<int,int>> vp;

        int cost=0;

        for(auto x:edges) {

            if(findParent(x.u,parent)!=findParent(x.v,parent)) {

                cost+=x.wt;
                vp.push_back(make_pair(x.u,x.v));
                union(x.v,x.u,parent,size);

            }

        }

        cout<<cost<<endl;

        for(auto x:vp) {
            cout<<x.f<<" - "<x.s<<endl;
        }

        
        return 0;
    }