    /*
    
    Given an array of integers where each element represents the max number of steps that can be made forward from that element.
    Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
    If an element is 0, then we cannot move through that element.
    
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

    int minJumps(int a[],int n) {

        if(n<=1) {
            return 0;
        }

        if(a[0]==0) {
            return -1;
        }

        int maxReach = a[0];

        int step = a[0];

        int jumps=1;


        for(int i=1;i<n;i++) {

            if(i==n-1) {
                return jumps;
            }

            maxReach = max(maxReach,i+a[i]);

            step--;

            if(step==0) {

                jumps++;


                if(i>=maxReach) {
                    return -1;
                }

                step = maxReach-i;

            }

        }


        return -1;

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

        cout<<minJumps(a,n);



        return 0;
    }