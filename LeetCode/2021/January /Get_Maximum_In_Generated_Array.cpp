class Solution {
public:
    int getMaximumGenerated(int n) {
        
        
        if(n==0) {
            return 0;
        }
        
        vector<int> v(n+1);
        
        v[0]=0;
        v[1]=1;
        
        for(int i=1;2*i+1<=n;i++) {
            v[2*i]=v[i];
            v[2*i+1]=v[i]+v[i+1];
        }
    
        return *max_element(v.begin(),v.end());
    }
};