    /*

        Your task is to maintain an array of n values and efficiently process the following types of queries:
        

        1. Increase each value in range [a,b] by x.
        2. Set each value in range [a,b] to x.
        3. Calculate the sum of values in range [a,b].


        So basically this problem is a modification of lazy propagation.


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

    struct node {           // we will define a node structure for every segement tree node.
        int sum;            //this will carry the sum, of the range
        int incr;           //this will define if an increement has to be performend in the range
        int set;            //this will define if all the values in the range have to be set in to a particular value.
        bool isSet;          // it is basically a flag, which will define if set_to_x has been performed in this range or not.

        node() {            // a node constructor
            sum=0;
            incr=0;
            isSet=false;
        }

        void reset() {      // we reset the node once it has been, all updated and values of set/incr have been passed to children.
            incr=0;
            isSet=false;
        }
    };


      void compose(vector<node> &st,int si,int child) {     //function to update the children nodes, by passing info
                                                            // of incr/set from parent node.
        if(st[si].isSet) {
            st[child].isSet=true;                       //if parent was set to a particular value, same goes for the child also.
            st[child].set=st[si].set;                      //so updating the set value
            st[child].incr=st[si].incr;                     //updating incr operations values if any from the parent node.
        }

        else {
            st[child].incr+=st[si].incr;        //if the parent was not set to a specific element, we simply keep the track of the increement to be done. 
        }

    }


    void apply_agr(vector<node> &st,int si,int sl,int sr) {     //function t update the node sum

            if(st[si].isSet) {
                st[si].sum=(sr-sl+1)*st[si].set;        // if the range was set, we simply update sum = set*(range_length)
            }

            st[si].sum+=(sr-sl+1)*(st[si].incr);        //adding increements done after set_operation to the range

            if(sl!=sr) {
                compose(st,si,2*si+1);          //updating children, if the parent is not a leaf node
                compose(st,si,2*si+2);
            }

            st[si].reset();         //resetting the node, as sum has been updated, so no backlog of set/incr operation remains.

    }


    int get_sum(vector<node> &st,int si,int sl,int sr,int l,int r) {

        if(sl>r||sr<l) {       //out of range
            return 0;
        }

        apply_agr(st,si,sl,sr); //updating the range/node

        if(l<=sl&&sr<=r) {

            return st[si].sum;  //if range overlaps, return sum
        }

        int mid=(sl+sr)/2;

        return get_sum(st,2*si+1,sl,mid,l,r)+get_sum(st,2*si+2,mid+1,sr,l,r);       //recurisve addition function


    }


    void set_range(vector<node> &st,int si,int sl,int sr,int l,int r,int x) {

        if(sl>r||sr<l) {        //out of range
            return;
        }

        if(l<=sl&&sr<=r) {          //complete range overlpas.
            
            st[si].isSet=true;      //setting flag=1, as set is performed
            st[si].set=x;           //updating set value of the rage
            st[si].incr=0;          //nullifying all the increements of this range

            return;

        }

        int mid=(sr+sl)/2;
            
        apply_agr(st,si,sl,sr);     //applying update operation to nodes, passing update/set/incr info to children

        set_range(st,2*si+1,sl,mid,l,r,x);  //finding other overlapping regions and updating the corresponding nodes.
        set_range(st,2*si+2,mid+1,sr,l,r,x);


        apply_agr(st,2*si+1,sl,mid);    //updating children nodes
        apply_agr(st,2*si+2,mid+1,sr);

        st[si].sum=st[2*si+1].sum+st[2*si+2].sum;      //calculatign parent sum
        
    }


    void increase_range(vector<node> &st,int si,int sl,int sr,int l,int r,int x) {      

        if(sl>r||sr<l) {        //if out of range
            return ;
        }

        if(l<=sl&&sr<=r) {            //complete range overlaps, so we update the incr value of the range node
            st[si].incr+=x;
            return;
        }

        int mid=(sl+sr)/2;

        apply_agr(st,si,sl,sr);     //applying the update operation to node, and passing further values to children

        increase_range(st,2*si+1,sl,mid,l,r,x);     //finding ranges which completely overlaps within query range
        increase_range(st,2*si+2,mid+1,sr,l,r,x);

        apply_agr(st,2*si+1,sl,mid);        //updating children nodes
        apply_agr(st,2*si+2,mid+1,sr);

        st[si].sum=st[2*si+1].sum+st[2*si+2].sum;       //calculating parent node sum throught addition between children nodes.

    }

  

    void build(vector<node> &st,int si,int sl,int sr,int a[]) {     //building the segment tree

        if(sl==sr) {
            st[si].sum=a[sl];
        }

        else {

            int mid=(sl+sr)/2;

            build(st,2*si+1,sl,mid,a);
            build(st,2*si+2,mid+1,sr,a);

            st[si].sum=st[2*si+1].sum+st[2*si+2].sum;
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
       

        vector<node> st(4*n,node());

        build(st,0,0,n-1,a);        //building segment tree


        while(q--) {

            int c;
            cin>>c;

            if(c==1) {          //processing, qureries of type - 1 :increement

                int l,r,x;
                cin>>l>>r>>x;

                l--;
                r--;

                increase_range(st,0,0,n-1,l,r,x);       //calling to increase values in the range by x.

            }

            if(c==2) {      //processing queries of type - 2 : setting all values in the range to x

                int l,r,x;
                cin>>l>>r>>x;

                l--;
                r--;

                set_range(st,0,0,n-1,l,r,x);    //function call

            }

            if(c==3) {          //processing queries of type - 3 : Range_Sum_Query

                int l,r;
                cin>>l>>r;

                l--;
                r--;

                int p=get_sum(st,0,0,n-1,l,r);          //function call

                cout<<p<<endl;

            }

        }



        return 0;
    }