
    /*

    Given N integers and K, find the minimum number of elements that should be removed such that Amax-Amin<=K. 
    After the removal of elements, Amax and Amin is considered among the remaining elements. 

    Time_Complexity: O(Nlog(N))


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


    int fin_index(int a[],int n,int i,int k) {

        int key=a[i];

        int idx=-1;

        int start=i+1;
        int end=n-1;

        while(start<end) {

            int mid = start+(end-start)/2;

            if(a[mid]-key<=k) {
                idx=mid;
                start=mid+1;
            }

            else {
                end=mid;
            }

        }


        return idx;
    }


    int min_removals(int a[],int n,int k) {


        sort(a,a+n);

        int ans=n-1;

        for(int i=0;i<n;i++) {

            int j=fin_index(a,n,i,k);

            if(j==-1) {
                continue;
            }

            else {
                ans=min(ans,n-(j-i+1));
            }

        }

        return ans;

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

        cout<<min_removals(a,n,k);


        return 0;
    }