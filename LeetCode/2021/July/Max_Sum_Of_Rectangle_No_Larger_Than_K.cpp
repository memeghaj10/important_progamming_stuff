class Solution {
public:    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(j==0) {
                    dp[i][j]=matrix[i][j];
                }
                else {
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]+=matrix[i][j];
                }
            }
        }
    
        
        int ans=INT_MIN;
        
        for(int i=0;i<m;i++) {
            for(int j=i;j<m;j++) {
                
                vector<int> v;
                
                for(int x=0;x<n;x++) {
                    
                    if(i==0) {
                        v.push_back(dp[x][j]);
                    }
                    
                    else {
                        v.push_back(dp[x][j]-dp[x][i-1]);
                    }
                    
                }
              
                int temp=INT_MIN;
                
                for(int x1=0;x1<n;x1++) {
                    int c=0;
                    for(int x2=x1;x2<n;x2++) {
                        c+=v[x2];
                        if(c<=k) {
                            temp=max(temp,c);
                        }
                    }
                }
                
                //cout<<temp<<endl;
                
                ans=max(ans,temp);
                
            }
        }
        
        
        return ans;
        
    }
};