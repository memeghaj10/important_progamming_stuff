/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105



*/

//O(n*n*log(n)) Solution :-

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>> ans;
        
        if(n<3) {
            return ans;
        }
        
        sort(nums.begin(),nums.end()); 
        
        map<vector<int>,int> mp;
        
        for(int i=0;i<n-2;i++) {
         
            int j=i+1;
            int k=n-1;
            
            while(j<k) {
                
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==0) {
                    mp[{nums[i],nums[j],nums[k]}]++;
                    j++;
                    k--;
                } 
                
                if(sum>0) {
                    k--;
                }
                
                if(sum<0) {
                    j++;
                }
                
            }
            
        }
        
        for(auto x:mp) {
            ans.push_back(x.first);
        }
        
        return ans;
    }
};


//O(n*n) Solution :-

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int val=nums[j];
                    while(j<n && val==nums[j])
                    {
                        j++;
                    }
                    val=nums[k];
                    while(k>=0 && val==nums[k])
                    {
                        k--;
                    }
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};