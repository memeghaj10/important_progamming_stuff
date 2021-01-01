class Solution {
public:
    string getHint(string secret, string guess) {
        
        string s=secret;
        string g=guess;
        
    sort(s.begin(),s.end());
    sort(g.begin(),g.end());
        
        if(s==g) {
            int c=0;
            s=secret;
            g=guess;
            for(int i=0;i<secret.size();i++) {
                if(s[i]==g[i]) {
                    c++;
                }
            }
            
            string h="";
            h+=to_string(c);
            h+='A';
            h+=to_string(secret.size()-c);
            h+='B';
            
            return h;
        }
        
        
        else {
                
            int c=0;
            int d=0;
            
            s=secret;
            g=guess;
            
            for(int i=0;i<secret.size();i++) {
                if(s[i]==g[i]) {
                    s[i]='.';
                    g[i]='.';
                    c++;
                }
            }
            
            for(int i=0;i<s.length();i++) {
                if(s[i]!=g[i]) {
                    for(int j=0;j<s.size();j++) {
                        if(s[j]==g[i]) {
                            s[j]='.';
                            g[i]='.';
                            d++;
                            break;
                        }
                    }
                    }
            }
            
            string h="";
            h+=to_string(c);
            h+='A';
            h+=to_string(d);
            h+='B';
            return h;
            
        }
        
        
        
        
        
    }
};