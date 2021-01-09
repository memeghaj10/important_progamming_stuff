    /*
    
    Given a 2D array, 
    find the maximum sum subarray in it.


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

    int kadane(int a[],int n)  {

            int max_as_of_now=a[0];
            int max_so_far=a[0];


            for(int i=1;i<n;i++) {

                max_as_of_now = max(a[i],max_as_of_now+a[i]);
                max_so_far = max(max_so_far,max_as_of_now);

            }


            return max_so_far;

    }

    int main()
    {

        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            int n,m;

            cin>>n>>m;
            //cout<<n<<m;

            int a[n][m];

            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cin>>a[i][j];
                   // cout<<a[i][j]<<" ";
                }
            }


            int res=INT_MIN;

            int temp[n];

            for(int i=0;i<m;i++) {                
                memset(temp,0,sizeof(temp));
                for(int j=i;j<m;j++) {
                    for(int k=0;k<n;k++) {
                        temp[k]+=a[k][j];
                       // cout<<temp[k]<<" ";
                    }

                    int sum=kadane(temp,n);

                  //  cout<<sum<<endl;

                    res=max(res,sum);

                }
            }

            cout<<res<<endl;

        }
        return 0;
    }