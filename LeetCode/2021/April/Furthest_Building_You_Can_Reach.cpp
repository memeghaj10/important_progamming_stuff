class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        
        multiset<int> ms;
        
        vector<int> pre(n);
        pre[0]=0;
        
        for(int i=1;i<n;i++) {
            if(heights[i]>heights[i-1]) {
                ms.insert(heights[i]-heights[i-1]);
            }
            if(ms.size()>ladders) {
               bricks-=*ms.begin();
                ms.erase(ms.begin());
                if(bricks<0) {
                    return i-1;
                }
            }
        }
    
        return n-1;
        
    }
};