class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        set<int> st;
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
            st.insert(nums[i]);
        }
        
        vector<int> v;
        
        for(auto x:st) {
            v.push_back(x);
        }
        
        int ans=0;
        
        for(int i=0;i<v.size()-1;i++) {
            if(v[i]+1==v[i+1]) {
                ans=max(ans,mp[v[i]]+mp[v[i+1]]);
            }
        }
        
        return ans;
        
        
    }
};