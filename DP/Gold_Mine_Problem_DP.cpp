    
    /*

    Given a gold mine of n*m dimensions.
    Each field in this mine contains a positive integer which is the amount of gold in tons.
    Initially the miner is at first column but can be at any row. 
    He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right.
    Find out maximum amount of gold he can collect.


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
    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        int r,c;

        cin>>r>>c;

        int dp[r][c];

        int arr[r][c];

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>arr[i][j];
            }
        }

        int max_sum=INT_MIN;

        memset(dp,0,sizeof(dp));

        for(int i=0;i<r;i++) {
            dp[i][c-1]=arr[i][c-1];
        }

        for(int i=c-2;i>=0;i--) {
            for(int j=0;j<r;j++) {

                int ru,rd,ri;

                j==0?ru=0:ru=dp[j-1][i+1];

                ri=dp[j][i+1];

                j==r-1?rd=0:rd=dp[j+1][i+1];

                dp[j][i]=arr[j][i]+max({ru,ri,rd});

                if(dp[j][i]>max_sum) {
                    max_sum=dp[j][i];
                }

            }
        }

       cout<<max_sum<<endl;


        return 0;
    }