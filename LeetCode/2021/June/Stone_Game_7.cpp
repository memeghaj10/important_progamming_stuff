class Solution {
public:
    
    int dp[1002][1002][2];
    
    int solve(int i,int j,int sum,vector<int>& v,int x) {
        
        if(j==i) {
            return 0;
        }
        
        if(dp[i][j][x]!=-1) {
            return dp[i][j][x];
        }
        
        else if(x==1) {
            
            return dp[i][j][x]=max(sum-v[i]+solve(i+1,j,sum-v[i],v,0),(sum-v[j]+solve(i,j-1,sum-v[j],v,0)));
            
        }
        
        return dp[i][j][x]=min(-1*(sum-v[i])+solve(i+1,j,sum-v[i],v,1),-1*(sum-v[j])+solve(i,j-1,sum-v[j],v,1));
        
    }
    
    
    int stoneGameVII(vector<int>& stones) {
        
        int n=stones.size();
        
        memset(dp,-1,sizeof(dp));
        
        int sum=accumulate(stones.begin(),stones.end(),0);
        
        return solve(0,n-1,sum,stones,1);
        
    }
};