class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        
        vector<string> vs;
        
         string h="";
        
        for(int i=0;i<str.length();i++) {
           if(str[i]==' ') {
               vs.push_back(h);
                 h="";
           }
            else {
                h+=str[i];
            }
        }
        
        vs.push_back(h);
        
        if(vs.size()!=pattern.size()) {
            return 0;
        }
        
        
        set<char> st;
        set<string> st1;
        
        for(int i=0;i<pattern.size();i++) {
            st.insert(pattern[i]);
            st1.insert(vs[i]);
        }
        
        if(st.size()==st1.size()) {
            
            map<char,string> mp;
            
            for(int i=0;i<pattern.size();i++) {
                mp[pattern[i]]=vs[i];
            }
            
            for(int i=0;i<pattern.size();i++) {
                if(mp[pattern[i]]!=vs[i]) {
                    return 0;
                }
            }
            
            
            return 1;
            
            
        }
        
        
        else {
            return 0;
        }
            
        
        
        
    }
};