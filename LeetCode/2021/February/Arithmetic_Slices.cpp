class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        
        int n=a.size();
        
        if(n<3) {
            return 0;
        }
        
        int d=a[1]-a[0];
        
        int run=0;
        int ans=0;
        
        for(int i=2;i<n;i++) {
            if(a[i]-a[i-1]==d) {
                run++;
            }
            
            else 
            {
                ans+=(run*(run+1))/2;
                run=0;
                d=a[i]-a[i-1];
            }
        }
        
        ans+=(run*(run+1))/2;
        
        return ans;
        
    }
};