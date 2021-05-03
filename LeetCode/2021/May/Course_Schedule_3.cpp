class Solution {
public:
    
    static bool cmp(vector<int> a,vector<int> b) {
            return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int n=courses.size();
        
        sort(courses.begin(),courses.end(),cmp);
        
        int time=0;
        
        priority_queue<int> pq;
        
        for(int i=0;i<n;i++) {
            if(time+courses[i][0]<=courses[i][1]) {
                time+=courses[i][0];
                pq.push(courses[i][0]);
            }
            
            else if(!pq.empty()&&pq.top()>courses[i][0]) {
                int t=pq.top();
                time-=t;
                pq.pop();
                pq.push(courses[i][0]);
                time+=courses[i][0];
            }
            
        }
        
        return pq.size();
        
    }
};