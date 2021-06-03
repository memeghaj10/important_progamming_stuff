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
    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        int n,m;
        cin>>n>>m;

        vector<int> balance(n+1,0);

        for(int i=0;i<m;i++) {
            int u,v;
            cin>>u>>v>>w;
            balance[u]-=w;
            balance[v]+=w;
        }

        multiset<int> st;

        for(int i=0;i<n;i++) {
            if(balance[i]!=0) {
                st.insert(balance[i]);
            }
        }

        int count=0;

        while(!st.empty()) {
            int poor=*st.begin();st.erase(st.begin());
            int rich=*st.rbegin();st.erase(prev(st.end()));

            int amt=min(-poor,rich);

            count++;
            poor+=amount;
            rich-=amount;

            if(poor) {
                st.insert(poor);
            }
            if(rich) {
                st.insert(rich);
            }

            for(in t:st) {
                cout<<t<<" ";
            }

        }


        return 0;
    }