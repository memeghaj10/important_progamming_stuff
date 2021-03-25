class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if(!matrix.size()||!matrix[0].size()) {
            return res;
        }
        
        n=matrix.size();
        m=matrix[0].size();
        states.assign(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++) {
            recDFS(matrix,i,0,INT_MIN,1);
            recDFS(matrix,i,m-1,INT_MIN,2);
        }
        
        for(int i=0;i<m;i++) {
            recDFS(matrix,0,i,INT_MIN,1);
            recDFS(matrix,n-1,i,INT_MIN,2);
        }
        
        return res;
        
    }

    
private:
    vector<vector<int>> res,states;
    vector<int> x_pts={1,0,-1,0};
    vector<int> y_pts={0,1,0,-1};
    int m,n;
    
    bool isValid(int x,int y) {
        return x<n and x>=0 and y<m and y>=0;
    }
    
    void recDFS(vector<vector<int>>& mat, int x,int y,int prev,int prev_state) {
        
        if(!isValid(x,y)||mat[x][y]<prev||states[x][y]==prev_state||states[x][y]==3) {
            return ;
        }
        
        states[x][y]+=prev_state;
        
        if(states[x][y]==3) {
            res.push_back({x,y});
        } 
        
        for(int i=0;i<4;i++) {
            recDFS(mat,x+x_pts[i],y+y_pts[i],mat[x][y],prev_state);
        }
        
    }
    
};