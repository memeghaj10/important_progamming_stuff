
    /*
        Given N integers and K, find the minimum number of elements that should be removed such that Amax-Amin<=K.
        After the removal of elements, Amax and Amin is considered among the remaining elements. 

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


    int dp[500][500];

    int count_removals(int a[],int i,int j,int k) {

       if(i>=j) {
        return 0;
       }

       else if(dp[i][j]!=-1) {
        return dp[i][j];
       }

       else if(a[j]-a[i]<=k) {
        return 0;
       }

       else if(a[j]-a[i]>k) {

            dp[i][j] = 1+min(count_removals(a,i+1,j,k),count_removals(a,i,j-1,k));

       }


       return dp[i][j];

    }


    int removals(int a[],int n,int k) {

        memset(dp,-1,sizeof(dp));

        if(n==1) {
            return 0;
        }

        else {
            return count_removals(a,0,n-1,k);
        }
    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        int n,k;

        cin>>n>>k;

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        sort(a,a+n);


        cout<<removals(a,n,k);  

        
        return 0;
    }