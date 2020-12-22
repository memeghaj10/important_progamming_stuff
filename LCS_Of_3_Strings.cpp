
  
  
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

  int lcs3(string s1,string s2,string s3,int x,int y,int z) {

    int dp[x+1][y+1][z+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=x;i++) {
      for(int j=1;j<=y;j++) {
        for(int k=1;k<=z;k++) {
          if(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1]) {
            dp[i][j][k]=dp[i-1][j-1][k-1]+1;
          }
          else {
            dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
          }
        }
      }
    }


    return dp[x][y][z];

  }

  int main()
  {



    
    int T;
    cin>>T;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--)
    {

      int x,y,z;
      cin>>x>>y>>z;
      string s1,s2,s3;

      cin>>s1>>s2>>s3;

      cout<<lcs3(s1,s2,s3,x,y,z)<<endl;
      
    }
    return 0;
  }