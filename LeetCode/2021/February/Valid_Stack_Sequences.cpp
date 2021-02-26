class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        
        int i=0;
        int j=0;
        
        while(j<popped.size()) {
            if(st.empty()||st.top()!=popped[j]) {
                if(i<pushed.size()) {
                    st.push(pushed[i]);
                    i++;
                }
                
                else {
                    return false;
                }
            }
            
            if(!st.empty()&&st.top()==popped[j]) {
                st.pop();
                j++;
            }
        }
        
        if(j==popped.size()&&i==pushed.size()&&st.size()==0) {
            return true;
        }
        
        return false;
        
    }
};