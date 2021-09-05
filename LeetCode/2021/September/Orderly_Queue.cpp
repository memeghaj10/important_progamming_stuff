class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1) {
            sort(s.begin(),s.end());
            return s;
        }
        
       string r=s;
        
        int n=s.size();
        
        while(n--) {
            
            char c=s[0];
            s.erase(s.begin());
            s+=c;
            
            r=min(r,s);
            
        }
        
        
        return r;
        
    }
};