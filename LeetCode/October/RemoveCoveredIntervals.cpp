int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [] (const vector<int>& v1, const vector<int>& v2) { 
                 if(v1[0] != v2[0]) return v1[0] < v2[0];
                 else return v1[1] > v2[1];
        });
        
        int ans = intervals.size(), end = INT_MIN;
        
        for(int i = 0; i < intervals.size(); i++) {
			// If the current intervals end previously than the latest checkpoint
			// Then it's overlapping, so decrease answer.
            if(intervals[i][1] <= end) --ans; 
			
			// Otherwise, make this intervals finishing time the latest.
            else end = intervals[i][1];
        }
        
        return ans;
    }