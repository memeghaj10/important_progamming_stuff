class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        vector<int> v;
        
        set<int> s;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0&&s.find(nums[i])==s.end()) {
                v.push_back(nums[i]);
                s.insert(nums[i]);
            }
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++) {
            if(v[i]!=i+1) {
                return i+1;
            }
        }
        
        return v.size()+1;
        
    }
};