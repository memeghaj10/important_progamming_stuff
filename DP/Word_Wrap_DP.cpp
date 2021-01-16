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

int printSolution (int p[], int n)  
{  
    int k;  
    if (p[n] == 1)  
        k = 1;  
    else
        k = printSolution (p, p[n]-1) + 1;  
    cout<<p[n]<<" "<<n<<" ";  
    return k;  
}  
    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
           
            int n;

            cin>>n;

            int a[n];

            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            int w;

            cin>>w;

            int extras[n+1][n+1];
            int c[n+1];
            int p[n+1];

            int i,j;


            for(int i=1;i<=n;i++) {
                extras[i][i]=w-a[i-1];
                for(int j=i+1;j<=n;j++) {
                    extras[i][j]=extras[i][j-1]-a[j-1]-1;
                }
            }

            for(int i=1;i<=n;i++) {
                for(int j=i;j<=n;j++) {
                    if(extras[i][j]<0) {
                        extras[i][j]=INT_MAX;
                    }
                    else if(j==n&&extras[i][j]>=0) {
                        extras[i][j]=0;
                    }
                    else {
                        extras[i][j]=extras[i][j]*extras[i][j];
                    }
                }
            }

            c[0]=0;

            for(int j=1;j<=n;j++) {
                c[j]=INT_MAX;
                for(int i=1;i<=j;i++) {
                    if(c[i-1]!=INT_MAX&&extras[i][j]!=INT_MAX&&(c[i-1]+extras[i][j]<c[j])) {
                        c[j]=c[i-1]+extras[i][j];
                        p[j]=i;
                    }
                }
            }
            
            printSolution(p,n);
            cout<<endl;
        }
        return 0;
    }