class Solution {
public:
    int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Counts the number of sides of the current cell that touches water cells (out of bound and in bound water cells)
    int sidesTouchingWater(vector<vector<int>> &grid, int x, int y){
        int sides = 0;
        for(auto dir: DIRECTIONS){
                int newX = x + dir[0], newY = y + dir[1];
            // If the current cell touches water out of bounds or a regular water cell, increment the number of sides
                if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] == 0) 
                    sides++;
        }
        return sides;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int res = 0;
        for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    // If the current cell is a land, count the number of sides that touch the water
                        if(grid[i][j] == 1){
                                res += sidesTouchingWater(grid, i, j);
                        }

                }
        }
        return res;
    }
};