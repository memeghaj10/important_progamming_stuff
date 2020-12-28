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

    static int dp[1001][1001];

    

    int solve(int a[],int i,int j) {

            if(i>=j) {
                return 0;
            }


            if(dp[i][j]!=-1) {
                return dp[i][j];
            }


            dp[i][j]=INT_MAX;

            for(int k=i;k<j;k++) {
                dp[i][j]=min(dp[i][j],solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[j]*a[k]);
            }

            return dp[i][j];

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

        memset(dp,-1,sizeof(dp));

        cout<<solve(a,1,n-1);



        return 0;
    }