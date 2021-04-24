        /*



        You are given a list consisting of n integers.
        Your task is to remove elements from the list at given positions, and report the removed elements.

        Example:-
        Input:
        5
        2 6 1 4 2
        3 1 3 1 1

        Output:
        1 2 2 6 4




    Idea: the main idea, is to build a range sum segment tree on an aux array, present[], which will denote:-
            present[i]=1 //the ith element is present
            present[i]=0 //the ith element has been deleted 


             So we wil build a range sum query segement tree.

            so sum of first j elements of the present array will lead us to the xth element.
            the moment xth element has been found, we simply update the segement tree, and update present[(where xth element was found)]=0;

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

    void update(int st[],int si,int sl,int sr,int pos,int x) {      //similar to range_sum_update

        if(sl>pos||sr<pos) {
            return;
        }

        if(sl==sr&&sr==pos) {
            st[si]=x;
            return ;
        }

        int mid=(sl+sr)/2;
        update(st,2*si+1,sl,mid,pos,x);
        update(st,2*si+2,mid+1,sr,pos,x);

        st[si]=st[2*si+1]+st[2*si+2];

    }

    int query(int st[],int si,int sl,int sr,int l,int r) {      //similar to range_sum_query

        if(sl>r||sr<l) {
            return 0;
        }

        if(sl>=l&&sr<=r) {
            return st[si];
        }

        int mid=(sl+sr)/2;
        return query(st,2*si+1,sl,mid,l,r)+query(st,2*si+2,mid+1,sr,l,r);
    }

    void build(int st[],int si,int sl,int sr,int p[]) {

        if(sl==sr) {
            st[si]=p[sl];
        }

        else {
            int mid=(sl+sr)/2;
            build(st,2*si+1,sl,mid,p);
            build(st,2*si+2,mid+1,sr,p);

            st[si]=st[2*si+1]+st[2*si+2];
        }

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

        int present[n];

        for(int i=0;i<n;i++) {      //constrcuting the present array, initially all the elements are present
            present[i]=1;   
        }



        int st[4*n];

        build(st,0,0,n-1,present);  //building the segment tree

        for(int k=0;k<n;k++) {


            int x;
            cin>>x;
            //cout<<x;
            

            int lo=0;
            int hi=n-1;
                                //we will use bunary search to find the index in the range [0,n-1], where 
                                //prefix sum of all elements till that position is = x.
                                //prefix sum can be found usig range sum query, as we will query for the range (0,index_to_be_judged)
            
            while(lo!=hi) {     

                int m=(lo+hi)/2;

                int p=query(st,0,0,n-1,0,m);       //qurying fo the prefix sum


                if(p>x) {               // if sum is more, than x, can be found earlier also, so we decrease hi
                    hi=m-1;
                }

                else if(p<x) {          //if sum is less, that is, then we increase lo
                    lo=m+1;
                }

                else {

                    if(present[m]) {        //if the element is still present and the prefix sum of the first mid elements amounts to x, we set lo to that index.
                        lo=m;
                        break;
                    }

                    else {
                        hi=m-1;     //else we search for the next index, and reduce hi.
                    }

                }

            }
            

            present[lo]=0;              //after finding that element, we mark that element visited.
            update(st,0,0,n-1,lo,0);     // and upadate the present of that element = 0;

            cout<<a[lo]<<endl;      //output.

        }


        return 0;
    }