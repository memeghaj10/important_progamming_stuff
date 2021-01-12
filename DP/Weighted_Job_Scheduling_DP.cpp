    /*

Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

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

    struct Job {
        int start,finish,profit;
    };


    bool comp(Job s1,Job s2) {
        return (s1.finish<s2.finish);
    }

    int last_non_conflict(Job arr[],int i) {

        int lo=0;
        int hi=i-1;

        while(lo<=hi) {

            int mid=(lo+hi)/2;

            if(arr[mid].finish<=arr[i].start) {
                if(arr[mid+1].finish<=arr[i].start){
                    lo=mid+1;
                }
                else {
                    return mid;
                }
            }

            else {
                hi=mid-1;
            }

        }


        return -1;
 
    }


    int findMaxProfit(Job a[],int n) {

        sort(a,a+n,comp);

        int dp[n];
        memset(dp,0,sizeof(dp));

        dp[0]=a[0].profit;

        for(int i=1;i<n;i++) {

            int curr=a[i].profit;

            int l=last_non_conflict(a,i);

            if(l!=-1) {
                curr+=dp[l];
            }

            dp[i] = max(curr,dp[i-1]);
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

        Job arr[n];

        for(int i=0;i<n;i++) {
            cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
        }

        cout<<"The optimal profit is: "<<findMaxProfit(arr,n);


        return 0;
    }