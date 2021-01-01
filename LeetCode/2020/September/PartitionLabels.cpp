class Solution {
public:
    vector<int> partitionLabels(string S) {
        
            vector<int> y;
        
            map<char,int> mp;
        
            for(int i=0;i<S.length();i++) {
                mp[S[i]]=i;
            }
        
        
        vector<char> v;
        
        set<char> st;
        
        
        if(S.length()==1) {
            y.push_back(1);
            
            return y;
        }
      
        
        for(int i=0;i<S.length();i++) {
                v.push_back(S[i]);
                st.insert(S[i]);
                int h=0;
                for(auto x:st) {
                    if(mp[x]>i) {
                        h=1;
                        break;
                    }
                }
            
                if(h==0) {
                    y.push_back(v.size());
                    v.clear();
                    st.clear();
                }
        }
        
        
        return y;
            
        
    }
};