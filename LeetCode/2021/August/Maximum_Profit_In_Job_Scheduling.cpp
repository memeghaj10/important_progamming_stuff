class Solution {
public:


    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       
        vector<vector<int>> v(startTime.size(),vector<int>(3));
        
        for(int i=0;i<startTime.size();i++) {
           v[i]={endTime[i],startTime[i],profit[i]};
        } 
        
        sort(v.begin(),v.end());
        
        int n=v.size();
        
        vector<int> dp(n,0);
        dp[0]=v[0][2];
        
        for(int i=1;i<n;i++) {
            
            int curr=v[i][2];
            
                int l=-1;
            
                int lo=0;
                int hi=i-1;

                while(lo<=hi) {
                    int mid=(lo+hi)/2;
                    if(v[mid][0]<=v[i][1]) {
                        if(v[mid+1][0]<=v[i][1]) {
                            lo=mid+1;
                        }
                        else {
                            l=mid;
                            break;
                        }
                    }
                    else {
                        hi=mid-1;
                    }
                }

            
            
            if(l!=-1) {
                curr+=dp[l];
            }
            
            dp[i]=max(dp[i-1],curr);
            
        }
        
        return dp[n-1];
        
    }
};