
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

   


        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {

            int n,m;

            cin>>n>>m;

            int a[n][m];

            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cin>>a[i][j];
                }
            }

            int dp[n][m];

            for(int i=0;i<n;i++) {
                dp[i][0]=a[i][0];
            }

            for(int j=0;j<m;j++) {
                dp[0][j]=a[0][j];
            }
            

            for(int i=1;i<n;i++) {
                for(int j=1;j<m;j++) {
                    if(a[i][j]==0) {
                        dp[i][j]=0;
                    }

                    else {
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                }
            }

            int ans=-1;

            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    ans=max(ans,dp[i][j]);
                }
            }

            cout<<ans<<endl;

            
        }
        return 0;
    }