class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.size();
        
        stack<pair<int,int>> st;
        
        string ans="";
        
        for(int i=0;i<n;i++) {
            if(st.empty()) {
               st.push(make_pair(s[i],1));
            }
            
            else {
                if(s[i]==st.top().first) {
                    st.top().second=st.top().second+1;
                    
                    if(st.top().second==k) {                       
                        st.pop();
                    }
                    
                }
                
                else {
                    st.push(make_pair(s[i],1));
                }
            }
        }
        
        while(!st.empty()) {
            int q=st.top().second;
            while(q--) {
                ans+=st.top().first;
            }
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};