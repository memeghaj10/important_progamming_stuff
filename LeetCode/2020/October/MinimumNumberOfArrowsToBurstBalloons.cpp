class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size()==0) {
            return 0;
        }
        
        vector<pair<int,int>> vp;
        
        for(int i=0;i<points.size();i++) {
            vp.push_back(make_pair(points[i][0],points[i][1]));
        }
        
        sort(vp.begin(),vp.end());

        int start=vp[0].first;
        int end=vp[0].second;
        
        int c=1;
        
        for(int i=1;i<vp.size();i++) {
            //cout<<start<<" "<<end<<endl;
            if(vp[i].first<=end&&vp[i].second>=end) {
                continue;
            }
            
            else if(start<=vp[i].first&&end>=vp[i].second) {
                end = vp[i].second;
                continue;
            }   
            
            else {
                c++;
                start=vp[i].first;
                end=vp[i].second;
            }
        }
        
        
        return c;
        
        
    }
};