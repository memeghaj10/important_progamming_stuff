class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        
            vector<vector<int>> matrix(N,vector<int>(N,1));
        
            for(int i=0;i<mines.size();i++) {
                matrix[mines[i][0]][mines[i][1]]=0;
            }     
           
        
            vector<vector<int>> left(N,vector<int>(N,0));
            vector<vector<int>> right(N,vector<int>(N,0));
            vector<vector<int>> up(N,vector<int>(N,0));
            vector<vector<int>> down(N,vector<int>(N,0));

            for(int i=0;i<N;i++) {
                for(int j=1;j<N;j++) {
                    if(matrix[i][j]!=0) {
                        if(matrix[i][j-1]!=0) {
                            left[i][j]=left[i][j-1]+1;
                       }
                        else {
                            left[i][j]=0;
                        }
                    }
                }
            }
        
              
        
            for(int i=0;i<N;i++) {
                for(int j=N-2;j>=0;j--) {
                    if(matrix[i][j]!=0) {
                        if(matrix[i][j+1]!=0) {
                            right[i][j]=right[i][j+1]+1;
                       }
                        else {
                            right[i][j]=0;
                        }
                    }
                }
            }
        
            for(int j=0;j<N;j++) {
                for(int i=1;i<N;i++) {
                    if(matrix[i][j]!=0) {
                        if(matrix[i-1][j]!=0) {
                            up[i][j]=up[i-1][j]+1;
                        }
                        else {
                            up[i][j]=0;
                        }
                    }
                }
            }
        
             for(int j=0;j<N;j++) {
                for(int i=N-2;i>=0;i--) {
                    if(matrix[i][j]!=0) {
                        if(matrix[i+1][j]!=0) {
                            down[i][j]=down[i+1][j]+1;
                        }
                        else {
                            down[i][j]=0;
                        }
                    }
                }
            }
        
        int ans=0;
        
            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                   if(matrix[i][j]) {
                        ans=max(ans,min({up[i][j],down[i][j],right[i][j],left[i][j]})+1);
                   }
                }
            }
        
        return ans;
        
    }
};