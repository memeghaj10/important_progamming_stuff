class Solution {
public:
    
    bool dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board,int n,int m) {
        
        vis[i][j]=1;
        
        if(i==0||i==n-1||j==0||j==m-1) {
            return false;
        }
        
        bool p=true;
        
        if(i-1>=0&&board[i-1][j]=='O'&&!vis[i-1][j]) {
            p=p&dfs(i-1,j,vis,board,n,m);
        }
        
        if(i+1<n&&board[i+1][j]=='O'&&!vis[i+1][j]) {
            p=p&dfs(i+1,j,vis,board,n,m);
        }
        
        if(j-1>=0&&board[i][j-1]=='O'&&!vis[i][j-1]) {
            p=p&dfs(i,j-1,vis,board,n,m);
        }
        
        if(j+1<m&&board[i][j+1]=='O'&&!vis[i][j+1]) {
            p=p&dfs(i,j+1,vis,board,n,m);
        }
        
        return p;
        
    }
    
    void mark(int i,int j,vector<vector<char>>& board,int n,int m) {
        
        board[i][j]='X';
        
        if(i-1>=0&&board[i-1][j]=='O') {
            mark(i-1,j,board,n,m);
        }
        
        if(i+1<n&&board[i+1][j]=='O') {
            mark(i+1,j,board,n,m);
        }
        
        if(j-1>=0&&board[i][j-1]=='O') {
            mark(i,j-1,board,n,m);
        }
        
        if(j+1<m&&board[i][j+1]=='O') {
            mark(i,j+1,board,n,m);
        }
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                if(board[i][j]=='O'&&!vis[i][j]) {
                   if(dfs(i,j,vis,board,n,m)) {
                       mark(i,j,board,n,m);
                   }
                }
            }
        }
        
    }
};