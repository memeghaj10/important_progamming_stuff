class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        if(r*c!=m*n) {
            return mat;
        }
        
        int x=0;
        int y=0;
        
        vector<vector<int>> ans(r,vector<int>(c));
        
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                ans[i][j]=mat[x][y];
                y++;
                if(y==n) {
                    y=0;
                    x++;
                }
            }
        }
        
        return ans;
        
    }
};