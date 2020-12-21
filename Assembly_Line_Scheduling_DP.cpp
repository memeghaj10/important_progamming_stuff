    
    /*

   A car factory has two assembly lines, each with n stations.
   A station is denoted by Si,j where i is either 1 or 2 and indicates the assembly line the station is on, and j indicates the number of the station.
   The time taken per station is denoted by ai,j. Each station is dedicated to some sort of work like engine fitting, body fitting, painting, and so on.
   So, a car chassis must pass through each of the n stations in order before exiting the factory.The parallel stations of the two assembly lines perform the same task. 
   After it passes through station Si,j, it will continue to station Si,j+1 unless it decides to transfer to the other line. 
   Continuing on the same line incurs no extra cost, but transferring from line i at station j – 1 to station j on the other line takes time ti,j. 
   Each assembly line takes an entry time ei and exit time xi which may be different for the two lines. 
   Give an algorithm for computing the minimum time it will take to build a car chassis.

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
    #define NUM_STATION 4
    
    using namespace std;

    

    int find_carAssembly(int en[],int ex[],int a[][NUM_STATION],int t[][NUM_STATION]) {

        int dp1[NUM_STATION];
        int dp2[NUM_STATION];

        //dp1[0]=0;
       // dp2[0]=0;
        dp1[0]=en[0]+a[0][0];
        dp2[0]=en[1]+a[1][0];

        for(int i=1;i<NUM_STATION;i++) {
            dp1[i]=min(dp1[i-1]+a[0][i],dp2[i-1]+t[1][i]+a[0][i]);
            dp2[i]=min(dp2[i-1]+a[1][i],dp1[i-1]+t[0][i]+a[1][i]);
        }


        return min(dp1[NUM_STATION-1]+ex[0],dp2[NUM_STATION-1]+ex[1]);

    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

       int en[2];
       cin>>en[0]>>en[1];
       int ex[2];
       cin>>ex[0]>>ex[1];

    

      // u=n;

       int a[2][NUM_STATION],t[2][NUM_STATION];

       for(int j=0;j<2;j++) {
        for(int i=0;i<NUM_STATION;i++) {
            cin>>a[j][i];
       }
       }

       for(int i=0;i<2;i++) {
        for(int j=0;j<NUM_STATION;j++) {
            cin>>t[i][j];
        }
       }

       cout<<find_carAssembly(en,ex,a,t);


        return 0;
    }