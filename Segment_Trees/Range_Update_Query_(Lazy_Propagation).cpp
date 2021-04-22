    /*

    This is a simple example of how lazy propagation works for updating ranges and processing range-update queries.

    Time Complexity : O(N)  //Build

                      O(Log(N)) //Query Processing

    */



    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define int long long int
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

    int getans(int st[],int si,int sl,int sr,int k,int lazy[]) {

        if(lazy[si]!=0) {

                    int dx=lazy[si];
                    lazy[si]=0;
                    st[si]+=(dx*(sr-sl+1));

                    if(sl!=sr) {
                        lazy[2*si+1]+=dx;
                        lazy[2*si+2]+=dx;
                    }
        }


        if(sl==sr&&sl==k) {
            return st[si];
        }

        int mid=(sl+sr)/2;

        if(k<=mid) {
            return getans(st,2*si+1,sl,mid,k,lazy);
        }

        return getans(st,2*si+2,mid+1,sr,k,lazy);

    }

    int getsum(int st[],int si,int sl,int sr,int l,int r,int lazy[]) {

        if(lazy[si]!=0) {

                    int dx=lazy[si];
                    lazy[si]=0;
                    st[si]+=(dx*(sr-sl+1));

                    if(sl!=sr) {
                        lazy[2*si+1]+=dx;
                        lazy[2*si+2]+=dx;
                    }
        }


        if(sl>=l&&sr<=r) {
            return st[si];
        }


        if(sl>r||l>r) {
            return 0;
        }

        int mid=(sl+sr)/2;

        return getsum(st,2*si+1,sl,mid,l,r,lazy)+getsum(st,2*si+2,mid+1,sr,l,r,lazy);


    }



    void update(int st[],int si,int sl,int sr,int l,int r,int val,int lazy[]) {

            if(lazy[si]!=0) {

                    int dx=lazy[si];
                    lazy[si]=0;
                    st[si]+=(dx*(sr-sl+1));

                    if(sl!=sr) {
                        lazy[2*si+1]+=dx;
                        lazy[2*si+2]+=dx;
                    }
            }

            if(sl>r||l>sr) {
                return;
            }

            if(sl>=l&&sr<=r) {

                int dx=val*(sr-sl+1);
                st[si]+=dx;

                if(sl!=sr) {
                    lazy[2*si+1]+=val;
                    lazy[2*si+2]+=val;
                }

                return;

            }


            int mid=(sl+sr)/2;
            update(st,2*si+1,sl,mid,l,r,val,lazy);
            update(st,2*si+2,mid+1,sr,l,r,val,lazy);

            st[si]=st[2*si+1]+st[2*si+2];

    }


    void build(int st[],int si,int sl,int sr,int a[]) {

        if(sl==sr) {
            st[si]=a[sl];
        }

        else {

            int mid=(sl+sr)/2;

            build(st,2*si+1,sl,mid,a);
            build(st,2*si+2,mid+1,sr,a);

            st[si]=st[2*si+1]+st[2*si+2];
        }

    }


    signed main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        int n,q;
        cin>>n>>q;

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        int st[4*n];
        int lazy[4*n];
        memset(lazy,0,sizeof(lazy));

        build(st,0,0,n-1,a);


        while(q--) {

            int c;
            cin>>c;

            if(c==1) {

                int l,r,x;
                cin>>l>>r>>x;

                l--;
                r--;

                update(st,0,0,n-1,l,r,x,lazy);

            }

            else if(c==2) {

                int k;
                cin>>k;
                k--;

                int p=getans(st,0,0,n-1,k,lazy);

                cout<<p<<endl;

            }

            else if(c==3) {

                int l,r;
                cin>>l>>r;

                l--;
                r--;

                int p=getsum(st,0,0,n-1,l,r,lazy);

                cout<<p<<endl;

            }


        }


        return 0;
    }