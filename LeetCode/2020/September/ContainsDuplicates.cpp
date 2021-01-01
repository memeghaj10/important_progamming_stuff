
    class Solution {
public:
   bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<2 || k==0)
            return false;
        set<long> ans;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(abs(i-l) > k)
                ans.erase(nums[l++]);
            auto it = ans.lower_bound((long)nums[i] - (long)t);
            if(it != ans.end() && *it <= ((long)nums[i] + (long)t))
                return true;
            ans.insert(nums[i]);
        }
        return false;
    }
};

