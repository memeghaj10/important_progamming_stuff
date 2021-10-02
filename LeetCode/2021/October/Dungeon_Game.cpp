class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n=dungeon.size();
        int m=dungeon[0].size();
        
        dungeon[n-1][m-1]<=0?dungeon[n-1][m-1]=abs(dungeon[n-1][m-1])+1:dungeon[n-1][m-1]=1;
        
        for(int j=m-2;j>=0;j--) {
            if(dungeon[n-1][j]<dungeon[n-1][j+1]) {
                dungeon[n-1][j]=dungeon[n-1][j+1]-dungeon[n-1][j];
            }
            else {
                dungeon[n-1][j]=1;
            }
        }
        
        for(int i=n-2;i>=0;i--) {
            if(dungeon[i][m-1]<dungeon[i+1][m-1]) {
                dungeon[i][m-1]=dungeon[i+1][m-1]-dungeon[i][m-1];
            }
            else {
                dungeon[i][m-1]=1;
            }
        }
        
        int k=0;
        int p=0;
        int q=0;
        
        for(int i=n-2;i>=0;i--) {
            for(int j=m-2;j>=0;j--) {
                if(dungeon[i][j]<dungeon[i][j+1]) {
                    p=dungeon[i][j+1]-dungeon[i][j];
                }
                else {
                    p=1;
                }
                
                if(dungeon[i][j]<dungeon[i+1][j]) {
                    q=dungeon[i+1][j]-dungeon[i][j];
                }
                
                else {
                    q=1;
                }
                              
                dungeon[i][j]=min(p,q);
            }
                              }
                              
                return dungeon[0][0];
        
    }
};