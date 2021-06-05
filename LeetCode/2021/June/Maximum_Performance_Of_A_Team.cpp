class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
       long  int total=0;
        long int best=0;
        
        priority_queue<int> pq;
        
        vector<pair<int,int>> vp;
        
        for(int i=0;i<n;i++) {
            vp.push_back(make_pair(efficiency[i],speed[i]));
        }
        
        sort(vp.rbegin(),vp.rend());
        
        for(int i=0;i<n;i++) {
            
            int spd=vp[i].second;
            pq.push(-spd);
            if(pq.size()<=k) {
                total+=spd;
            }
            else {
                total+=spd;
                total+=pq.top();
                pq.pop();
            }
            best=max(best,total*vp[i].first);
        }
        
        return best%1000000007;
        
    }
};