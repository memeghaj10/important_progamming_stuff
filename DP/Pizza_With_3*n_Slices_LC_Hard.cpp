/*

There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick next slice in anti clockwise direction of your pick. 
Your friend Bob will pick next slice in clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Sizes of Pizza slices is represented by circular array slices in clockwise direction.

Return the maximum possible sum of slice sizes which you can have.

 

Example 1:



Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
Example 2:



Input: slices = [8,9,8,6,1,1]
Output: 16
Output: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
Example 3:

Input: slices = [4,1,2,5,8,3,1,9,7]
Output: 21
Example 4:

Input: slices = [3,1,2]
Output: 3
 

Constraints:

1 <= slices.length <= 500
slices.length % 3 == 0
1 <= slices[i] <= 1000


Hints:-

By studying the pattern of the operations, we can find out that the problem is equivalent to: Given an integer array with size 3N, select N integers with maximum sum and any selected integers are not next to each other in the array.

The first one in the array is considered next to the last one in the array. Use Dynamic Programming to solve it.


*/



class Solution {
public:
    
    int dp[501][501/3+1];
    vector<int> s;
    
    
    int solve(int start, int end, int pieces) {
        
        if(pieces==0) {
            return 0;
        }
        
        if(start>=end) {
            return 0;
        }
        
        if(dp[start][pieces]!=-1)
        {
            return dp[start][pieces];
        }        
        
        return dp[start][pieces]=max(s[start]+solve(start+2,end,pieces-1),solve(start+1,end,pieces));
        
    }
    
    
    int maxSizeSlices(vector<int>& slices) {
     
        int n=slices.size();
        s=slices;
     
        memset(dp,-1,sizeof(dp));
        
        int ans=solve(0,n-1,n/3);
        
        memset(dp,-1,sizeof(dp));
        
        ans=max(ans,solve(1,n,n/3));
        
        return ans;        
        
    }
};