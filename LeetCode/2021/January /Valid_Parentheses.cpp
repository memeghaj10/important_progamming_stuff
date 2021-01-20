class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        int n=s.size();
        
        if(n==1) {
            return 0;
        }
        
        
        for(int i=0;i<n;i++) {
            if(s[i]==40||s[i]==91||s[i]==123) {
                st.push(s[i]);
            }
            
            else{
                
              if(st.size()!=0) {
                    if(st.top()+2==s[i]||st.top()+1==s[i]) {
                    st.pop();
                }
                   else {
                    return 0;
                }
              }
                
                else {
                    st.push(s[i]);
                }
                
               
            }
       }
        
        if(st.size()==0) {
            return 1;
        }
        
        return 0;
        
    }
};