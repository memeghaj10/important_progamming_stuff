class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        
        int n=s.size();
        
        int pre[n+1];
        pre[0]=0;
        
        
        for(int i=0;i<n;i++) {
            pre[i+1]=pre[i]+s[i]-'0';
        }
        
        int ans=INT_MAX;
        
        for(int j=0;j<=n;j++) {
            ans=min(ans,pre[j]+n-j-(pre[n]-pre[j]));
        }
        
        return ans;        
    }
};