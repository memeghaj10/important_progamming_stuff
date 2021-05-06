    /*

    
You are given a sequence of n integers a0, a1, ..., an-1. You are also given several queries consisting of indices i and j (0 ≤ i ≤ j ≤ n-1). For each query, determine the number of occurrences of the most frequent value among the integers ai, ..., aj.

Input
First line contains two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a0, ... ,an-1 (0 ≤ ai ≤ 100000, for each i ∈ {0, ..., n-1}) separated by spaces. The following q lines contain one query each, consisting of two integers i and j (0 ≤ i ≤ j ≤ n-1), which indicates the boundary indices for the query.

Output
For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.

Example
Input:

5 3
1 2 1 3 3
0 2
1 2
0 4

Output:

2
1

    */



    #include <bits/stdc++.h>
    #define endl "\n"
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define f first
    #define s second
    #define blk 555
    
    using namespace std;

    struct query {

        int l;
        int r;
        int idx;

    };

    bool comp(query a,query b) {

        if((a.l/blk)!=(b.l/blk)) {
            return (a.l/blk)<(b.l/blk);
        }

        return a.r<b.r;

    }

     query Q[300001];
    int a[300001] , ans[300001];
    int freq[300001];
     
    int freq_of_freq[300001];
    int curr_max = 0;


    void add (int pos) {

        int pref_f=freq[a[pos]];
        freq[a[pos]]++;
        int curr_f=freq[a[pos]];

        freq_of_freq[pref_f]--;
        freq_of_freq[curr_f]++;

        if(curr_f>curr_max) {
            curr_max=curr_f;
        }

    }

    void remove(int pos) {

        int pre_f=freq[a[pos]];
        freq[a[pos]]--;
        int curr_f=freq[a[pos]];

        freq_of_freq[pre_f]--;
        freq_of_freq[curr_f]++;

        if(curr_f<curr_max) {
            while(freq_of_freq[curr_max]==0) {
                curr_max--;
            }
        }

    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        int n,q;
        cin>>n>>q;

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        for(int i=0;i<q;i++) {
            cin>>Q[i].l>>Q[i].r;
            Q[i].idx=i;
        } 


        sort(Q,Q+q,comp);


        int ml=0;
        int mr=-1;

        for(int i=0;i<q;i++) {

            int l=Q[i].l;
            int r=Q[i].r;

            while(l>ml) {
               remove(ml);
                ml++;
            }

            while(r<mr) {
                remove(mr);
                mr--;
            }

            while(l<ml) {               
               ml--;
               add(ml);
            }

            while(r>mr) {
                mr++;
                add(mr);
            }

            ans[Q[i].idx]=curr_max;

        }

        for(int i=0;i<q;i++) {
            cout<<ans[i]<<endl;
        }


        return 0;
    }