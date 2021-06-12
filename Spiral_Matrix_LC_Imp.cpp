
/*

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int> ans;
        
        int j;
        
        int c=min(m,n);
        
        for(int i=0;i<min((m+1)/2,(n+1)/2);i++) {
            for(j=i;j<n-i;j++) {
                ans.push_back(matrix[i][j]);
            }
            for(j=i+1;j<m-i;j++) {
                ans.push_back(matrix[j][n-i-1]);
            }
            c--;
            if(c==0) {
                return ans;
            }
            for(j=n-i-2;j>i;j--) {
                ans.push_back(matrix[m-i-1][j]);
            }
            for(j=m-i-1;j>i;j--) {
                ans.push_back(matrix[j][i]);
            }
            c--;
            if(c==0) {
                return ans;
            }
        }
        
        return ans;
        
    }
};