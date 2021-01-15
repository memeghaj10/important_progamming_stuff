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

    int sum(int freq[],int i,int j) {

        int s=0;

        for(int k=i;k<=j;k++) {
            s+=freq[k];
        }

        return s;

    }


    int optimal_BST(int keys[],int freq[],int n) {

        int dp[n][n];

        //memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++) {
            dp[i][i]=freq[i];
        }


        for(int L=2;L<=n;L++) {

            for(int i=0;i<=n-L+1;i++) {

                int j=i+L-1;

                dp[i][j]=INT_MAX;

                for(int r=i;r<=j;r++) {

                    int c = ((r>i)?dp[i][r-1]:0)+
                            ((r<j)?dp[r+1][j]:0)+
                            sum(freq,i,j);
                    dp[i][j] = min(c,dp[i][j]);
                }
            }

        }

        return dp[0][n-1];


    }


    

    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif



        int n;

        cin>>n;

        int keys[n];
        int freq[n];

        for(int i=0;i<n;i++) {
            cin>>keys[i];
        }

        for(int i=0;i<n;i++) {
            cin>>freq[i];
        }


        cout<<optimal_BST(keys,freq,n);


        return 0;
    }