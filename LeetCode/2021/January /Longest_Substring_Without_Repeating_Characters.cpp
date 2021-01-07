class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        
        if(n==0) {
            return 0;
        }  
        
        vector<int> v(256,-1);
        
        int res=0;
        
        int prev=0;
        
        for(int i=0;i<n;i++) {
                      
                    int j=v[s[i]]+1;                
                    prev=max(prev,j);       
                    res=max(res,i-prev+1);
                    v[s[i]]=i;                
                      
        }
        
        return res;
        
    }
};