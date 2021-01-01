class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int numOfIntervals = intervals.size();
		if (numOfIntervals == 0)
			return {newInterval};

		vector<vector<int>> resultIntervals;
		int idx = 0;
		while (idx < numOfIntervals && newInterval[0] > intervals[idx][1]) {
			resultIntervals.push_back(intervals[idx++]); // Insert those that end before the new interval starts
		}

		resultIntervals.push_back(newInterval); // Insert the new interval
		int insertedIdx = resultIntervals.size() - 1;
        if (idx < numOfIntervals) // Take lower start time between the new and the next interval in order
		    resultIntervals[insertedIdx][0] = min(resultIntervals[insertedIdx][0], intervals[idx][0]);
        
        while (idx < numOfIntervals && intervals[idx][0] <= resultIntervals[insertedIdx][1]) { // Merge overlapping intervals
            resultIntervals[insertedIdx][1] = max(resultIntervals[insertedIdx][1], intervals[idx++][1]);
        }

        while (idx < numOfIntervals) { // Insert remaining intervals
            resultIntervals.push_back(intervals[idx++]);
        }

        return resultIntervals;
	}
};