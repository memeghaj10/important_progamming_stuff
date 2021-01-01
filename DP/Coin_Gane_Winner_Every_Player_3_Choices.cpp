  /*

    A and B are playing a game.
     At the beginning there are n coins.
      Given two more numbers x and y.
      Ineach move a player can pick x or y or l coins.
      Aalways starts the game.
      The player who picks the last coin wins the game.
      For a given value of n, find whether A will win the game or not if both are playing optimally.

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

    bool solve(int n,int x,int y) {

        bool dp[n+1];

        dp[0]=false;
        dp[1]=true;

        for(int i=2;i<=n;i++) {

            if(i-1>=0&&dp[i-1]==0) {
                dp[i]=true;
            }

            else if(i-x>=0&&dp[i-x]==0) {
                dp[i]=true;
            }

            else if(i-y>=0&&dp[i-y]==0) {
                dp[i]=true;
            }

            else {
                dp[i]=false;
            }

        }


        return dp[n];

    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


      int n,x,y;

      cin>>n>>x>>y;

      if(solve(n,x,y)) {
        cout<<"A";
      }

      else {
        cout<<"B";
      }


        return 0;
    }