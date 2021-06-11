/*


On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

Input: board = [[3,2,4],[1,5,0]]
Output: 14


Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].


*/




class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        vector<vector<int> > target{{1,2,3},{4,5,0}} ; 
        
      
        
        int moves=0;
        
        int n=board.size();
        int m=board[0].size();
        
        queue<pair<int,vector<vector<int>>>> q;
        
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        
        q.push({moves,board});
        
        map<vector<vector<int>>,bool> mp;
        
        while(!q.empty()) {
            
            vector<vector<int>> curNode=q.front().second;
            
            int mv=q.front().first;
            
            q.pop();
            
            
            if(curNode==target) {
                return mv;
            }
            
            if(mp[curNode]) {
                continue;
            }
            
            else {
                
                
                mp[curNode]=true;
                
                pair<int,int> zeroPos=findPos(curNode);
                int r=zeroPos.first, c=zeroPos.second;
                
                for(int i=0;i<4;i++) {
                    if((r+dr[i]>=0 and r+dr[i]<n) and (c+dc[i]>=0 and c+dc[i]<m)) {
                        swap(curNode[r][c],curNode[r+dr[i]][c+dc[i]]);
                        
                        if(mp[curNode]==false) {
                            q.push({mv+1,curNode});
                        }
                        
                        swap(curNode[r][c],curNode[r+dr[i]][c+dc[i]]);
                        
                    }
                }
                
            }
            
        }
        
        return -1;
        
    }
    
    
    pair<int,int> findPos(vector<vector<int>>& curNode) {
        
        for(int i=0;i<2;i++) {
            for(int j=0;j<3;j++) {
                if(curNode[i][j]==0) {
                    return {i,j};
                }
            }
        }
        
        return {-1,-1};
        
    }
    
};