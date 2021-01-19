class Solution {
public:
    string longestPalindrome(string s) {
            
            string n="@";
            n+="#";
        
            for(int i=0;i<s.size();i++) {
                n+=s[i];
                n+="#";
            }
            n+="$";
        
            int y=n.size();
            int p[y];
            memset(p,0,sizeof(p));
            
            int c=0;
            int r=0;
        
            cout<<n<<endl;
        
            
            for(int i=0;i<y;i++) {
                    
                    int mirror=2*c-i;
                
                    if(r>i) {
                            p[i]=min(r-i,p[mirror]);
                    }
                
                    if(i>=1&&i<y-1) {
                        while(n[i+1+p[i]]==n[i-1-p[i]]) {
                        p[i]++;
                    }
                    }
                
                if(i+p[i]>r) {
                    r=i+p[i];
                    c=i;
                }
                
            }
        
        
        
        for(int i:p) {
            cout<<i<<" ";
        }
        
        int max_palin=0;
        int center_index=0;
        
        
        for(int i=1;i<n.size();i++) {
            if(p[i]>max_palin) {
                max_palin=p[i];
                center_index=i;
            }
        }
        
        string u=n.substr((center_index-max_palin),2*max_palin);
        string l="";
        for(int i=0;i<u.size();i++) {
            if(u[i]!='#') {
                l+=u[i];
            }
        }
        
        return l;
        
    }
};