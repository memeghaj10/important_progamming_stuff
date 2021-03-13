class Solution {
public:
    
    #define mod 1000000007
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        long long int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        long long int dp[n];
        
        map<long long int,long long int> mp;
        
        for(int i=0;i<n;i++) {
            dp[i]=1;
            mp[arr[i]]=dp[i];
        }
        
        for(int i=1;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(arr[i]%arr[j]==0) {
                    dp[i]=dp[i]%mod+((dp[j]%mod)*(mp[arr[i]/arr[j]]%mod))%mod;
                }
            }
            mp[arr[i]]=dp[i]%mod;
        }
        
        long long int sum=0;
        
        sum=accumulate(dp,dp+n,sum);
        
        return sum%mod;
        
    }
};