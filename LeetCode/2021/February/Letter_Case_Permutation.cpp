class Solution {
public :
    vector<string> letterCasePermutation(string s) {
        
        vector<string> vs;
        string y="";
        vs.push_back(y);
        
        for(int i=0;i<s.size();i++) {
            if(s[i]>='0'&&s[i]<='9') {
                for(int j=0;j<vs.size();j++) {
                    vs[j]+=s[i];
                }
            }
            else {
                vector<string> h=vs;
                
                for(int j=0;j<vs.size();j++) {
                    vs[j]+=s[i];
                }
                
                char t=s[i];
                if(s[i]<='Z') {
                    t+=32;
                }
                else {
                    t-=32;
                }
                
                for(int j=0;j<h.size();j++) {
                    h[j]+=t;
                }
                
                for(int j=0;j<h.size();j++) {
                    vs.push_back(h[j]);
                }
            }
        }
        
        return vs;
        
    }
};