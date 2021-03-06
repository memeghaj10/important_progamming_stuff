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

    int find_LPS(string s,string g) {

        int n=s.size();
        int m=g.size();

        int dp[n+1][m+1];

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1]==g[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }

                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }




    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        string s;

        cin>>s;

        string g=s;

        reverse(g.begin(),g.end());

        cout<<find_LPS(s,g);


        return 0;
    }