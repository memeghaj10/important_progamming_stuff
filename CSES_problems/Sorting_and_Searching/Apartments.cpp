    
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

        int n,m,k;

        cin>>n>>m>>k;

        int a[n];
       

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        sort(a,a+n);

        multiset<int> ms;

        int y;

        for(int i=0;i<m;i++) {
            cin>>y;
            ms.insert(y);
        }

        int c=0;

        for(int i=0;i<n;i++)  {
            int val=a[i]-k;
            auto it = ms.lower_bound(val);

            if(it!=ms.end() and *it<=a[i]+k) {
                ms.erase(it);
                c++;
            }
        }

        cout<<c<<endl;

        return 0;
    }