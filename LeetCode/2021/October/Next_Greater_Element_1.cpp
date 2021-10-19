class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;
        for(auto x: nums2){
            while(st.size() && st.top() < x){
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        for(auto x: nums1) ans.push_back(mp[x] ? mp[x] : -1);
        return ans;
    }
};