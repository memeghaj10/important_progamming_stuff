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
    #define mod 1003
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;

    int dp[1001][1001][2];


    int parenthesis_count(string s,int i,int j,int istrue) {

        if(i>j) {
           return false;
        }

        if(i==j) {
             if(istrue) {
                return s[i]=='T';
            }
            else {
                return s[i]=='F';
            }
        }

        if(dp[i][j][istrue]!=-1) {
            return dp[i][j][istrue];
        }

        int ans=0;

        for(int k=i+1;k<=j-1;k+=2) {

            int lf,rf,lt,rt;

            if(dp[i][k-1][1]==-1) {
                lt=parenthesis_count(s,i,k-1,1);
                dp[i][k-1][1]=lt;
            }
            else {
                lt=dp[i][k-1][1];
            }

            if(dp[i][k-1][0]==-1) {
                lf=parenthesis_count(s,i,k-1,0);
                dp[i][k-1][0]=lf;
            }
            else {
                lf=dp[i][k-1][0];
            }

            if(dp[k+1][j][1]==-1) {
                rt=parenthesis_count(s,k+1,j,1);
                dp[k+1][j][1]=rt;
            }
            else {
                rt=dp[k+1][j][1];
            }

            if(dp[k+1][j][0]==-1) {
                rf=parenthesis_count(s,k+1,j,0);
                dp[k+1][j][0]=rf;
            }
            else {
                rf=dp[k+1][j][0];
            }


            if(s[k]=='&') {
                if(istrue==1) {
                    ans+=((lt%mod)*(rt%mod))%mod;
                }
                else {
                    ans+=(lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod;
                }
            }

            else if(s[k]=='^') {
                if(istrue==1) {
                    ans+=lt*rf+lf*rt;
                }
                else {
                    ans+=(lt*rt)%mod+(lf*rf)%mod;
                }
            }

            else if(s[k]=='|') {
                if(istrue==1) {
                    ans+=(lt*rt)%mod+(lt*rf)%mod+(rt*lf)%mod;
                }
                else {
                    ans+=(lf*rf)%mod;
                }
            }

            dp[i][j][istrue]=ans;

        }

        return ans%mod;

    }


    signed main()
    {

   

        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            int  n;
            cin>>n;

            string s;
            cin>>s;

            memset(dp,-1,sizeof(dp));
            int istrue=1;

            cout<<parenthesis_count(s,0,n-1,istrue)<<endl;


        }
        return 0;
    }