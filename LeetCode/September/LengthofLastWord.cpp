class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0;
        
        string h="";
        
        vector<string> v;
        
        for(int i=0;i<s.length();i++) {
            if(s[i]!=' ') {
                h+=s[i];
            }
            
            else {
               if(h.size()!=0) {
                    v.push_back(h);
               }
                h="";
            }
        }
        
      if(h.size()!=0)  {
          v.push_back(h);
      }
        
        if(v.size()==0) {
         return 0;
        }
          
          
        
        return v[v.size()-1].size();
        
        
    }
};