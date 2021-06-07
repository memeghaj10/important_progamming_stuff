/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
*/


/*
Solution:-
We will maintain, 2 ptrs here.

1st ptr will maintain the value of the least element in the array, uptill the point traversed, "i".

2nd ptr will maintain the value of the 2nd smallest element in the array, uptill the point traverse, "i".

for each element we will check if the element is bigger than the 2nd smallest element, till the point traversed.

If found at any point, we simply return true.
else false.
*/




class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        
        for(int i=0;i<n;i++) {
            
            if(nums[i]<mini1) {
                mini1=nums[i];
            }
            
            if(nums[i]>mini1&&nums[i]<mini2) {
                mini2=nums[i];
            }
            
            if(nums[i]>mini2) {
                return true;
            }
            
        }
        
        return false;
        
    }
};