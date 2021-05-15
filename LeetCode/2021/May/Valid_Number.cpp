class Solution {
public:
    bool isNumber(string s) {
        
        int n=s.size();
        
        int i=0;
        
        while(s[i]==' ') {
            i++;
        }
        
        if(s[i]=='+'||s[i]=='-') {
            i++;
        }
        
        int dot=0,num=0;
        
        while(s[i]<='9'&&s[i]>='0'||s[i]=='.') {
            if(s[i]=='.') {
                dot++;
                i++;
            }
            else {
                num++;
                i++;
            }
        }
        
        if(dot>1) {
            return false;
        }
        
        if(num<1) {
            return false;
        }
        
        num=0;
        
        if(s[i]=='e'||s[i]=='E') {
            i++;
            
            if(s[i]=='+'||s[i]=='-') {
                i++;
            }
            
            while(s[i]<='9'&&s[i]>='0') {
                num++;
                i++;
            }
            
            if(num<1) {
                return false;
            }
            
        }
        
        while(s[i]==' ') {
            i++;
        }
        
        return n==i;
        
    }
};