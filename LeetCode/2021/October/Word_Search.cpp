class Solution {
public:
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool solve(vector<vector<char>>& board, string& word, int idx, int x, int y, int &row, int &col){
        if(idx==word.size()) return true;
        if(x<0 or x>=row or y<0 or y>=col or board[x][y]=='#' or word[idx]!=board[x][y]) return false;
        char ch = board[x][y];
        board[x][y]='#';
        for(int i=0;i<4;++i){
            int x1=x+dx[i], y1=y+dy[i];
            if(solve(board,word,idx+1,x1,y1,row,col)) return true;
        }
        board[x][y]=ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col=board[0].size();
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(word[0]==board[i][j] and solve(board,word,0,i,j,row,col)) return true;
            }
        }
        return false;
    }
};