class Solution {
public:
    
    int dp[601][101][101];
    vector<string> v;
    
    int dyn(int t,int m,int n) {
        
             if(t<0) {
                return 0;
            }
        
        
            if(dp[t][m][n]!=-1) {
                return dp[t][m][n];
            }
        
           
        
            int c1=count(v[t].begin(),v[t].end(),'1');
            int c0=count(v[t].begin(),v[t].end(),'0');
        
            if(c1<=n&&c0<=m) {
                return dp[t][m][n]=max(dyn(t-1,m,n),1+dyn(t-1,m-c0,n-c1));
            }
        
            return dp[t][m][n]=dyn(t-1,m,n);
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        v=strs;
        int n1=v.size();
        memset(dp,-1,sizeof(dp));
        return dyn(n1-1,m,n);
    }
};