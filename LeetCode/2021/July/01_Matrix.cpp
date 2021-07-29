#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
class Solution {
    void solve(vector<vector<int>>&arr,vector<vector<int>>&vec)
    {
        // fill the matrix vec;
        int n=arr.size(); int m=arr[0].size();
        queue<pair<int,int>>q; // for storing the coordinate.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0)
                {
                    vec[i][j]=0;   
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int,int>p=q.front(); q.pop();
            int row_val[4]={-1,1,0,0};
            int col_val[4]={0,0,-1,1};
            int i=p.first; int j=p.second;
            for(int k=0;k<4;k++)
            {
                int r=i + row_val[k];
                int c=j + col_val[k];

                if(r>=0 and r<n and c>=0 and c<m and vec[r][c]==INT_MAX)
                {
                    // we have to update and insert it into the queue
                    vec[r][c]=vec[i][j]+1;
                    q.push({r,c});
                }
            }
            
        }
        
         
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        fio;
        vector<vector<int>>vec;
        if(matrix.size()==0)
            return vec;
        int n=matrix.size(); int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=0;j<m;j++)
                temp.push_back(INT_MAX);
            vec.push_back(temp);
        }
        
        solve(matrix,vec);
        return vec;
    }
};