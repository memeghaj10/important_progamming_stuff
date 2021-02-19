class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
            stack<pair<char,int>> st;
        
            int n=s.size();
        
            for(int i=0;i<n;i++) {
                if(s[i]==')') {
                    if(st.size()!=0&&st.top().first=='(') {
                        st.pop();
                    }
                    
                    else {
                        st.push(make_pair(s[i],i));
                    }
                }
                
                else if(s[i]=='(') {
                    st.push(make_pair(s[i],i));
                }
            }
        
            if(st.size()==0) {
                return s;
            }
        
            vector<int> v;
        
            while(st.size()) {
                v.push_back(st.top().second);
                st.pop();
            }
        
            string y="";
            
            for(int i=0;i<s.size();i++) {
                if(count(v.begin(),v.end(),i)==0) {
                    y+=s[i];
                }
            }
        
            return y;
        
    }
};