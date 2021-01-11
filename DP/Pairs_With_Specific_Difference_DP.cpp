
    
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

            int n;

            cin>>n;

            int a[n];

            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            int k;

            cin>>k;

            int dp[n];

            dp[0]=0;

            sort(a,a+n);

            for(int i=1;i<n;i++) {

                dp[i]=dp[i-1];

                if(a[i]-a[i-1]<k) {
                    if(i>=2) {
                        dp[i]=max(dp[i],dp[i-2]+a[i]+a[i-1]);
                    }
                    else {
                        dp[i]=max(dp[i],a[i]+a[i-1]);
                    }
                }
            }


            cout<<dp[n-1]<<endl;

        }
        return 0;
    }