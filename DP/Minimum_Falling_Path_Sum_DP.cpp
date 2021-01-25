/*
	
	Given a square grid of integers arr, a falling path with non-zero shifts is a choice of exactly one element from each row of arr, such that no two elements chosen in adjacent rows are in the same column.

	Return the minimum sum of a falling path with non-zero shifts.


	Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
	Output: 13
	Explanation: 
	The possible falling paths are:
	[1,5,9], [1,5,7], [1,6,7], [1,6,8],
	[2,4,8], [2,4,9], [2,6,7], [2,6,8],
	[3,4,8], [3,4,9], [3,5,7], [3,5,9]
	The falling path with the smallest sum is [1,5,7], so the answer is 13.


*/



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        int n=arr.size();
        int m=arr[0].size();
        
        for(int i=1;i<n;i++) {
            vector<int> left(m);
            vector<int> right(m);
            
            left[0]=arr[i-1][0];
            
            for(int j=1;j<m;j++) {
                left[j]=min(left[j-1],arr[i-1][j]);
            }
            
            right[m-1]=arr[i-1][m-1];
            
            for(int j=m-2;j>=0;j--) {
                right[j]=min(right[j+1],arr[i-1][j]);
            }
            
            
            for(int j=0;j<m;j++) {
                int l,r;    
                if(j==0) {
                        l=INT_MAX;
                    }
                
                else {
                    l=left[j-1];
                }
                
                if(j==m-1) {
                    r=INT_MAX;
                }
                
                else {
                    r=right[j+1];
                }
                
                arr[i][j]+=min(l,r);
                
            }
            
        }
        
        return *min_element(arr[n-1].begin(),arr[n-1].end());
        
        
    }
};