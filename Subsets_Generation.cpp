/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

*/


/*

if the array has 3 elements, then the possible combination could be pow(2,3).

000
001
010
100
101
111
011
110
 
where '1' stands for inclusion of the element
where '0' stands for exclusion of the element

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;	//answer vectors
        
        int n=pow(2,nums.size());	//total number of subsets
        
        for(int i=0;i<n;i++) {
            vector<int> temp;		//ith subset answer
                
            for(int j=0;j<nums.size();j++) {
                if(i&(1<<j)) {					//checking if the jth element from the nums, 
                    temp.push_back(nums[j]);	//is part of the subset or not.
                }
            }
            
            ans.push_back(temp);	//inserting the temporary vector, into the 
            						//main answer vector
        }
        
        
        return ans;
    }
};