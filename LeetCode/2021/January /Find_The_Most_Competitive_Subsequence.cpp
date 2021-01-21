class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        stack<int> st;
        int n=nums.size();
        
        for(int i=0;i<n;i++) {
                 while(!st.empty()&&st.top()>nums[i]&&st.size()+n-i>k) {
                    st.pop();
                }
              if(st.size()<k) {
                    st.push(nums[i]);
              }            
        }
        
        
        vector<int> v;
        
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        
        reverse(v.begin(),v.end());
        
        return v;
        
    }
};