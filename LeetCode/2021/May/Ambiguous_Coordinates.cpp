class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        
            int n=s.size();
            vector<string> res;
        
            for(int i=1;i<n-2;i++) {
                if(isvalid(s,1,i)&&isvalid(s,i+1,n-2)) {
                    vector<string> x=getData(s.substr(1,i-1+1));
                    vector<string> y=getData(s.substr(i+1,n-2-i));
                    
                    for(auto s1:x) {
                        for(auto s2:y) {
                            res.push_back("("+s1+", "+s2+")");
                        }
                    }
                    
                }
            }
        
        
        
        
        return res;
    }
    
    bool isvalid(string s,int i,int j) {
        
        if(i==j||s[i]!='0') {
            return true;
        }
        
        return s[j]!='0';
        
    }
    
    
    vector<string> getData(string s) {
        
        if(s.back()=='0') {
            return {s};
        }
        
        if(s[0]=='0') {
            return {s.insert(1,1,'.')};
        }
        
        vector<string> res;
        
        for(int i=1;i<s.size();i++) {
            string ss=s;
            res.push_back(ss.insert(i,1,'.'));
        }
        
        res.push_back(s);
        
        return res;
        
    }
    
    
};