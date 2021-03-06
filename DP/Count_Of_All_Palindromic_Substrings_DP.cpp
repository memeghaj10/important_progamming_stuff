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

    int dp[1001][1001];

    bool ispalin(string s, int i,int j) {


        if(i>j) {
            return 1;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }


        if(s[i]!=s[j]) {
            return dp[i][j]=0;
        }

        return dp[i][j]=ispalin(s,i+1,j-1);

    }



    int countPalin(string s) {

        memset(dp,-1,sizeof(dp));

        int n=s.size();

        int c=0;


        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(ispalin(s,i,j)) {
                    c++;
                }
            }
        }

        return c;
    }


    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

       
       string s;

       cin>>s;

       cout<<countPalin(s);       


        return 0;
    }