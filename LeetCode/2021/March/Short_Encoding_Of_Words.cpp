class Solution {
public:
    
   static bool comp(string s1,string s2) {
        return s1.size()>s2.size();
    }
    
    
    bool is_suffix(string s1, string s2) {
        
          int n=s1.size();
        
          int j=s2.size()-1;
        
        for(int i=n-1;i>=0;i--) {
            
                if(s1[i]=='#') {
                    int k=i-1;
                    while(k>=0&&j>=0&&s1[k]==s2[j]) {
                        k--;
                        j--;
                    }
                    
                    if(j==-1) {
                        return 1;
                    }
                    
                    else {
                        j=s2.size()-1;
                    }
                }
            
        }
         
        return 0;
        
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        string s="";
        
        sort(words.begin(),words.end(),comp);
        
        int n=words.size();
        
        s+=words[0];
        s+="#";
        
        for(int i=1;i<n;i++) {
            if(is_suffix(s,words[i])) {
                continue;
            }             
            else {
                s+=words[i];
                s+="#";
            }
        }
        
        return s.size();
        
    }
};