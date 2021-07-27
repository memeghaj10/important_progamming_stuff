/*

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

*/


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

};