class Solution {
public:
    vector<int> constructArray(int n, int k) {
      
        vector<int> ans(n);
        
        for(int i=0;i<=k;i++) {
            if(i==0) {
                ans[i]=1;
            }
            else if(i==1) {
                ans[i]=k+1;
            }
            else {
                if(i%2==0) {
                    ans[i]=ans[i-2]+1;
                }
                else {
                    ans[i]=ans[i-2]-1;
                }
            }
        }
        
        for(int i=k+1;i<n;i++) {
            ans[i]=i+1;
        }
        
        return ans;
        
    }
};