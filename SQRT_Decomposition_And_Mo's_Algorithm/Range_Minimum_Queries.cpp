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

    int block[100]; //block array
    int blk_sz;        //block size, will be assigned in the min function
    int a[100001];  //array containing the values

    int getMin(int l,int r) {

       int ans=INT_MAX;

        while(l<r and l%blk_sz!=0 and l!=0) {
            ans=min(ans,a[l]);
            l++;
        }

        while(l+blk_sz<=r) {
            ans=min(ans,block[l/blk_sz]);
            l+=blk_sz;
        }

        while(l<=r) {
            ans=min(ans,a[l]);
            l++;
        }

        return ans;

    }

    void update(int pos,int val) {

        int blk_number=pos/blk_sz; //finding the block number
        block[blk_number]=min(block[blk_number],val);   //updating the block number
        a[pos]=val;
    }


    void preprocess(int a[],int n) {

        int blk_idx=-1;   //initialising block pointer
        int blk_sz=sqrt(n);   //calculating size of block

        for(int i=0;i<n;i++) {
            if(i%blk_sz==0) {
                blk_idx++;      //incremting block pointer
                block[blk_idx]=INT_MAX;
            }
            block[blk_idx]=min(block[blk_idx],a[i]);     ///finding minimum of all the block values
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

        blk_sz=sqrt(n);

        preprocess(a,n);

        for(int i=0;i<q;i++) {

            int y;
            cin>>y;

            if(y==1) {

                int l,r;
                cin>>l>>r;
                l--;
                r--;

                int ans=getMin(l,r);

                cout<<ans<<endl;

            }


            else {

                int pos,val;
                cin>>pos>>val;

                pos--;

                update(pos,val);

            }

        }


        return 0;
    }