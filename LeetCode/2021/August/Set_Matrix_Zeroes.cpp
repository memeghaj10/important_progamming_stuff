class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int row_z=0;
        int col_z=0;
        
        for(int j=0;j<m;j++) {
            if(matrix[0][j]==0) {
                row_z=1;
                break;
            }
        }
        
        for(int i=0;i<n;i++) {
            if(matrix[i][0]==0) {
                col_z=1;
                break;
            } 
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<n;i++) {
            if(matrix[i][0]==0) {
                for(int j=0;j<m;j++) {
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int j=1;j<m;j++) {
            if(matrix[0][j]==0) {
                for(int i=0;i<n;i++) {
                    matrix[i][j]=0;
                }
            }
        }
        
        if(row_z) {
            matrix[0]=vector<int>(m,0);
        }
        
        if(col_z) {
            for(int i=0;i<n;i++) {
                matrix[i][0]=0;
            }
        }
        
    }
};