
    /*


    Given a sequence of positive numbers,
    find the maximum sum that can be formed which has no three consecutive elements present.


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


    int max_sums(int a[],int n) {

        int dp[n];

        if(n>=1) {
            dp[0]=a[0];
        }

        if(n>=2) {
            dp[1]=a[0]+a[1];
        }

        if(n>2) {
            dp[2]=max({dp[1],dp[0]+a[2],a[0]+a[2]});
        }


        for(int i=3;i<n;i++) {
            dp[i] = max({dp[i-1],dp[i-2]+a[i],dp[i-3]+a[i-1]+a[i]});
        }

        return dp[n-1];

    }


    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        int n;

        cin>>n;

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }


        cout<<max_sums(a,n);    


        return 0;
    }