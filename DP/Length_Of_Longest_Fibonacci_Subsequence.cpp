
    /*

 A sequence X1, X2, ..., Xn is Fibonacci-like if:

n >= 3
Xi + Xi+1 = Xi+2 for all i + 2 <= n


Given a strictly increasing array arr of positive integers forming a sequence,
return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements.
For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].


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

    int length_of_longest_fibonacci_subseq(vector<int> v) {

            int n=v.size();

            map<int,int> mp;
            
            for(int i=0;i<n;i++) {
                mp[v[i]]=i;
            }

            unordered_map<int,int> longest;
            int ans=0;

            for(int i=0;i<n;i++) {
                for(int j=0;j<i;j++) {

                    if(v[i]-v[j]<v[j]&&mp.find(v[i]-v[j])!=mp.end()) {

                        int p=mp[v[i]-v[j]];

                        longest[j*n+i]=longest[p*n+j]+1;

                        ans=max(ans,longest[j*n+i]+2);

                    }

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

        int n;

        cin>>n;

        vector<int> v(n);

        for(int i=0;i<n;i++) {
            cin>>v[i];
        }

        cout<<length_of_longest_fibonacci_subseq(v);


        return 0;
    }