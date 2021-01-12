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

    int zzis(int a[],int n) {

        int dp[n][2];   

        /*

        dp[i][0] - > it denotes, length of the longest alternating subsequence ending at i
                    and last element is greater than its previous.

        dp[i][1] - > it denotes, length of the longest alternating subsequence ending at i
                    and last element is smaller than its previous.


        dp[i][0] = max(dp[i][0],dp[j][1]+1);
                    //max of (no_inclusion,prev_smaller_count+1);


        dp[i][1] = max(dp[i][1],dp[j][0]+1);
                    //max of (no_inclusion,prev_greater_count+1);
        */

        for(int i=0;i<n;i++) {
            dp[i][0]=dp[i][1]=1;
        }

        int res=1;


        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {

                if(a[j]<a[i]&&dp[i][0]<dp[j][1]+1) {
                    dp[i][0]=dp[j][1]+1;
                }

                if(a[j]>a[i]&&dp[i][1]<dp[j][0]+1) {
                    dp[i][1]=dp[j][0]+1;
                }

            }

            res=max(res,max(dp[i][0],dp[i][1]));
        }

        return res;

    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


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


            cout<<zzis(a,n)<<endl;

        }
        return 0;
    }