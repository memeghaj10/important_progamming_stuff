/*


There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.



*/


/*

Solution:-

We will simply form a directed graph from the courses schedule given.

Then check for cycle in a Directed Graph:-

Two methods:-

1. BFS(Kahn's Algo)
2. DFS.

*/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        
        vector<int> adj[n];
        
        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++) {
            for(auto x:adj[i]) {
                indegree[x]++;
            }
        }
        
        for(int i=0;i<n;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        
        int c=0;
        
        while(!q.empty()) {
            
            int node=q.front();
            q.pop();
            
            c++;
            
            for(auto x:adj[node]) {
                indegree[x]--;
                if(indegree[x]==0) {
                    q.push(x);
                }
            }
            
        }
        
        if(c==n) {
            return true;
        }
        
        return false;
        
    }
};