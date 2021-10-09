class Solution {
public:
    vector<vector<char>> board;
    int rows;
    int cols;
    bool wordExists(int row, int col, const string &word, int idx) {
        if(idx == word.size()) {
            return true;
        }
        if(row < 0 || row == rows || col < 0 || col == cols) {
            return false;
        }
        if (board[row][col] != word[idx] ){
            return false;
        }
        bool ret = false;
        board[row][col] = '#';
        int rowsL[] = {0,1,0,-1};
        int colsL[] = {1,0,-1,0};
        for(int d = 0; d < 4 ;++d) {
            ret = this->wordExists(row+rowsL[d], col+colsL[d], word, idx+1);
            if(ret) break;
        }

        board[row][col] = word[idx];
        return ret; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(this->wordExists(row, col, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> S;
        this->board = board;
        this->rows = board.size();
        this->cols = board[0].size();
        for(auto &word: words) {
            reverse(word.begin(), word.end());
            if(exist(board, word)) {
                reverse(word.begin(), word.end());
                S.push_back(word);
            }
        }
        return S;
    }
};