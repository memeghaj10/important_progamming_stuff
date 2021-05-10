/*

    You are given an array nums​​​ and an integer k​​​​​. The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].

Return the minimum number of elements to change in the array such that the XOR of all segments of size k​​​​​​ is equal to zero.

 

Example 1:

Input: nums = [1,2,0,3,0], k = 1
Output: 3
Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
Example 2:

Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
Output: 3
Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].
Example 3:

Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
Output: 3
Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].
 

Constraints:

1 <= k <= nums.length <= 2000
​​​​​​0 <= nums[i] < 210

*/








class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        
        int freq[k][1025];
        memset(freq,0,sizeof(freq));
        
        for(int i=0;i<n;i++) {
            freq[i%k][nums[i]]++;
        }
        
        int dp[k+1][1025];
        
        for(int i=0;i<=k;i++) {
                for(int j=0;j<1025;j++) {
                    dp[i][j]=1e9+5;
                }
        }
        
        dp[0][0]=0;
        int prevMin=0;
        
        
        for(int i=0;i<k;i++) {
            
                for(int j=0;j<1025;j++) {
                    
                        for(int z=i;z<n;z+=k) {
                                
                            if((j^nums[z])<1025) {
                                    
                                dp[i+1][j^nums[z]]=min(dp[i+1][j^nums[z]],dp[i][j]+int(ceil((n-i)*1.0/k))-freq[i][nums[z]]);
                                    
                            }
                            
                        }
                    
                }
            
            int prevMin2=1e9+5;
            
            for(int j=0;j<1025;j++) {
                dp[i+1][j]=min(dp[i+1][j],int(ceil((n-i)*1.0/k))+prevMin);
                prevMin2=min(prevMin2,dp[i+1][j]);
            }
            
            prevMin=prevMin2;
        }
        
        
        return dp[k][0];
        
    }
};