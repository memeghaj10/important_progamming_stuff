/*

Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points.
6 total points are earned.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.



*/



class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        
        map<int,int> mp;
        
        vector<pair<int,int>> vp;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }
        
        
        for(auto x:mp) {
            vp.push_back(make_pair(x.first,x.second));
        }
        
        int m=vp.size();
        
        vector<vector<int>> dp(m,vector<int>(2,0));
        
        dp[0][0]=0;                         //not include
        dp[0][1]=vp[0].first*vp[0].second;  //include
        
        for(int i=1;i<m;i++) {
                
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            
                if(vp[i].first==vp[i-1].first+1) {
                    dp[i][1]=dp[i-1][0]+vp[i].first*vp[i].second;
                }
            
                else {
                    dp[i][1]=vp[i].first*vp[i].second+max(dp[i-1][0],dp[i-1][1]);
                }
            
        }
        
        return max(dp[m-1][0],dp[m-1][1]);
    }
};