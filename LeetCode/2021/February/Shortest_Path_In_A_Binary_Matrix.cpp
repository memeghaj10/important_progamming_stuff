class Solution {
public:
    vector<int> dx = {-1,-1,-1,0,1,1,1,0};
vector<int> dy = {-1,0,1,1,1,0,-1,-1};
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int ans = 0;
    queue<pair<int,int>> q;
    int R = grid.size();
    int C = grid[0].size();
    if(grid[0][0] == 0){
        q.push({0,0});
        grid[0][0] = 1;
    }
    while(!q.empty()){
        int size = q.size();
        ++ans;
        while(size--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == R - 1 && y == C - 1)
                return ans;
            for(int i = 0 ; i < 8 ; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < R && ny < C && !grid[nx][ny]){
                    grid[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return -1;
}
};