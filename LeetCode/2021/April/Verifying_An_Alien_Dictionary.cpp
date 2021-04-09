class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        
        map<char,int> mp;
        
        for(int i=0;i<26;i++) {
            mp[order[i]]=i;
        }
        
        int n=words.size();
        
        for(int i=0;i<n-1;i++) {
            
                int w1=words[i].size();
                int w2=words[i+1].size();
            
                
            
                int f=0;
            
                for(int j=0;j<min(w1,w2);j++) {
                    if(mp[words[i][j]]==mp[words[i+1][j]]) {
                         if(j==min(w1,w2)-1) {
                        if(w1>w2) {
                            f=1;
                        }
                    }
                        continue;
                    }
                    
                    else if(mp[words[i][j]]<mp[words[i+1][j]]) {
                        break;
                    }
                    
                    else {
                        f=1;
                        break;
                    }
                    
                   
                }
            
            if(f) {
                return 0;
            }
            
        }
        
        return 1;
        
        
    }
};