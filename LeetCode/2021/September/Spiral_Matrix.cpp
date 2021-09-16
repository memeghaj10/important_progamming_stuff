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

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