class Solution {
public:
    
    bool isvowel(char c) {
            
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                return 1;
            }
        
            if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
                return 1;
            }
        
        return 0;
        
    }
    
    bool halvesAreAlike(string s) {
        
        int c1=0;
        int c2=0;
        
        for(int i=0;i<s.size();i++) {
            if(i<s.size()/2&&isvowel(s[i])) {
                c1++;
            }
            
            else if(i>=s.size()/2&&isvowel(s[i])) {
                c2++;
            }
        }
        
        return c1==c2;
        
    }
};