class Solution {
public:
    string reverseWords(string s) {
     
            string h="";
        
            string ans="";
        
            reverse(s.begin(),s.end());
        
            for(int i=0;i<s.size();i++) {
                if(s[i]!=' ') {
                    h+=s[i];
                }
                
                else {
                    if(h.size()==0) {
                        continue;
                    }
                    reverse(h.begin(),h.end());
                    if(ans.size()==0) {
                        ans+=h;
                    }
                    
                    else {
                        ans+=' ';
                        ans+=h;
                    }
                    h="";
                }
            }
        
            if(h.size()>0) {
                reverse(h.begin(),h.end());
                if(ans.size()==0) {
                        ans+=h;
                    }
                    
                    else {
                        ans+=' ';
                        ans+=h;
                    }
            }
        return ans;
        
    }
};