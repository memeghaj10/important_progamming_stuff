class Solution {
private:
    struct Orange { int i, j, day; }; // custom struct to store position and day
    const int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // possible relative directional moves
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int today = 0;      // To keep track of current day
		int totalFresh = 0; // To keep track of any fresh oranges
        queue<Orange> rotten;
        
		// Store all the inital rotten oranges 
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[i].size();j++) {
                if (grid[i][j] == 2) {
                    rotten.push(Orange{i, j, 0});
                }
                else if (grid[i][j] == 1) {
                    totalFresh += 1; // count the no of fresh oranges
                }
            }
        }
        
        while (!rotten.empty()) {
            Orange &orange = rotten.front();
            int i = orange.i;
            int j = orange.j;
            
            if (orange.day > today) { 
			    // if we are processing oranges from next day, update our day
                today++;
            }
            
            for (int d=0;d<4;d++) { // scan adjacent cells in all four directions
                int x = i + directions[d][0];
                int y = j + directions[d][1];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[i].size() && grid[x][y] == 1) {
                    grid[x][y] = 2; // mark as rotten
                    rotten.push(Orange{x, y, today+1}); // update queue
                    totalFresh -= 1; // reduce fresh orange count
                }
            }
            
            rotten.pop(); // remove the processed orange from queue
        }
        
		// if there are no fresh orangs left (totalFresh == 0), return today else -1 
        return (totalFresh == 0)?today:-1;
    }
};