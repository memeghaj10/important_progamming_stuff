//fully copied, not mine!!!

#define vi vector<int>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<vi,vector<vi>,greater<vi>>q;
        q.push({0,0,0});
        int m=h.size(),n=h[0].size();
        vi x={-1,0,1,0},y={0,-1,0,1};
        vector<vector<int>>dis(m+1,vector<int>(n+1,INT_MAX));
        dis[0][0]=0;
        while(!q.empty()){
            vi v=q.top(); q.pop();
            int d=v[0],r=v[1],c=v[2];
            if(r==m-1 && c==n-1)return d;
            for(int i=0;i<4;i++){
                int rr=x[i]+r,cc=y[i]+c;
                if(rr>=0 && rr<m && cc>=0 && cc<n){
                    int mx_dis=max(d,abs(h[rr][cc]-h[r][c]));
                    if(mx_dis<dis[rr][cc]){
                        dis[rr][cc]=mx_dis;
                        q.push({mx_dis,rr,cc});
                    }
                }
            }
        }
        return 0;
    }
};