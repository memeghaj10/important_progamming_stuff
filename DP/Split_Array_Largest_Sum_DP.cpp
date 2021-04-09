/*

Given an array nums which consists of non-negative integers and an integer m,
you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9


*/


// DP Solution :-
// Time Complexity: O(n*n*m)
// Space Complexity: O(n*m)

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(m+1,INT_MAX));
        
        vector<int> pre(n+1,0);
        
        for(int i=1;i<=n;i++) {
            pre[i]=pre[i-1]+nums[i-1];
        }
        
        for(int i=0;i<n;i++) {
            dp[i][1]=pre[i+1];
        }
        
        for(int i=1;i<n;i++) {
            for(int j=2;j<=min(m,i+1);j++) {
                    for(int k=0;k<i;k++) {
                        dp[i][j]=min(dp[i][j],max(dp[k][j-1],pre[i+1]-pre[k+1]));
                    }
            }
        }
        
        return dp[n-1][m];
        
    }
};



// Binary Search Solution :-
// Time COmplexity :  O(nlog(n))
// Space Complexity:  O(n)




class Solution {
public:
    
    bool check(int x,int m,vector<int> nums) {
            
        int cnt=0;
        int sum=0;
        
        for(int i=0;i<nums.size();i++) {
            if(sum+nums[i]>x) {
                cnt++;
                sum=0;
            }
            sum+=nums[i];
        }
        
        return cnt+1<=m;
        
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        
        int n=nums.size();
        
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        
        while(l<r) {
                
                int mid=(l+r)/2;
            
                if(check(mid,m,nums)) {
                    r=mid;
                }
            
               else {
                l=mid+1;    
            }
            
        }
        
        return r;
        
    }
};

