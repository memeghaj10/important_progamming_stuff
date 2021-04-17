class Solution {
public:
    
    int sub_array_sum_k(vector<int> v,int k) {
        
            int n=v.size();
        
            map<int,int> mp;
        
            vector<int> prefix(n);
            
            prefix[0]=v[0];
        
            for(int i=1;i<n;i++) {
                prefix[i]=prefix[i-1]+v[i];
            }
        
            mp[0]=1;
            int c=0;
            
            for(int i=0;i<n;i++) {
                int u=prefix[i]-k;
                
                if(mp.find(u)!=mp.end()) {
                    c+=mp[u];
                }
                
                
                mp[prefix[i]]++;
                
            }
        
        
            return c;
        
    }
    
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
     
        int n=matrix.size();
        
        if(n==0) {
            return 0;
        }
        
        int m=matrix[0].size();        
        
        vector<vector<int>> dp(n,vector<int>(m));
        
        dp=matrix;
        
        for(int j=1;j<m;j++) {
            for(int i=0;i<n;i++) {
                dp[i][j]+=dp[i][j-1];
            }
        }
    
        
        int count=0;
        
        
        for(int j1=0;j1<m;j1++) {
            for(int j2=j1;j2<m;j2++) {
                
                    vector<int> sums(n);
                
                    for(int i=0;i<n;i++) {
                        if(j1==0) {
                            sums[i]=dp[i][j2]-dp[i][j1]+matrix[i][j1];
                        }
                        
                        else {
                            sums[i]=dp[i][j2]-dp[i][j1-1];
                        }
                    }
                                    
                    int y=sub_array_sum_k(sums,target);
                   
                    count+=y;
                
            }
        }
        
        return count;
        
    }
};