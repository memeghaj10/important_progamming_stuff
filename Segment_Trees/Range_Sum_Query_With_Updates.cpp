    /*

    Basic Implementation of a Segment Tree.

    Range Sum Query Based Solution.

    Time Complex for Queries:-

    1. Building the Seg Tree : O(N);
    2. Range Sum Query : O(log2(N));
    3. Update Query : O(log2(N));

    Also, the queries are solve in logarithmic complexities, because of division
    of segments in to further parts of an array, and representing them as a tree.
    
    Thus for each query, we simply traverse the hieght of the tree, which is of the order
    log2(N), where N is number of total array elements. 


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

    int getSum(int st[],int si,int sl,int sr,int l,int r) {

        if(sl>=l&&sr<=r) {      //if the query_range is fully overallping with seg_tree range
            return st[si];
        }

        if(r<sl||l>sr) {        // if there is no overlapping
            return 0;
        }

                                //when there is partial overlapping.

        int mid=(sl+sr)/2;      //calculating the mid to get the sum from the left_child and the right_child

        return getSum(st,2*si+1,sl,mid,l,r)+getSum(st,2*si+2,mid+1,sr,l,r);

    }

    void update(int st[],int si,int sl,int sr,int pos,int diff) {

        if(pos<sl||pos>sr) {        //if pos is not in the seg_tree range traversed.
            return;
        }

        st[si]+=diff;           //else, simply add the difference to the node.

        if(sl!=sr) {            // if it is not a leaf node, we simple break it into left_sub_range and right_sub_range

            int mid=(sl+sr)/2;  

            update(st,2*si+1,sl,mid,pos,diff);
            update(st,2*si+2,mid+1,sr,pos,diff);    //further we check if pos is available in the other nodes as well, and if true, we add the difference.
        }

    }


    void build(int st[],int si,int a[],int l,int r) {

        if(l==r) {
            st[si]=a[l];        //condition for leaf node
        }

        else {
            int mid=(l+r)/2;

            build(st,2*si+1,a,l,mid);       //building left child node
            build(st,2*si+2,a,mid+1,r);     //building right child node

            st[si]=st[2*si+1]+st[2*si+2];   //parent_node = left_node + right_node
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

        //number of array_elements and the queries

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        int st[4*n]; //segment tree, max_size cannot be more than 4*(number_of_leaf_nodes).

        build(st,0,a,0,n-1);       //building the segment tree.


        while(q--) {        //attempting queries.


            string h;
            cin>>h;

            if(h=="update") {   //update query

                int pos,x;
                cin>>pos>>x;

                int diff=x-a[pos-1];    //calculating change occured.
                a[pos-1]=x;

                update(st,0,0,n-1,pos-1,diff);      //update_query called

            }   

            else {


                int l,r;
                cin>>l>>r;

                l--;        //indexing to 0-based.
                r--;

                int p=getSum(st,0,0,n-1,l,r);   //calling range_sum_query.

                cout<<p<<endl;      //answer

            }


        }


        return 0;
    }