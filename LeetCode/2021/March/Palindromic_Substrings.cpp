class Solution {
public:
    
    int dp[1001][1001];
    
    bool ispalin(int i,int j, string s) {
        
        if(i>j) {
            return 1;
        }
        
        else if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        
        if(s[i]!=s[j]) {
            return dp[i][j]=0;
        }
        
        return dp[i][j]=ispalin(i+1,j-1,s);
        
    }
    
    int countSubstrings(string s) {
        
        memset(dp,-1,sizeof(dp));
        
        int n=s.size();
        int c=0;
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                c+=ispalin(i,j,s);
            }
        }
       
        return c+s.size();
        
    }
};