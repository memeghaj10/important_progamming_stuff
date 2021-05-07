    
    /*


Question:::--


Baby Ehab has a piece of Cut and Stick with an array a of length n written on it. He plans to grab a pair of scissors and do the following to it:

pick a range (l,r) and cut out every element al, al+1, ..., ar in this range;
stick some of the elements together in the same order they were in the array;
end up with multiple pieces, where every piece contains some of the elements and every element belongs to some piece.
More formally, he partitions the sequence al, al+1, ..., ar into subsequences. He thinks a partitioning is beautiful if for every piece (subsequence) it holds that, if it has length x, then no value occurs strictly more than ⌈x2⌉ times in it.

He didn't pick a range yet, so he's wondering: for q ranges (l,r), what is the minimum number of pieces he needs to partition the elements al, al+1, ..., ar into so that the partitioning is beautiful.

A sequence b is a subsequence of an array a if b can be obtained from a by deleting some (possibly zero) elements. Note that it does not have to be contiguous.

Input
The first line contains two integers n and q (1≤n,q≤3⋅105) — the length of the array a and the number of queries.

The second line contains n integers a1, a2, ..., an (1≤ai≤n) — the elements of the array a.

Each of the next q lines contains two integers l and r (1≤l≤r≤n) — the range of this query.

Output
For each query, print the minimum number of subsequences you need to partition this range into so that the partitioning is beautiful. We can prove such partitioning always exists.

Example
input
6 2
1 3 2 3 3 2
1 6
2 5
output
1
2
Note
In the first query, you can just put the whole array in one subsequence, since its length is 6, and no value occurs more than 3 times in it.

In the second query, the elements of the query range are [3,2,3,3]. You can't put them all in one subsequence, since its length is 4, and 3 occurs more than 2 times. However, you can partition it into two subsequences: [3] and [2,3,3].
    

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
    #define blk 555
    
    using namespace std;

    struct query {

        int l;
        int r;
        int idx;

    };

    query Q[300001];
    int a[3000001];
    int freq[300001];
    int freq_of_freq[300001];
    int ans[300001];

    int currMax=0;


    bool comp(query a,query b) {

            if((a.l/blk)!=(b.l/blk)) {
                return (a.l/blk)<(b.l/blk);
            }

            return a.r<b.r;
    }

    void add(int pos) {

        int pref_f=freq[a[pos]];
        freq[a[pos]]++;
        int curr_f=freq[a[pos]];

        freq_of_freq[pref_f]--;
        freq_of_freq[curr_f]++;

        if(currMax<curr_f) {
            currMax=curr_f;
        }

    }

    void remove(int pos) {

        int pref_f=freq[a[pos]];
        freq[a[pos]]--;
        int curr_f=freq[a[pos]];

        freq_of_freq[pref_f]--;
        freq_of_freq[curr_f]++;

        if(curr_f<currMax) {
            while(freq_of_freq[currMax]==0) {
                currMax--;
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

        //int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        for(int i=0;i<q;i++) {
            cin>>Q[i].l>>Q[i].r;
            Q[i].idx=i;
            Q[i].l--;
            Q[i].r--;
        }

        sort(Q,Q+q,comp);

        int ml=0;
        int mr=-1;

        for(int i=0;i<q;i++) {

            int L=Q[i].l;
            int R=Q[i].r;

            while(ml>L) {
                ml--;
                add(ml);
            }

            while(mr<R) {
                mr++;
                add(mr);
            }

            while(ml<L) {
                remove(ml);
                ml++;
            }

            while(R<mr) {
                remove(mr);
                mr--;
            }

            int total=R-L+1;

            int rem=total-currMax;

            int half=(total+1)/2;

            if(currMax<=half) {
                ans[Q[i].idx]=1;
            }

            else {
                ans[Q[i].idx]=total-2*rem;
            }

        }

        for(int i=0;i<q;i++) {
            cout<<ans[i]<<endl;
        }

        return 0;
    }