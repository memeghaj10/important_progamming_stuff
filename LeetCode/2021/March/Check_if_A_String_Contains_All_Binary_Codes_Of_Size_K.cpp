class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        set<string> st;
        
        int n=s.size();
        
        for(int i=0;i<n;i++) {
            if(i+k<n+1) {
                string r=s.substr(i,k);
                st.insert(r);
            }
        }
        
        if(pow(2,k)==st.size()) {
            return 1;
        }
        
        return 0;
        
    }
};