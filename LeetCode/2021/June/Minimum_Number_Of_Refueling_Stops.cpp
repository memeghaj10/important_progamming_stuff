
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        long long int n=stations.size();
        
        vector<long long int> dp(n+1,0);
        
        dp[0]=startFuel;
        
        for(int i=0;i<n;i++) {
            for(int j=i;j>-1;j--) {
                if(dp[j]>=stations[i][0]) {
                    dp[j+1]=max(dp[j+1],dp[j]+stations[i][1]);
                }
            }
        }
     
        for(int i=0;i<n+1;i++) {
            if(dp[i]>=target) {
                return i;
            }
        }
        
        return -1;
        
    }
};