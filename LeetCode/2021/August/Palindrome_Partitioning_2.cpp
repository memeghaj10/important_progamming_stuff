class Solution {
    
    
private:
     int dp[2001][2001];
     bool p_dp[2001][2001];
    
public:   

    
    int solve(string &s,int i,int j) {
        
        if(i>=j) {
            return 0;
        }
        
        if(p_dp[i][j]) {
            return 0;
        }
        
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        
        
        
        int mn=INT_MAX;
        
        for(int k=i;k<=j-1;k++) {
            int right=0;
            if(p_dp[i][k]) {
                right=solve(s,k+1,j);
            }
            else {
                dp[i][k]=0;
                continue;
            }
            
            mn=min(mn,1+right);
        }
        
        return dp[i][j]=mn;
        
    }
    
    
    void pre(string s) {
            
        int n=s.size();
        
        for(int i=0;i<s.size();i++) {
            p_dp[i][i]=1;
        }
        
        for(int l=2;l<=n;l++) {
            for(int i=0;i<=n-l;i++) {
                int j=i+l-1;
                if(l==2) {
                    p_dp[i][j]=(s[i]==s[j]);
                }
                else {
                    p_dp[i][j]=(s[i]==s[j]&&p_dp[i+1][j-1]);
                }
            }
        }
        
    }
    
    
    int minCut(string s) {
        
        memset(dp,-1,sizeof(dp));
        memset(p_dp,0,sizeof(p_dp));
        
        pre(s);
        
        int n=s.size();
        
        return solve(s,0,n-1);
        
    }
};