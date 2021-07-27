class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minGap = INT_MAX;
        int ans = 0;
        for(auto i = nums.begin(); i != nums.end() - 2; i++){
            auto j = i + 1, k = nums.end() - 1;
            while(j < k){
                int sums = *i + *j + *k;
                if(sums == target) return sums;
                int gap = abs(target - sums);
                if(gap < minGap){
                    minGap = gap;
                    ans = sums;
                }
                sums < target ? j++ : k--;
            }
        }
        return ans;
    }