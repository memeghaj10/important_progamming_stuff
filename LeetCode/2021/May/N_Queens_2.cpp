class Solution {
public:
    int totalNQueens(int n) {
	vector<vector<bool>> board(n, vector<bool>(n, false));
	return solve(board, 0);
}
bool check(vector<vector<bool>>& board, int row, int col) {
	int n = size(board);
	for(int i = 0; i <= row; i++) {
		if(board[i][col]) return false; // checking if any queen already placed on same column previously
		// checking if all diagonals are safe -
		if(row - i >= 0 && col - i >= 0 && board[row - i][col - i]) return false;
		if(row - i >= 0 && col + i <  n && board[row - i][col + i]) return false;
	}
	return true;
}    
int solve(vector<vector<bool>>& board, int row) {
	if(row == size(board)) return 1;
	int count = 0;
	for(int col = 0; col < size(board); col++)           
		if(check(board, row, col)){          // check if we can place at (row, col)
			board[row][col] = true;          // place the queen at (row, col)
			count += solve(board, row + 1);  // explore for the next row. The function will return 1 if all N queens get placed for current combination
			board[row][col] = false;         // backtrack - remove previously placed queen and try for different columns
		}                                
	return count;
}
};